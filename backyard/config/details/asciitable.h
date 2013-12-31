/*
Ascii Table
===========

Decimal   Octal   Hex    Binary       Value
-------   -----   ----   --------     -----
000      000     0x00   00000000      NUL    (Null char.)
001      001     0x01   00000001      SOH    (Start of Header)
002      002     0x02   00000010      STX    (Start of Text)
003      003     0x03   00000011      ETX    (End of Text)
004      004     0x04   00000100      EOT    (End of Transmission)
005      005     0x05   00000101      ENQ    (Enquiry)
006      006     0x06   00000110      ACK    (Acknowledgment)
007      007     0x07   00000111      BEL    (Bell)
008      010     0x08   00001000       BS    (Backspace)
009      011     0x09   00001001       HT    (Horizontal Tab)
010      012     0x0A   00001010       LF    (Line Feed)
011      013     0x0B   00001011       VT    (Vertical Tab)
012      014     0x0C   00001100       FF    (Form Feed)
013      015     0x0D   00001101       CR    (Carriage Return)
014      016     0x0E   00001110       SO    (Shift Out)
015      017     0x0F   00001111       SI    (Shift In)
016      020     0x10   00010000      DLE    (Data Link Escape)
017      021     0x11   00010001      DC1    (XON) (Device Control 1)
018      022     0x12   00010010      DC2          (Device Control 2)
019      023     0x13   00010011      DC3    (XOFF)(Device Control 3)
020      024     0x14   00010100      DC4          (Device Control 4)
021      025     0x15   00010101      NAK    (Negative Acknowledgement)
022      026     0x16   00010110      SYN    (Synchronous Idle)
023      027     0x17   00010111      ETB    (End of Trans. Block)
024      030     0x18   00011000      CAN    (Cancel)
025      031     0x19   00011001       EM    (End of Medium)
026      032     0x1A   00011010      SUB    (Substitute)
027      033     0x1B   00011011      ESC    (Escape)
028      034     0x1C   00011100       FS    (File Separator)
029      035     0x1D   00011101       GS    (Group Separator)
030      036     0x1E   00011110       RS    (Request to Send)(Record Separator)
031      037     0x1F   00011111       US    (Unit Separator)
032      040     0x20   00100000       SP    (Space)
033      041     0x21   00100001        !    (exclamation mark)
034      042     0x22   00100010        "    (double quote)
035      043     0x23   00100011        #    (number sign)
036      044     0x24   00100100        $    (dollar sign)
037      045     0x25   00100101        %    (percent)
038      046     0x26   00100110        &    (ampersand)
039      047     0x27   00100111        '    (single quote)
040      050     0x28   00101000        (    (left/opening parenthesis)
041      051     0x29   00101001        )    (right/closing parenthesis)
042      052     0x2A   00101010        *    (asterisk)
043      053     0x2B   00101011        +    (plus)
044      054     0x2C   00101100        ,    (comma)
045      055     0x2D   00101101        -    (minus or dash)
046      056     0x2E   00101110        .    (dot)
047      057     0x2F   00101111        /    (forward slash)
048      060     0x30   00110000        0
049      061     0x31   00110001        1
050      062     0x32   00110010        2
051      063     0x33   00110011        3
052      064     0x34   00110100        4
053      065     0x35   00110101        5
054      066     0x36   00110110        6
055      067     0x37   00110111        7
056      070     0x38   00111000        8
057      071     0x39   00111001        9
058      072     0x3A   00111010        :    (colon)
059      073     0x3B   00111011        ;    (semi-colon)
060      074     0x3C   00111100        <    (less than)
061      075     0x3D   00111101        =    (equal sign)
062      076     0x3E   00111110        >    (greater than)
063      077     0x3F   00111111        ?    (question mark)
064      100     0x40   01000000        @    (AT symbol)
065      101     0x41   01000001        A
066      102     0x42   01000010        B
067      103     0x43   01000011        C
068      104     0x44   01000100        D
069      105     0x45   01000101        E
070      106     0x46   01000110        F
071      107     0x47   01000111        G
072      110     0x48   01001000        H
073      111     0x49   01001001        I
074      112     0x4A   01001010        J
075      113     0x4B   01001011        K
076      114     0x4C   01001100        L
077      115     0x4D   01001101        M
078      116     0x4E   01001110        N
079      117     0x4F   01001111        O
080      120     0x50   01010000        P
081      121     0x51   01010001        Q
082      122     0x52   01010010        R
083      123     0x53   01010011        S
084      124     0x54   01010100        T
085      125     0x55   01010101        U
086      126     0x56   01010110        V
087      127     0x57   01010111        W
088      130     0x58   01011000        X
089      131     0x59   01011001        Y
090      132     0x5A   01011010        Z
091      133     0x5B   01011011        [    (left/opening bracket)
092      134     0x5C   01011100        \    (back slash)
093      135     0x5D   01011101        ]    (right/closing bracket)
094      136     0x5E   01011110        ^    (caret/cirumflex)
095      137     0x5F   01011111        _    (underscore)
096      140     0x60   01100000        `
097      141     0x61   01100001        a
098      142     0x62   01100010        b
099      143     0x63   01100011        c
100      144     0x64   01100100        d
101      145     0x65   01100101        e
102      146     0x66   01100110        f
103      147     0x67   01100111        g
104      150     0x68   01101000        h
105      151     0x69   01101001        i
106      152     0x6A   01101010        j
107      153     0x6B   01101011        k
108      154     0x6C   01101100        l
109      155     0x6D   01101101        m
110      156     0x6E   01101110        n
111      157     0x6F   01101111        o
112      160     0x70   01110000        p
113      161     0x71   01110001        q
114      162     0x72   01110010        r
115      163     0x73   01110011        s
116      164     0x74   01110100        t
117      165     0x75   01110101        u
118      166     0x76   01110110        v
119      167     0x77   01110111        w
120      170     0x78   01111000        x
121      171     0x79   01111001        y
122      172     0x7A   01111010        z
123      173     0x7B   01111011        {    (left/opening brace)
124      174     0x7C   01111100        |    (vertical bar)
125      175     0x7D   01111101        }    (right/closing brace)
126      176     0x7E   01111110        ~    (tilde)
127      177     0x7F   01111111      DEL    (delete)

*/

