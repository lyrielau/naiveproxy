// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_CERT_CERT_VERIFY_RESULT_H_
#define NET_CERT_CERT_VERIFY_RESULT_H_

#include <vector>

#include "base/memory/ref_counted.h"
#include "base/supports_user_data.h"
#include "net/base/net_export.h"
#include "net/cert/cert_status_flags.h"
#include "net/cert/ct_policy_status.h"
#include "net/cert/ocsp_verify_result.h"
#include "net/cert/signed_certificate_timestamp_and_status.h"
#include "net/cert/x509_cert_types.h"

namespace base {
class Value;
}

namespace ct {
enum class CTPolicyCompliance;
}  // namespace ct

namespace net {

class X509Certificate;

// The result of certificate verification.
//
// Additional debugging or purely informational data may be added through
// SupportsUserData, but such data must not be used for anything that changes
// how the results are interpreted or acted upon: any data that changes the
// meaning of the result must be added as a member in this class, not through
// SupportsUserData.
// Any Data added through SupportsUserData must implement Clone().
class NET_EXPORT CertVerifyResult : public base::SupportsUserData {
 public:
  CertVerifyResult();
  CertVerifyResult(const CertVerifyResult& other);
  ~CertVerifyResult() override;

  CertVerifyResult& operator=(const CertVerifyResult& other);

  void Reset();

  // Creates NetLog parameter to describe the CertVerifyResult. |net_error| is
  // a net error code to include in the params, if non-zero. It must not be
  // ERR_IO_PENDING, as that is not a true error.
  base::Value NetLogParams(int net_error) const;

  // The certificate chain that was constructed during verification.
  //
  // Note: Although |verified_cert| will match the originally supplied
  // certificate to be validated, the results of intermediate_buffers()
  // may be substantially different, both in order and in content, then the
  // originally supplied intermediates.
  //
  // In the event of validation failures, this may contain the originally
  // supplied certificate chain or a partially constructed path, depending on
  // the implementation.
  //
  // In the event of validation success, the trust anchor will be
  // |verified_cert->intermediate_buffers().back()| if
  // there was a certificate chain to the trust anchor, and will
  // be |verified_cert->cert_buffer()| if the certificate was
  // the trust anchor.
  scoped_refptr<X509Certificate> verified_cert;

  // Bitmask of CERT_STATUS_* from net/cert/cert_status_flags.h. Note that
  // these status flags apply to the certificate chain returned in
  // |verified_cert|, rather than the originally supplied certificate
  // chain.
  CertStatus cert_status;

  // Hash algorithms used by the certificate chain, excluding the trust
  // anchor.
  bool has_md2;
  bool has_md4;
  bool has_md5;
  bool has_sha1;
  bool has_sha1_leaf;

  // If the certificate was successfully verified then this contains the
  // hashes for all of the SubjectPublicKeyInfos of the chain (target,
  // intermediates, and trust anchor)
  //
  // The ordering of the hashes in this vector is unspecified. Both the SHA1
  // and SHA256 hash will be present for each certificate.
  HashValueVector public_key_hashes;

  // is_issued_by_known_root is true if we recognise the root CA as a standard
  // root.  If it isn't then it's probably the case that this certificate was
  // generated by a MITM proxy whose root has been installed locally. This is
  // meaningless if the certificate was not trusted.
  bool is_issued_by_known_root;

  // is_issued_by_additional_trust_anchor is true if the root CA used for this
  // verification came from the list of additional trust anchors.
  bool is_issued_by_additional_trust_anchor;

  // Verification of stapled OCSP response, if present.
  OCSPVerifyResult ocsp_result;

  // `scts` contains the result of verifying any provided or embedded SCTs for
  // this certificate against the set of known logs. Consumers should not simply
  // check this for the presence of a successfully verified SCT to determine CT
  // compliance. Instead look at `policy_compliance`.
  SignedCertificateTimestampAndStatusList scts;

  // The result of evaluating whether the certificate complies with the
  // Certificate Transparency policy.
  ct::CTPolicyCompliance policy_compliance;
};

}  // namespace net

#endif  // NET_CERT_CERT_VERIFY_RESULT_H_
