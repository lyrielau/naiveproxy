/********************************************************************************************
* SIDH: an efficient supersingular isogeny cryptography library
*
* Abstract: supersingular isogeny parameters and generation of functions for P503
*********************************************************************************************/

#include "utils.h"

// Parameters for isogeny system "SIKEp503"
const struct params_t p503 = {
    .prime = {
        U64_TO_WORDS(0xFFFFFFFFFFFFFFFF), U64_TO_WORDS(0xFFFFFFFFFFFFFFFF),
        U64_TO_WORDS(0xFFFFFFFFFFFFFFFF), U64_TO_WORDS(0xABFFFFFFFFFFFFFF),
        U64_TO_WORDS(0x13085BDA2211E7A0), U64_TO_WORDS(0x1B9BF6C87B7E7DAF),
        U64_TO_WORDS(0x6045C6BDDA77A4D0), U64_TO_WORDS(0x004066F541811E1E)
    },
    .prime_p1 = {
        U64_TO_WORDS(0x0000000000000000), U64_TO_WORDS(0x0000000000000000),
        U64_TO_WORDS(0x0000000000000000), U64_TO_WORDS(0xAC00000000000000),
        U64_TO_WORDS(0x13085BDA2211E7A0), U64_TO_WORDS(0x1B9BF6C87B7E7DAF),
        U64_TO_WORDS(0x6045C6BDDA77A4D0), U64_TO_WORDS(0x004066F541811E1E)
    },
    .prime_x2 = {
        U64_TO_WORDS(0xFFFFFFFFFFFFFFFE), U64_TO_WORDS(0xFFFFFFFFFFFFFFFF),
        U64_TO_WORDS(0xFFFFFFFFFFFFFFFF), U64_TO_WORDS(0x57FFFFFFFFFFFFFF),
        U64_TO_WORDS(0x2610B7B44423CF41), U64_TO_WORDS(0x3737ED90F6FCFB5E),
        U64_TO_WORDS(0xC08B8D7BB4EF49A0), U64_TO_WORDS(0x0080CDEA83023C3C)
    },
    .A_gen = {
        U64_TO_WORDS(0xE7EF4AA786D855AF), U64_TO_WORDS(0xED5758F03EB34D3B),
        U64_TO_WORDS(0x09AE172535A86AA9), U64_TO_WORDS(0x237B9CC07D622723),
        U64_TO_WORDS(0xE3A284CBA4E7932D), U64_TO_WORDS(0x27481D9176C5E63F),
        U64_TO_WORDS(0x6A323FF55C6E71BF), U64_TO_WORDS(0x002ECC31A6FB8773),   // XPA0
        U64_TO_WORDS(0x64D02E4E90A620B8), U64_TO_WORDS(0xDAB8128537D4B9F1),
        U64_TO_WORDS(0x4BADF77B8A228F98), U64_TO_WORDS(0x0F5DBDF9D1FB7D1B),
        U64_TO_WORDS(0xBEC4DB288E1A0DCC), U64_TO_WORDS(0xE76A8665E80675DB),
        U64_TO_WORDS(0x6D6F252E12929463), U64_TO_WORDS(0x003188BD1463FACC),   // XPA1
        U64_TO_WORDS(0xB79D41025DE85D56), U64_TO_WORDS(0x0B867DA9DF169686),
        U64_TO_WORDS(0x740E5368021C827D), U64_TO_WORDS(0x20615D72157BF25C),
        U64_TO_WORDS(0xFF1590013C9B9F5B), U64_TO_WORDS(0xC884DCADE8C16CEA),
        U64_TO_WORDS(0xEBD05E53BF724E01), U64_TO_WORDS(0x0032FEF8FDA5748C),   // XQA0
        U64_TO_WORDS(0x12E2E849AA0A8006), U64_TO_WORDS(0x41CF47008635A1E8),
        U64_TO_WORDS(0x9CD720A70798AED7), U64_TO_WORDS(0x42A820B42FCF04CF),
        U64_TO_WORDS(0x7BF9BAD32AAE88B1), U64_TO_WORDS(0xF619127A54090BBE),
        U64_TO_WORDS(0x1CB10D8F56408EAA), U64_TO_WORDS(0x001D6B54C3C0EDEB),   // XRA0
        U64_TO_WORDS(0x34DB54931CBAAC36), U64_TO_WORDS(0x420A18CB8DD5F0C4),
        U64_TO_WORDS(0x32008C1A48C0F44D), U64_TO_WORDS(0x3B3BA772B1CFD44D),
        U64_TO_WORDS(0xA74B058FDAF13515), U64_TO_WORDS(0x095FC9CA7EEC17B4),
        U64_TO_WORDS(0x448E829D28F120F8), U64_TO_WORDS(0x00261EC3ED16A489)    // XRA1
    },
    .B_gen = {
        U64_TO_WORDS(0x7EDE37F4FA0BC727), U64_TO_WORDS(0xF7F8EC5C8598941C),
        U64_TO_WORDS(0xD15519B516B5F5C8), U64_TO_WORDS(0xF6D5AC9B87A36282),
        U64_TO_WORDS(0x7B19F105B30E952E), U64_TO_WORDS(0x13BD8B2025B4EBEE),
        U64_TO_WORDS(0x7B96D27F4EC579A2), U64_TO_WORDS(0x00140850CAB7E5DE),   // XPB0
        U64_TO_WORDS(0x7764909DAE7B7B2D), U64_TO_WORDS(0x578ABB16284911AB),
        U64_TO_WORDS(0x76E2BFD146A6BF4D), U64_TO_WORDS(0x4824044B23AA02F0),
        U64_TO_WORDS(0x1105048912A321F3), U64_TO_WORDS(0xB8A2E482CF0F10C1),
        U64_TO_WORDS(0x42FF7D0BE2152085), U64_TO_WORDS(0x0018E599C5223352),   // XPB1
        U64_TO_WORDS(0x4256C520FB388820), U64_TO_WORDS(0x744FD7C3BAAF0A13),
        U64_TO_WORDS(0x4B6A2DDDB12CBCB8), U64_TO_WORDS(0xE46826E27F427DF8),
        U64_TO_WORDS(0xFE4A663CD505A61B), U64_TO_WORDS(0xD6B3A1BAF025C695),
        U64_TO_WORDS(0x7C3BB62B8FCC00BD), U64_TO_WORDS(0x003AFDDE4A35746C),   // XQB0
        U64_TO_WORDS(0x75601CD1E6C0DFCB), U64_TO_WORDS(0x1A9007239B58F93E),
        U64_TO_WORDS(0xC1F1BE80C62107AC), U64_TO_WORDS(0x7F513B898F29FF08),
        U64_TO_WORDS(0xEA0BEDFF43E1F7B2), U64_TO_WORDS(0x2C6D94018CBAE6D0),
        U64_TO_WORDS(0x3A430D31BCD84672), U64_TO_WORDS(0x000D26892ECCFE83),   // XRB0
        U64_TO_WORDS(0x1119D62AEA3007A1), U64_TO_WORDS(0xE3702AA4E04BAE1B),
        U64_TO_WORDS(0x9AB96F7D59F990E7), U64_TO_WORDS(0xF58440E8B43319C0),
        U64_TO_WORDS(0xAF8134BEE1489775), U64_TO_WORDS(0xE7F7774E905192AA),
        U64_TO_WORDS(0xF54AE09308E98039), U64_TO_WORDS(0x001EF7A041A86112)    // XRB1
    },
    .mont_R2 = {
        U64_TO_WORDS(0x5289A0CF641D011F), U64_TO_WORDS(0x9B88257189FED2B9),
        U64_TO_WORDS(0xA3B365D58DC8F17A), U64_TO_WORDS(0x5BC57AB6EFF168EC),
        U64_TO_WORDS(0x9E51998BD84D4423), U64_TO_WORDS(0xBF8999CBAC3B5695),
        U64_TO_WORDS(0x46E9127BCE14CDB6), U64_TO_WORDS(0x003F6CFCE8B81771)
    },
    .mont_one = {
        U64_TO_WORDS(0x00000000000003F9), U64_TO_WORDS(0x0000000000000000),
        U64_TO_WORDS(0x0000000000000000), U64_TO_WORDS(0xB400000000000000),
        U64_TO_WORDS(0x63CB1A6EA6DED2B4), U64_TO_WORDS(0x51689D8D667EB37D),
        U64_TO_WORDS(0x8ACD77C71AB24142), U64_TO_WORDS(0x0026FBAEC60F5953)
    },
    .A_strat = {
        61, 32, 16, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1,
        4, 2, 1, 1, 2, 1, 1, 16, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1,
        1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 29, 16, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1,
        1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 13, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2,
        1, 1, 2, 1, 1, 5, 4, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1
    },
    .B_strat = {
        71, 38, 21, 13, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 5, 4, 2, 1, 1, 2, 1,
        1, 2, 1, 1, 1, 9, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1, 1, 17, 9,
        5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 1, 2, 1,
        1, 4, 2, 1, 1, 2, 1, 1, 33, 17, 9, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 1,
        2, 1, 1, 8, 4, 2, 1, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 16, 8, 4, 2, 1, 1, 1, 2,
        1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1
    }
};