#ifndef GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_ASCII_H
#define GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_ASCII_H
#pragma once

#include "basictypes.h"

namespace SolidMCP { namespace BedRock {

    //typedef UInt8 CharType;
    template<typename T>
    class Ascii
    {
        public:
            typedef T CharType;

        public:

            static const CharType  NUL;
            static const CharType  SOH;
            static const CharType  STX;
            static const CharType  ETX;
            static const CharType  EOT;
            static const CharType  ENQ;
            static const CharType  ACK;
            static const CharType  BEL;
            static const CharType  BS;
            static const CharType  HT;
            static const CharType  LF;
            static const CharType  VT;
            static const CharType  FF;
            static const CharType  CR;
            static const CharType  SO;
            static const CharType  SI;
            static const CharType  DLE;
            static const CharType  DC1;
            static const CharType  DC2;
            static const CharType  DC3;
            static const CharType  DC4;
            static const CharType  NAK;
            static const CharType  SYN;
            static const CharType  ETB;
            static const CharType  CAN;
            static const CharType  EM;
            static const CharType  SUB;
            static const CharType  ESC;
            static const CharType  FS;
            static const CharType  GS;
            static const CharType  RS;
            static const CharType  US;
            static const CharType  SPACE;

            static const CharType  EXCLAMATION_MARK;
            static const CharType  DOUBLE_QUOTE;
            static const CharType  NUMBER_SIGN;
            static const CharType  DOLLAR_SIGN;
            static const CharType  PERCENT;
            static const CharType  AMPERSAND;
            static const CharType  SINGLE_QUOTE;
            static const CharType  OPENING_PARENTHESIS;
            static const CharType  CLOSING_PARENTHESIS;
            static const CharType  ASTERISK;
            static const CharType  PLUS;
            static const CharType  COMMA;
            static const CharType  DASH;
            static const CharType  DOT;
            static const CharType  FORWARD_SLASH;

            static const CharType  NUM0;
            static const CharType  NUM1;
            static const CharType  NUM2;
            static const CharType  NUM3;
            static const CharType  NUM4;
            static const CharType  NUM5;
            static const CharType  NUM6;
            static const CharType  NUM7;
            static const CharType  NUM8;
            static const CharType  NUM9;

            static const CharType  COLON;
            static const CharType  SEMI_COLON;
            static const CharType  LESS_THAN;
            static const CharType  EQUAL_SIGN;
            static const CharType  GREATER_THAN;
            static const CharType  QUESTION_MARK;
            static const CharType  AT_SYMBOL;

