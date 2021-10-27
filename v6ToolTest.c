//
//  v6ToolTest.c
//  v6ToolTest
//
//  Created by Darrell Root on 10/17/21.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "v6tools.h"

int main(int argc, const char * argv[]) {

    {
        char *testDescription = "stripNewline";
        char testcase[] = "ABCD\n";
        printf("%s %s ",testDescription,testcase);
        stripNewline(testcase);
        if (0 == strcmp(testcase,"ABCD")) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "stripNewline";
        char testcase[] = "ABCD";
        printf("%s %s ",testDescription,testcase);
        stripNewline(testcase);
        if (0 == strcmp(testcase,"ABCD")) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    // NAZEER GREENE

    {
        char *testDescription = "stripNewline";
        char testcase[] = "";
        printf("%s %s ",testDescription,"EMPTY STRING (\"\")");
        stripNewline(testcase);
        if (0 == strcmp(testcase, "")) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "lowercase";
        char testcase[] = "ABCDef";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (0 == strcmp(testcase,"abcdef")) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    // NAZEER GREENE

    {
        char *testDescription = "lowercase";
        char testcase[] = "";
        printf("%s %s ",testDescription, "EMPTY STRING (\"\")");
        lowercase(testcase);
        if (0 == strcmp(testcase,"")) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }
    
    {
        char *testDescription = "validIPv6Characters";
        char testcase[] = "0123456789ABCDef:";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (validIPv6Characters(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }
    
    {
        char *testDescription = "validIPv6Characters";
        char testcase[] = "0123456789::ABCDefg:";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (!validIPv6Characters(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }
    
    {
        char *testDescription = "validIPv6Characters";
        // should pass due to 39 characters
        char testcase[] = "012345678901234567890123456789012345678";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (validIPv6Characters(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }


    {
        char *testDescription = "validIPv6Characters";
        // should fail due to 40 characters
        char testcase[] = "0123456789012345678901234567890123456789";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (!validIPv6Characters(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    // NAZEER GREENE

    {
        char *testDescription = "validIPv6Characters";
        char testcase[] = "";
        printf("%s %s ",testDescription, "EMPTY STRING (\"\")");
        lowercase(testcase);
        if (!validIPv6Characters(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }
    
    {
        char *testDescription = "validIPv6DoubleColons";
        char testcase[] = "::";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (numberDoubleColons(testcase) == 1) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "validIPv6DoubleColons";
        char testcase[] = ":::";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (numberDoubleColons(testcase) == 2) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "validIPv6DoubleColons";
        char testcase[] = "fe80::1234::1234";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (numberDoubleColons(testcase) == 2) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "validIPv6DoubleColons";
        char testcase[] = "fe80::1234:1234";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (numberDoubleColons(testcase) == 1) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    // NAZEER GREENE

    {
        char *testDescription = "validIPv6DoubleColons";
        char testcase[] = "";
        printf("%s %s ",testDescription, "EMPTY STRING (\"\")");
        lowercase(testcase);
        if (numberDoubleColons(testcase) == 0) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }
    
    {
        char *testDescription = "numberOfColons";
        char testcase[] = "fe80::1234::1234";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (numberOfColons(testcase) == 4) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }
    
    {
        char *testDescription = "numberOfColons";
        char testcase[] = "::";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (numberOfColons(testcase) == 2) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "numberOfColons";
        char testcase[] = "2001:0db8:01234:5678:9abc:def:0123:4567";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (numberOfColons(testcase) == 7) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }
    
    {
        char *testDescription = "numberOfColons";
        char testcase[] = "2001:0db8:01234:5678:9abc:def:0123:4567:89ab";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (numberOfColons(testcase) == 8) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }
    
    {
        // interesting case with "valid" IPv6 address with 8 colons
        // we will ignore case not rfc5952 compliant
        char *testDescription = "numberOfColons";
        char testcase[] = "2001:0db8:0123:5678:9abc:def:0123::";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (numberOfColons(testcase) == 8) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    // NAZEER GREENE

    {
        char *testDescription = "numberOfColons";
        char testcase[] = "";
        printf("%s %s ",testDescription, "EMPTY STRING (\"\")");
        lowercase(testcase);
        if (numberOfColons(testcase) == 0) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    //NAZEER GREENE
    {
        char *testDescription = "validHextets";
        char testcase[] = ":::::::1";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (validHextets(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "validHextets";
        char testcase[] = "2001:0db8:0123:4567:89ab:cdef:0123:4567";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (validHextets(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "validHextets";
        char testcase[] = "2001:0db8:01234:4567:89ab:cdef:0123:4567";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (!validHextets(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "validHextets";
        char testcase[] = "2001:0db8::4567:89ab:cdef:0123";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (validHextets(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }
    
    {
        char *testDescription = "validHextets";
        char testcase[] = "2:b8::456:89ab:cdef:0123";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (validHextets(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    // NAZEER GREENE
    // an empty hextet is still a valid hextet
    {
        char *testDescription = "validHextets";
        char testcase[] = "";
        printf("%s %s ",testDescription, "EMPTY STRING (\"\")");
        lowercase(testcase);
        if (validHextets(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "validIPv6Address";
        char testcase[] = "::";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (validIPv6Address(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "validIPv6Address";
        char testcase[] = ":::";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (!validIPv6Address(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "validIPv6Address";
        char testcase[] = "2001:0db8:0123:4567:89ab:cdef:0123:4567";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (validIPv6Address(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    //NAZEER GREENE
    {
        char *testDescription = "validIPv6Address";
        char testcase[] = "2001:0db8:0123:4567:89ab:cdef::";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (validIPv6Address(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }
    
    {
        char *testDescription = "validIPv6Address";
        char testcase[] = "ff02::1";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (validIPv6Address(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "validIPv6Address";
        char testcase[] = "gg::1";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (!validIPv6Address(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    {
        char *testDescription = "validIPv6Address";
        char testcase[] = "2001:0db8:0123:4567:89ab:cdef:0123:4567:89ab";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (!validIPv6Address(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }
    
    {
        char *testDescription = "validIPv6Address";
        char testcase[] = "2001:0db8:0123:4567:89ab:cdef:0123";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (!validIPv6Address(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    //NAZEER GREENE
    {
        char *testDescription = "validIPv6Address";
        char testcase[] = "2001:0db8:01234:5678:9abc:def:0123:4567";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (!validIPv6Address(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    // NAZEER GREENE
    {
        char *testDescription = "validIPv6Address";
        char testcase[] = "";
        printf("%s %s ",testDescription, "EMPTY STRING (\"\")");
        lowercase(testcase);
        if (!validIPv6Address(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }
    
    // Darrell
    {
        char *testDescription = "invalid 8 colons less than 39 char";
        char testcase[] = "2001:db8:123:567:9ab:def:123:567:9ab";
        printf("%s %s ",testDescription,testcase);
        lowercase(testcase);
        if (!validIPv6Address(testcase)) {
            printf("SUCCESS %s\n",testcase);
        } else {
            printf("FAILED %s\n",testcase);
        }
    }

    return 0;
}
