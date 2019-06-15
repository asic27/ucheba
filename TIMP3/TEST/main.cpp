#include <unittest++/UnitTest++.h>
#include <locale>
#include "/home/asic27/Timp/OOO_MOYA_OBORONA/modAlphaCipher.cpp"
#include "/home/asic27/Timp/OOO_MOYA_OBORONA/modAlphaCipher.h"
struct KeyB_fixture {
    modAlphaCipher * p;
    KeyB_fixture() {
        std::wstring s;
        std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
        s = codec.from_bytes("Б");
        p = new modAlphaCipher(s);
    }
    ~KeyB_fixture() {
        delete p;
    }
};
SUITE(KeyTest)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    TEST(ValidKey) {
        CHECK_EQUAL("БВГБВ",modAlphaCipher(codec.from_bytes("БВГ")).encrypt(codec.from_bytes("ААААА")));
    }
    TEST(LongKey) {
        CHECK_EQUAL("БВГДЕ",modAlphaCipher(codec.from_bytes("БВГДЕЖЗИК")).encrypt(codec.from_bytes("ААААА")));
    }
    TEST(LowCaseKey) {
        CHECK_EQUAL("БВГБВ",modAlphaCipher(codec.from_bytes("бвг")).encrypt(codec.from_bytes("ААААА")));
    }
    TEST(DigitsInKey) {
        CHECK_THROW(modAlphaCipher cp(codec.from_bytes("В1")),cipher_error);
    }
    TEST(PunctuationInKey) {
        CHECK_THROW(modAlphaCipher cp(codec.from_bytes("В,С")),cipher_error);
    }
    TEST(WhitespaceInKey) {
        CHECK_THROW(modAlphaCipher cp(codec.from_bytes("В С")),cipher_error);
    }
    TEST(EmptyKey) {
        CHECK_THROW(modAlphaCipher cp(codec.from_bytes("")),cipher_error);
    }
    TEST(WeakKey) {
        CHECK_THROW(modAlphaCipher cp(codec.from_bytes("ААА")),cipher_error);
    }
}
SUITE(EncryptTest)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("ТЫЁЩЭЁЪЖЮУЙНАДЛЙЦХСБОЧФИТЛЙЦВФМПЛЕБГЬРЁКШБЯЗБЛ",p->encrypt(codec.from_bytes("СЪЕШЬЕЩЁЭТИМЯГКИХФРАНЦУЗСКИХБУЛОКДАВЫПЕЙЧАЮЖАК")));
    }
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_EQUAL("ТЫЁЩЭЁЪЖЮУЙНАДЛЙЦХСБОЧФИТЛЙЦВФМПЛЕБГЬРЁКШБЯЗБЛ",p->encrypt(codec.from_bytes("съешьещёэтимягкихфранцузскихбулокдавыпейчаюжак")));
    }
    TEST_FIXTURE(KeyB_fixture, StringWithWhitspaceAndPunct) {
        CHECK_EQUAL("ТЫЁЩЭЁЪЖЮУЙНАДЛЙЦХСБОЧФИТЛЙЦВФМПЛЕБГЬРЁКШБЯЗБЛ",p->encrypt(codec.from_bytes("Съешь ещё эти мягких французских булок,да выпей чаю, жак")));
    }
    TEST_FIXTURE(KeyB_fixture, StringWithNumbers) {
        CHECK_EQUAL("ТЫЁЩЭЁЪЖЮУЙНАДЛЙЦХСБОЧФИТЛЙЦВФМПЛЕБГЬРЁКШБЯЗБЛ", p->encrypt(codec.from_bytes("1Съешь 2ещё 3эти 4мягких 5французских 6булок, 7да 8выпей 9чаю, жак")));
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->encrypt(codec.from_bytes("")),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
        CHECK_THROW(p->encrypt(codec.from_bytes("1234+8765=9999")),cipher_error);
    }
    TEST(MaxShiftKey) {
        CHECK_EQUAL("РЩДЧЫДШЕЬСЗЛЮВЙЗФУПЯМХТЖРЙЗФАТКНЙГЯБЪОДИЦЯЭЁЯЙ",modAlphaCipher(codec.from_bytes("Я")).encrypt(codec.from_bytes("СЪЕШЬЕЩЁЭТИМЯГКИХФРАНЦУЗСКИХБУЛОКДАВЫПЕЙЧАЮЖАК")));
    }
}
SUITE(DecryptText)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("СЪЕШЬЕЩЁЭТИМЯГКИХФРАНЦУЗСКИХБУЛОКДАВЫПЕЙЧАЮЖАК",p->decrypt(codec.from_bytes("ТЫЁЩЭЁЪЖЮУЙНАДЛЙЦХСБОЧФИТЛЙЦВФМПЛЕБГЬРЁКШБЯЗБЛ")));
    }
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_THROW(p->decrypt(codec.from_bytes("тыЁЩЭЁЪЖЮУЙНАДЛЙЦХСБОЧФИТЛЙЦВФМПЛЕБГЬРЁКШБЯЗБЛ")),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, WhitespaceString) {
        CHECK_THROW(p->decrypt(codec.from_bytes("ТЫ ЁЩЭЁЪЖЮУЙН АДЛЙЦХСБОЧФИТЛЙЦВФМ ПЛЕБГЬРЁКШБЯЗБЛ")),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, DigitsString) {
        CHECK_THROW(p->decrypt(codec.from_bytes("ТЫЁЩЭ2ЁЪЖЮУЙНАДЛЙЦ1ХСБОЧФИТЛЙЦВФМПЛЕБГЬ4РЁКШБЯЗБ5Л")),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, PunctString) {
        CHECK_THROW(p->decrypt(codec.from_bytes("ТЫЁЩ,ЭЁЪЖЮУЙНАДЛЙЦ,ХСБОЧФИТЛЙЦВФМПЛЕБГ,ЬРЁКШБЯЗБЛ")),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->decrypt(codec.from_bytes("")),cipher_error);
    }
    TEST(MaxShiftKey) {
        CHECK_EQUAL("СЪЕШЬЕЩЁЭТИМЯГКИХФРАНЦУЗСКИХБУЛОКДАВЫПЕЙЧАЮЖАК",
                    modAlphaCipher(codec.from_bytes("Я")).decrypt(codec.from_bytes("РЩДЧЫДШЕЬСЗЛЮВЙЗФУПЯМХТЖРЙЗФАТКНЙГЯБЪОДИЦЯЭЁЯЙ")));
    }
}
int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