            static const CharType  A;
            static const CharType  B;
            static const CharType  C;
            static const CharType  D;
            static const CharType  E;
            static const CharType  F;
            static const CharType  G;
            static const CharType  H;
            static const CharType  I;
            static const CharType  J;
            static const CharType  K;
            static const CharType  L;
            static const CharType  M;
            static const CharType  N;
            static const CharType  O;
            static const CharType  P;
            static const CharType  Q;
            static const CharType  R;
            static const CharType  S;
            static const CharType  T;
            static const CharType  U;
            static const CharType  V;
            static const CharType  W;
            static const CharType  X;
            static const CharType  Y;
            static const CharType  Z;

            static const CharType  OPENING_BRACKET;
            static const CharType  BACK_SLASH;
            static const CharType  CLOSING_BRACKET;
            static const CharType  CIRUMFLEX;
            static const CharType  UNDERSCORE;
            static const CharType  GRAVE;

            static const CharType  a;
            static const CharType  b;
            static const CharType  c;
            static const CharType  d;
            static const CharType  e;
            static const CharType  f;
            static const CharType  g;
            static const CharType  h;
            static const CharType  i;
            static const CharType  j;
            static const CharType  k;
            static const CharType  l;
            static const CharType  m;
            static const CharType  n;
            static const CharType  o;
            static const CharType  p;
            static const CharType  q;
            static const CharType  r;
            static const CharType  s;
            static const CharType  t;
            static const CharType  u;
            static const CharType  v;
            static const CharType  w;
            static const CharType  x;
            static const CharType  y;
            static const CharType  z;

            static const CharType  OPENING_BRACE;
            static const CharType  VERTICAL_BAR;
            static const CharType  CLOSING_BRACE;
            static const CharType  TILDE;
            static const CharType  DEL;
        };



        template<typename T> const T Ascii<T>::NUL                  =  0x00;    //  Null

        template<typename T> const T Ascii<T>::SOH                  =  0x01;    //  Start of Heading
        template<typename T> const T Ascii<T>::STX                  =  0x02;    //  Start of Text
        template<typename T> const T Ascii<T>::ETX                  =  0x03;    //  End of Text
        template<typename T> const T Ascii<T>::EOT                  =  0x04;    //  End of Transmission
        template<typename T> const T Ascii<T>::ENQ                  =  0x05;    //  Enquiry
        template<typename T> const T Ascii<T>::ACK                  =  0x06;    //  Positive Acknowledgement
        template<typename T> const T Ascii<T>::BEL                  =  0x07;    //  Bell
        template<typename T> const T Ascii<T>::BS                   =  0x08;    //  Back Space      (\b)
        template<typename T> const T Ascii<T>::HT                   =  0x09;    //  Horizontal Tab  (\t)
        template<typename T> const T Ascii<T>::LF                   =  0x0A;    //  Line Feed       (\n)
        template<typename T> const T Ascii<T>::VT                   =  0x0B;    //  Vertical Tab
        template<typename T> const T Ascii<T>::FF                   =  0x0C;    //  Form Feed       (\f)
        template<typename T> const T Ascii<T>::CR                   =  0x0D;    //  Carriage Return (\r)
        template<typename T> const T Ascii<T>::SO                   =  0x0E;    //  Shift Out
        template<typename T> const T Ascii<T>::SI                   =  0x0F;    //  Shift In
        template<typename T> const T Ascii<T>::DLE                  =  0x10;    //  Data Link Escape
        template<typename T> const T Ascii<T>::DC1                  =  0x11;    //  Device Control 1
        template<typename T> const T Ascii<T>::DC2                  =  0x12;    //  Device Control 2
        template<typename T> const T Ascii<T>::DC3                  =  0x13;    //  Device Control 3
        template<typename T> const T Ascii<T>::DC4                  =  0x14;    //  Device Control 4
        template<typename T> const T Ascii<T>::NAK                  =  0x15;    //  Negative Acknowledgement
        template<typename T> const T Ascii<T>::SYN                  =  0x16;    //  Synchronous Idle
        template<typename T> const T Ascii<T>::ETB                  =  0x17;    //  End of Trans. Block
        template<typename T> const T Ascii<T>::CAN                  =  0x18;    //  Cancel
        template<typename T> const T Ascii<T>::EM                   =  0x19;    //  End of Medium
        template<typename T> const T Ascii<T>::SUB                  =  0x1A;    //  Substitute
        template<typename T> const T Ascii<T>::ESC                  =  0x1B;    //  Escape
        template<typename T> const T Ascii<T>::FS                   =  0x1C;    //  File Separator
        template<typename T> const T Ascii<T>::GS                   =  0x1D;    //  Group Separator
        template<typename T> const T Ascii<T>::RS                   =  0x1E;    //  Record Separator
        template<typename T> const T Ascii<T>::US                   =  0x1F;    //  Unit Separator

