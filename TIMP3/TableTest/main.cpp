#include <unittest++/UnitTest++.h>
#include "/home/asic27/Timp/Perestanovka/Perestanovka.cpp"
#include "/home/asic27/Timp/Perestanovka/Perestanovka.h"
struct KeyThree_fixture {
    Perestanovka * p;
    KeyThree_fixture() {
        p = new Perestanovka(3);
    }
    ~KeyThree_fixture() {
        delete p;
    }
};
SUITE(KeyTest){
    TEST(ValidKey){
        CHECK_EQUAL("ANWLREWRBVEOD",Perestanovka(3).shifr("BRAVENEWWORLD"));
    }
    TEST(BadKey){
        CHECK_THROW(Perestanovka(1).shifr("BRAVENEWWORLD"),cipher_error);
    }
}
SUITE(ShifrTest){
    TEST_FIXTURE(KeyThree_fixture,UpCaseOT){
        CHECK_EQUAL("ANWLREWRBVEOD",p->shifr("BRAVENEWWORLD"));
    }
    TEST_FIXTURE(KeyThree_fixture,LowCaseOT){
        CHECK_EQUAL("ANWLREWRBVEOD",p->shifr("bravenewworld"));
    }
    TEST_FIXTURE(KeyThree_fixture,OTWithSpace){
        CHECK_EQUAL("ANWLREWRBVEOD",p->shifr("BRAVE NEW WORLD"));
    }
    TEST_FIXTURE(KeyThree_fixture,OTWhithDigit){
        CHECK_EQUAL("ANWLREWRBVEOD",p->shifr("2BRAVENEWWORLD1"));
    }
    TEST_FIXTURE(KeyThree_fixture,OTOnlyDigit){
        CHECK_THROW(p->shifr("1234"),cipher_error);
    }
    TEST_FIXTURE(KeyThree_fixture,OTPunct){
       CHECK_EQUAL("ANWLREWRBVEOD",p->shifr("BRAVENEWWORLD!!!"));
    }
    TEST_FIXTURE(KeyThree_fixture,EmptyCT){
        CHECK_THROW(p->shifr(""),cipher_error);
    }
    TEST_FIXTURE(KeyThree_fixture,ShortOT){
        CHECK_THROW(p->shifr("BRA"),cipher_error);
    }
}
SUITE(RashifrTest){
    TEST_FIXTURE(KeyThree_fixture,UpCaseCT){
        CHECK_EQUAL("BRAVENEWWORLD",p->rashifr("ANWLREWRBVEOD"));
    }
    TEST_FIXTURE(KeyThree_fixture,LowCaseCT){
        CHECK_THROW(p->rashifr("anwLREWRBVEOD"),cipher_error);
    }
    TEST_FIXTURE(KeyThree_fixture,CTwithSpace){
        CHECK_THROW(p->rashifr("ANWLR EWRBV EOD"),cipher_error);
    }
    TEST_FIXTURE(KeyThree_fixture,CTwithdigits){
        CHECK_THROW(p->rashifr("1ANWLREWRBVEOD2"),cipher_error);
    }
    TEST_FIXTURE(KeyThree_fixture,EmptyCT){
        CHECK_THROW(p->rashifr(""),cipher_error);
    }
    TEST_FIXTURE(KeyThree_fixture,CTonlydigits){
        CHECK_THROW(p->rashifr("1234"),cipher_error);
    }
    TEST_FIXTURE(KeyThree_fixture,CTwithPunct){
        CHECK_THROW(p->rashifr("ANWLREWRBVEOD!!"),cipher_error);
    }
    TEST_FIXTURE(KeyThree_fixture,ShortCT){
        CHECK_THROW(p->rashifr("ANW"),cipher_error);
    }
    
}
int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
