// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/proxy_resolution/win/winhttp_api_wrapper.h"

#include <utility>

#include "base/check_op.h"
#include "base/macros.h"
#include "base/strings/string16.h"
#include "net/proxy_resolution/win/winhttp_proxy_resolver_functions.h"

namespace net {

// TODO(https://crbug.com/1032820): Capture telemetry for WinHttp APIs if
// interesting.

ScopedIEConfig::ScopedIEConfig() = default;
ScopedIEConfig::~ScopedIEConfig() {
  if (ie_config.lpszAutoConfigUrl)
    GlobalFree(ie_config.lpszAutoConfigUrl);
  if (ie_config.lpszProxy)
    GlobalFree(ie_config.lpszProxy);
  if (ie_config.lpszProxyBypass)
    GlobalFree(ie_config.lpszProxyBypass);
}

WinHttpAPIWrapper::WinHttpAPIWrapper() = default;
WinHttpAPIWrapper::~WinHttpAPIWrapper() {
  if (session_handle_)
    ignore_result(CallWinHttpSetStatusCallback(nullptr));
  CloseSessionHandle();
}

bool WinHttpAPIWrapper::CallWinHttpOpen() {
  DCHECK_EQ(nullptr, session_handle_);
  session_handle_ =
      WinHttpOpen(nullptr, WINHTTP_ACCESS_TYPE_NO_PROXY, WINHTTP_NO_PROXY_NAME,
                  WINHTTP_NO_PROXY_BYPASS, WINHTTP_FLAG_ASYNC);
  return (session_handle_ != nullptr);
}

bool WinHttpAPIWrapper::CallWinHttpSetTimeouts(int resolve_timeout,
                                               int connect_timeout,
                                               int send_timeout,
                                               int receive_timeout) {
  DCHECK_NE(nullptr, session_handle_);
  return (!!WinHttpSetTimeouts(session_handle_, resolve_timeout,
                               connect_timeout, send_timeout, receive_timeout));
}

bool WinHttpAPIWrapper::CallWinHttpSetStatusCallback(
    WINHTTP_STATUS_CALLBACK internet_callback) {
  DCHECK_NE(nullptr, session_handle_);
  const WINHTTP_STATUS_CALLBACK winhttp_status_callback =
      WinHttpSetStatusCallback(
          session_handle_, internet_callback,
          WINHTTP_CALLBACK_FLAG_REQUEST_ERROR |
              WINHTTP_CALLBACK_FLAG_GETPROXYFORURL_COMPLETE,
          0);
  return (winhttp_status_callback != WINHTTP_INVALID_STATUS_CALLBACK);
}

bool WinHttpAPIWrapper::CallWinHttpGetIEProxyConfigForCurrentUser(
    WINHTTP_CURRENT_USER_IE_PROXY_CONFIG* ie_proxy_config) {
  return !!WinHttpGetIEProxyConfigForCurrentUser(ie_proxy_config);
}

bool WinHttpAPIWrapper::CallWinHttpCreateProxyResolver(
    HINTERNET* out_resolver_handle) {
  DCHECK_NE(nullptr, session_handle_);
  const DWORD result =
      WinHttpProxyResolverFunctions::GetInstance().create_proxy_resolver(
          session_handle_, out_resolver_handle);
  return (result == ERROR_SUCCESS);
}

bool WinHttpAPIWrapper::CallWinHttpGetProxyForUrlEx(
    HINTERNET resolver_handle,
    const std::string& url,
    WINHTTP_AUTOPROXY_OPTIONS* autoproxy_options,
    DWORD_PTR context) {
  const base::string16 wide_url(url.begin(), url.end());
  // TODO(https://crbug.com/1032820): Upgrade to WinHttpGetProxyForUrlEx2()
  // if there is a clear reason to do so.
  const DWORD result =
      WinHttpProxyResolverFunctions::GetInstance().get_proxy_for_url_ex(
          resolver_handle, wide_url.data(), autoproxy_options, context);
  return (result == ERROR_IO_PENDING);
}

bool WinHttpAPIWrapper::CallWinHttpGetProxyResult(
    HINTERNET resolver_handle,
    WINHTTP_PROXY_RESULT* proxy_result) {
  const DWORD result =
      WinHttpProxyResolverFunctions::GetInstance().get_proxy_result(
          resolver_handle, proxy_result);
  return (result == ERROR_SUCCESS);
}

VOID WinHttpAPIWrapper::CallWinHttpFreeProxyResult(
    WINHTTP_PROXY_RESULT* proxy_result) {
  WinHttpProxyResolverFunctions::GetInstance().free_proxy_result(proxy_result);
}

void WinHttpAPIWrapper::CallWinHttpCloseHandle(HINTERNET internet_handle) {
  WinHttpCloseHandle(internet_handle);
}

void WinHttpAPIWrapper::CloseSessionHandle() {
  if (session_handle_) {
    CallWinHttpCloseHandle(session_handle_);
    session_handle_ = nullptr;
  }
}

}  // namespace net