        template<typename T> const T Ascii<T>::SPACE                =  0x20;    //  Space

        template<typename T> const T Ascii<T>::EXCLAMATION_MARK     =  0x21;    //  !    (exclamation mark)
        template<typename T> const T Ascii<T>::DOUBLE_QUOTE         =  0x22;    //  "    (double quote)
        template<typename T> const T Ascii<T>::NUMBER_SIGN          =  0x23;    //  #    (numbersign)
        template<typename T> const T Ascii<T>::DOLLAR_SIGN          =  0x24;    //  $    (dollarsign)
        template<typename T> const T Ascii<T>::PERCENT              =  0x25;    //  %    (percent)
        template<typename T> const T Ascii<T>::AMPERSAND            =  0x26;    //  &    (ampersand)
        template<typename T> const T Ascii<T>::SINGLE_QUOTE         =  0x27;    //  '    (singlequote)
        template<typename T> const T Ascii<T>::OPENING_PARENTHESIS  =  0x28;    //  (    (left/opening parenthesis)
        template<typename T> const T Ascii<T>::CLOSING_PARENTHESIS  =  0x29;    //  )    (right/closing parenthesis)
        template<typename T> const T Ascii<T>::ASTERISK             =  0x2A;    //  *    (asterisk)
        template<typename T> const T Ascii<T>::PLUS                 =  0x2B;    //  +    (plus)
        template<typename T> const T Ascii<T>::COMMA                =  0x2C;    //  ,    (comma)
        template<typename T> const T Ascii<T>::DASH                 =  0x2D;    //  -    (minus or dash)
        template<typename T> const T Ascii<T>::DOT                  =  0x2E;    //  .    (dot)
        template<typename T> const T Ascii<T>::FORWARD_SLASH        =  0x2F;    //  /    (forward slash)

        template<typename T> const T Ascii<T>::NUM0                 =  0x30;    // Numbers
        template<typename T> const T Ascii<T>::NUM1                 =  0x31;
        template<typename T> const T Ascii<T>::NUM2                 =  0x32;
        template<typename T> const T Ascii<T>::NUM3                 =  0x33;
        template<typename T> const T Ascii<T>::NUM4                 =  0x34;
        template<typename T> const T Ascii<T>::NUM5                 =  0x35;
        template<typename T> const T Ascii<T>::NUM6                 =  0x36;
        template<typename T> const T Ascii<T>::NUM7                 =  0x37;
        template<typename T> const T Ascii<T>::NUM8                 =  0x38;
        template<typename T> const T Ascii<T>::NUM9                 =  0x39;

        template<typename T> const T Ascii<T>::COLON                =  0x3A;    //  :    (colon)
        template<typename T> const T Ascii<T>::SEMI_COLON           =  0x3B;    //  ;    (semi-colon)
        template<typename T> const T Ascii<T>::LESS_THAN            =  0x3C;    //  <    (less than)
        template<typename T> const T Ascii<T>::EQUAL_SIGN           =  0x3D;    //  =    (equal sign)
        template<typename T> const T Ascii<T>::GREATER_THAN         =  0x3E;    //  >    (greater than)
        template<typename T> const T Ascii<T>::QUESTION_MARK        =  0x3F;    //  ?    (question mark)
        template<typename T> const T Ascii<T>::AT_SYMBOL            =  0x40;    //  @    (AT symbol)

        template<typename T> const T Ascii<T>::A                    =  0x41;
        template<typename T> const T Ascii<T>::B                    =  0x42;
        template<typename T> const T Ascii<T>::C                    =  0x43;
        template<typename T> const T Ascii<T>::D                    =  0x44;
        template<typename T> const T Ascii<T>::E                    =  0x45;
        template<typename T> const T Ascii<T>::F                    =  0x46;
        template<typename T> const T Ascii<T>::G                    =  0x47;
        template<typename T> const T Ascii<T>::H                    =  0x48;
        template<typename T> const T Ascii<T>::I                    =  0x49;
        template<typename T> const T Ascii<T>::J                    =  0x4A;
        template<typename T> const T Ascii<T>::K                    =  0x4B;
        template<typename T> const T Ascii<T>::L                    =  0x4C;
        template<typename T> const T Ascii<T>::M                    =  0x4D;
        template<typename T> const T Ascii<T>::N                    =  0x4E;
        template<typename T> const T Ascii<T>::O                    =  0x4F;
        template<typename T> const T Ascii<T>::P                    =  0x50;
        template<typename T> const T Ascii<T>::Q                    =  0x51;
        template<typename T> const T Ascii<T>::R                    =  0x52;
        template<typename T> const T Ascii<T>::S                    =  0x53;
        template<typename T> const T Ascii<T>::T                    =  0x54;
        template<typename T> const T Ascii<T>::U                    =  0x55;
        template<typename T> const T Ascii<T>::V                    =  0x56;
        template<typename T> const T Ascii<T>::W                    =  0x57;
        template<typename T> const T Ascii<T>::X                    =  0x58;
        template<typename T> const T Ascii<T>::Y                    =  0x59;
        template<typename T> const T Ascii<T>::Z                    =  0x5A;

        template<typename T> const T Ascii<T>::OPENING_BRACKET      =  0x5B;    //  [    (left/opening bracket)
        template<typename T> const T Ascii<T>::BACK_SLASH           =  0x5C;    //  \    (back slash)
        template<typename T> const T Ascii<T>::CLOSING_BRACKET      =  0x5D;    //  ]    (right/closing bracket)
        template<typename T> const T Ascii<T>::CIRUMFLEX            =  0x5E;    //  ^    (caret/cirumflex)
        template<typename T> const T Ascii<T>::UNDERSCORE           =  0x5F;    //  _    (underscore)
        template<typename T> const T Ascii<T>::GRAVE                =  0x60;    //  `    (Grave)

        template<typename T> const T Ascii<T>::a                    =  0x61;    // Lower Case.
        template<typename T> const T Ascii<T>::b                    =  0x62;
        template<typename T> const T Ascii<T>::c                    =  0x63;
        template<typename T> const T Ascii<T>::d                    =  0x64;
        template<typename T> const T Ascii<T>::e                    =  0x65;
        template<typename T> const T Ascii<T>::f                    =  0x66;
        template<typename T> const T Ascii<T>::g                    =  0x67;
        template<typename T> const T Ascii<T>::h                    =  0x68;
        template<typename T> const T Ascii<T>::i                    =  0x69;
        template<typename T> const T Ascii<T>::j                    =  0x6A;
        template<typename T> const T Ascii<T>::k                    =  0x6B;
        template<typename T> const T Ascii<T>::l                    =  0x6C;
        template<typename T> const T Ascii<T>::m                    =  0x6D;
        template<typename T> const T Ascii<T>::n                    =  0x6E;
        template<typename T> const T Ascii<T>::o                    =  0x6F;
        template<typename T> const T Ascii<T>::p                    =  0x70;
        template<typename T> const T Ascii<T>::q                    =  0x71;
        template<typename T> const T Ascii<T>::r                    =  0x72;
        template<typename T> const T Ascii<T>::s                    =  0x73;
        template<typename T> const T Ascii<T>::t                    =  0x74;
        template<typename T> const T Ascii<T>::u                    =  0x75;
        template<typename T> const T Ascii<T>::v                    =  0x76;
        template<typename T> const T Ascii<T>::w                    =  0x77;
        template<typename T> const T Ascii<T>::x                    =  0x78;
        template<typename T> const T Ascii<T>::y                    =  0x79;
        template<typename T> const T Ascii<T>::z                    =  0x7A;

        template<typename T> const T Ascii<T>::OPENING_BRACE        =  0x7B;    //  {    (left/opening brace)
        template<typename T> const T Ascii<T>::VERTICAL_BAR         =  0x7C;    //  |    (vertical bar)
        template<typename T> const T Ascii<T>::CLOSING_BRACE        =  0x7D;    //  }    (right/closing brace)
        template<typename T> const T Ascii<T>::TILDE                =  0x7E;    //  ~    (tilde)
        template<typename T> const T Ascii<T>::DEL                  =  0x7F;    //  DEL    (delete)
    }
};


#endif // GUARD_SMCPCORE_BEDROCK_TYPESYSTEM_ASCII_H
