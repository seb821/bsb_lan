/****************************************************/
/* DEFINITIONS and TYPEDEFS                         */
/****************************************************/

/*
 * TODO: If someone has some time to spare, replace multiple occasions of the same string with #define STRXXX STRYYY
 * where YYY is the first occasion and XXX one of the subsequent occasions.
 * To get a full list of string doublettes, use this command chain:
 * cat BSB_lan_defs.h | grep "const char STR" | sed -e 's/.* = \(.*\);/\1/g;' | sort | uniq -c | sort | grep -v "^.*1 \""
*/

#define PROGMEM_LATE __attribute__ (( __section__(".fini1") ))
#define PROGMEM_LATEST __attribute__ (( __section__(".fini1") ))

/* telegram types */
#define TYPE_QINF 0x01  // request info telegram
#define TYPE_INF  0x02
#define TYPE_SET  0x03
#define TYPE_ACK  0x04
#define TYPE_NACK 0x05
#define TYPE_QUR  0x06
#define TYPE_ANS  0x07
#define TYPE_ERR  0x08
#define TYPE_QRV  0x0F // query  reset value
#define TYPE_ARV  0x10 // answer reset value

/* telegram addresses */
#define ADDR_HEIZ  0x00
#define ADDR_EM1   0x03
#define ADDR_EM2   0x04
#define ADDR_RGT1  0x06
#define ADDR_RGT2  0x07
#define ADDR_CNTR  0x08
#define ADDR_DISP  0x0A
#define ADDR_SRVC  0x0B
#define ADDR_ALL   0x7F

#define BUS_BSB 0
#define BUS_LPB 1
#define BUS_PPS 2

/* special command ids */
#define CMD_UNKNOWN 0x00000000u
#define CMD_END     0xffffffffu
#define FL_RONLY    1
#define FL_NO_CMD   2
#define FL_OEM      5    // Known OEM parameters are set to read-only by default. If you want to have general write-access (not recommended!) to OEM parameters, set FL_OEM to 4.

/* heating systems */

#define DEV_028_ALL  28,255 // Brötje SOB26 / LPB
#define DEV_050_ALL  50,255 // Weishaupt
#define DEV_064_ALL  64,255   // Brötje WGB 2 (über OCI420)
#define DEV_076_ALL  76,255   // RVA63.244/160
#define DEV_085_ALL  85,255   // Elco Aquatop 8es
#define DEV_090_ALL  90,255   // RVS43.222 SSR C
#define DEV_095_ALL  95,255 // Brötje LogoBloc Unit L-UB 25C
#define DEV_096_ALL  96,255 // Brötje NovoCondens SOB 22C, 26C
#define DEV_097_100  97,100   // Brötje WGB 20 C
#define DEV_097_ALL  97,255   // Elco Thision S 17.1, Brötje WBS 14D
#define DEV_098_ALL  98,255 // Brötje Ecotherm Plus WGB Pro Evo 20C, EcoCondens BBS Pro EVO 15 C
#define DEV_103_ALL  103,255 // CTC 380 IC
#define DEV_107_ALL  107,255 // RVS43.222-Z1
#define DEV_108_ALL  108,255 // Brötje Sensotherm BSW-K
#define DEV_116_ALL  116,255 // Brötije ISR-SSR B
#define DEV_119_ALL  119,255 // Waterstage WP 5kw
#define DEV_123_ALL  123,255 // Brötje EcoTherm Kompakt WMS 24
#define DEV_138_ALL  138,255 // Brötje BOB
#define DEV_162_ALL  162,255 // Brötje WGB 15 E, WGB-S 17/20E, WBS 22 E
#define DEV_163_ALL  163,255 // Brötje WGB Evo 20 H
#define DEV_170_ALL  170,255 // Fujitsu Waterstage WSYK160DC9
#define DEV_195_ALL  195,255 // MHG Procon E 25 HS
#define DEV_203_ALL  203,255 // Elco Thision 13 Plus
#define DEV_205_ALL  205,255 // Brötje Sensotherm BLW 15 B
#define DEV_211_ALL  211,255 // Fujitsu Waterstage WSYP100DG6 (Gerätevariante: 127, Geräteindetifikation: RVS21.831F/127)
#define DEV_ALL      255,255 // All devices
#define DEV_NONE     0,0

/*
typedef struct {
  uint8_t    dev_family;             // Gerätefamilie
  uint32_t   dev_bit_id;             // Bitmuster
} device_table;

PROGMEM_LATE const device_table dev_tbl[]={
//{1,   DEV_LPB},
{28,  DEV_028_ALL},
{85,  DEV_085_ALL},
{50,  DEV_050_ALL},
{97,  DEV_097_ALL},
{90,  DEV_090_ALL},
{95,  DEV_095_ALL},
{96,  DEV_096_ALL},
{98,  DEV_098_ALL},
{103, DEV_103_ALL},
{107, DEV_107_ALL},
{108, DEV_108_ALL},
{116, DEV_116_ALL},
{138, DEV_138_ALL},
{162, DEV_162_ALL},
{163, DEV_163_ALL},
{170, DEV_170_ALL},
{203, DEV_203_ALL},
{205, DEV_203_ALL},
{211, DEV_211_ALL},
{255, DEV_NONE},
};
*/

// Menu Categories
typedef enum{
  CAT_DATUMZEIT,
  CAT_BEDIENEINHEIT,
  CAT_FUNK,
  CAT_ZEITPROG_HK1,
  CAT_ZEITPROG_HK2,
  CAT_ZEITPROG_HKP,
  CAT_ZEITPROG_TWW,
  CAT_ZEITPROG_5,
  CAT_FERIEN_HK1,
  CAT_FERIEN_HK2,
  CAT_FERIEN_HKP,
  CAT_HK1,
  CAT_KUEHL1,
  CAT_HK2,
  CAT_HKP,
  CAT_TW,
  CAT_HXPUMPE,
  CAT_SCHWIMMBAD,
  CAT_VORREGLERPUMPE,
  CAT_KESSEL,
  CAT_SITHERM,
  CAT_WAERMEPUMPE,
  CAT_ENERGIEZAEHLER,
  CAT_KASKADE,
  CAT_ZUSATZERZEUGER,
  CAT_SOLAR,
  CAT_FESTSTOFFKESSEL,
  CAT_PUFFERSPEICHER,
  CAT_TWSPEICHER,
  CAT_DRUCHLERHITZER,
  CAT_KONFIG,
  CAT_LPB,
  CAT_FEHLER,
  CAT_WARTUNG,
  CAT_MODULE,
  CAT_IOTEST,
  CAT_STATUS,
  CAT_DIAG_KASKADE,
  CAT_DIAG_ERZEUGER,
  CAT_DIAG_VERBRAUCHER,
  CAT_FEUERUNGSAUTOMAT,
  CAT_USER_DEFINED,
  CAT_PPS,
  CAT_UNKNOWN
}category_t;

/* Parameter types */
typedef enum{
  VT_BIT,               //  2 Byte - 1 enable 0x01 / value
  VT_BYTE,              //  2 Byte - 1 enable 0x01 / value
  VT_CLOSEDOPEN,        //  2 Byte - 1 enable 0x01 / 0=Offen 1=Geschlossen Choice
  VT_DAYS,              //  2 Byte - 1 enable 0x01 / day
  VT_ENUM,              //* 2 Byte - 1 enable 0x01 / value        Choice
  VT_GRADIENT_SHORT,    //  2 Byte - 1 enable / value min/K
  VT_HOURS_SHORT,       //  2 Byte - 1 enable 0x01 / hours        Int08
  VT_LPBADDR,           //* 2 Byte - 1 enable / adr/seg           READ-ONLY
  VT_MINUTES_SHORT,     //  2 Byte - 1 enable 0x06 / minutes      Int08S
  VT_MONTHS,            //  2 Byte - 1 enable 0x06 / months       Int08S
  VT_ONOFF,             //  2 Byte - 1 enable 0x01 / 0=Aus  1=An (auch 0xff=An)
//  VT_MANUAUTO,          //  2 Byte - 1 enable 0x01 / 0=Automatisch  1=Manuell //FUJITSU
//  VT_BLOCKEDREL,        //  2 Byte - 1 enable 0x01 / 0=Gesperrt  1=Freigegeben //FUJITSU
  VT_PERCENT,           //  2 Byte - 1 enable 0x06 / percent
  VT_PERCENT5,          //  2 Byte - 1 enable 0x01 / value/2
  VT_PRESSURE,          //  2 Byte - 1 enable 0x01 / bar/10.0     READ-ONLY
  VT_SECONDS_SHORT,     //  2 Byte - 1 enable / seconds
  VT_SECONDS_SHORT4,    //  2 Byte - 1 enable 0x01 / value/4 (signed?)
  VT_SECONDS_SHORT5,    //  2 Byte - 1 enable 0x01 / value/5 (signed?)
  VT_TEMP_SHORT,        //  2 Byte - 1 enable 0x01 / value
  VT_TEMP_SHORT5,       //  2 Byte - 1 enable 0x01 / value/2 (signed)
  VT_TEMP_SHORT5_US,    //  2 Byte - 1 enable 0x01 / value/2 (unsigned)
  VT_TEMP_SHORT64,      //  2 Byte - 1 enable 0x01 / value/64 (signed)
  VT_VOLTAGE,           //  2 Byte - 1 enable / volt z.B. 2.9V
  VT_VOLTAGEONOFF,      //  2 Byte - 1 enable / volt 0V (0x00) or 230V (0xFF)
  VT_WEEKDAY,           //  2 Byte - 1 enable 0x01 / weekday (1=Mo..7=So)
  VT_YESNO,             //  2 Byte - 1 enable 0x01 / 0=Nein 1=Ja (auch 0xff=Ja)
  VT_CURRENT,           //  3 Byte - 1 enable / value/100 uA
  VT_CURRENT1000,       //  3 Byte - 1 enable / value/1000 uA
  VT_DAYS_WORD,         //  3 Byte - 1 enable / day
  VT_ERRORCODE,         //  3 Byte - 1 enable / value READ-ONLY
  VT_FP1,               //  3 Byte - 1 enable / value/10 READ-ONLY
  VT_FP02,              //  3 Byte - 1 enable 0x01 / value/50
  VT_GRADIENT,          //  3 Byte - 1 enable / value min/K
  VT_HOUR_MINUTES,      //  3 Byte - 1 enable 0x06 / hh mm
  VT_HOURS_WORD,        //  3 Byte - 1 enable 0x06 / hours
  VT_MINUTES_WORD,      //  3 Byte - 1 enable 0x06 / minutes
  VT_MINUTES_WORD10,    //  3 Byte - 1 enable 0x06 / minutes / 10
  VT_PERCENT_WORD1,     //  3 Byte - 1 enable / percent
  VT_PERCENT_WORD,      //  3 Byte - 1 enable / percent/2
  VT_PERCENT_100,       //  3 Byte - 1 enable / percent/100
  VT_POWER_WORD,        //  3 Byte - 1 enable / value/10 kW
  VT_ENERGY_WORD,       //  3 Byte - 1 enable / value/10 kWh
  VT_PRESSURE_WORD,     //  3 Byte - 1 enable / bar/10.0
  VT_PROPVAL,           //  3 Byte - 1 enable / value/16
  VT_SECONDS_WORD,      //  3 Byte - 1 enable / seconds
  VT_SECONDS_WORD5,     //  3 Byte - 1 enable / seconds / 2
  VT_SPEED,             //  3 Byte - 1 enable / value * 50 rpm
  VT_SPEED2,            //  3 Byte - 1 enable / rpm
  VT_TEMP,              //  3 Byte - 1 enable / value/64
  VT_TEMP_WORD,         //  3 Byte - 1 enable / value
  VT_TEMP_WORD5_US,     //  3 Byte - 1 enable / value / 2
  VT_LITERPERHOUR,      //  3 Byte - 1 enable / value
  VT_LITERPERMIN,       //  3 Byte - 1 enable / value / 10
  VT_UINT,              //  3 Byte - 1 enable 0x06 / value
  VT_UINT5,             //  3 Byte - 1 enable / value * 5
  VT_UINT10,            //  3 Byte - 1 enable / value / 10
  VT_SINT,              //  3 Byte - 1 enable 0x06 / value
  VT_SINT1000,          //  3 Byte - 1 enable value / 1000
  VT_PPS_TIME,          //  4 Byte
  VT_DWORD,             //  5 Byte - 1 enable 0x06 / value
  VT_HOURS,             //  5 Byte - 1 enable / seconds/3600
  VT_MINUTES,           //  5 Byte - 1 enable 0x01 / seconds/60
  VT_POWER,             //  5 Byte - 1 enable / value/10 kW
  VT_POWER100,          //  5 Byte - 1 enable / value/100 kW
  VT_ENERGY10,          //  5 Byte - 1 enable / value/10 kWh
  VT_ENERGY,            //  5 Byte - 1 enable / value/1 kWh
  VT_UINT100,           //  5 Byte - 1 enable / value / 100
  VT_DATETIME,          //* 9 Byte - 1 enable 0x01 / year+1900 month day weekday hour min sec
  VT_SUMMERPERIOD,      //* 9 Byte - no flag? 1 enable / byte 2/3 month/year
  VT_VACATIONPROG,      //* 9 Byte - 1 enable 0x06 / byte 2/3 month/year
  VT_TIMEPROG,          //*12 Byte - no flag / 1_ein 1_aus 2_ein 2_aus 3_ein 3_aus (jeweils SS:MM)
  VT_STRING,            //* x Byte - 1 enable / string
  VT_UNKNOWN
}vt_type_t;

const char U_MONTHS[] PROGMEM = "Monate";
const char U_DAYS[] PROGMEM = "Tage";
const char U_HOUR[] PROGMEM = "h";
const char U_MIN[] PROGMEM = "min";
const char U_SEC[] PROGMEM = "s";
const char U_DEG[] PROGMEM = "&deg;C";
const char U_PERC[] PROGMEM = "&#037;";
const char U_RPM[] PROGMEM = "U/min";
const char U_KW[] PROGMEM = "kW";
const char U_KWH[] PROGMEM = "kWh";
const char U_CURR[] PROGMEM = "&#181;A";
const char U_BAR[] PROGMEM = "bar";
const char U_VOLT[] PROGMEM = "V";
const char U_GRADIENT[] PROGMEM = "min/K";
const char U_GRADIENTKS[] PROGMEM = "K/s";
const char U_LITERPERHOUR[] PROGMEM = "l/h";
const char U_LITERPERMIN[] PROGMEM = "l/min";
const char U_NONE[] PROGMEM = "";

typedef struct {
  uint32_t    cmd;                 // the command or fieldID
  uint8_t     category;            // the menu category
  uint8_t     type;                // the message type
  uint16_t    line;                // parameter number
  const char *desc;                // description test
  uint16_t    enumstr_len;         // sizeof enum
  const char *enumstr;             // enum string
  uint8_t     flags;               // e.g. FL_RONLY
  uint8_t     dev_fam;             // device family
  uint8_t     dev_var;             // device variant
//  uint32_t    devices;           // e.g. DEV_ALL, DEV_097_ALL, DEV_162_ALL+DEV_163_ALL, DEV_ALL-DEV_097_ALL
} cmd_t;

typedef struct {
  uint8_t   type;             // message type (e.g. VT_TEMP)
  float     operand;          // both for divisors as well as factors (1/divisor)
  uint8_t   data_type;        // Value, String, Date...
  uint8_t   precision;        // decimal places
  const char   *unit;
  uint8_t unit_len;
} units;

typedef enum {
  DT_VALS,    // plain value
  DT_ENUM,    // value (8/16 Bit) followed by space followed by text
  DT_BITS,    // bit value followed by bitmask followed by text
  DT_WDAY,    // weekday
  DT_HHMM,    // hour:minute
  DT_DTTM,    // date and time
  DT_DDMM,    // day and month
  DT_STRN,    // string
  DT_DWHM     // PPS time (day of week, hour:minute)
} dt_types_t;

PROGMEM_LATE const units optbl[]={
{VT_BIT,            1.0,    DT_BITS, 0,  U_NONE, sizeof(U_NONE)},
{VT_BYTE,           1.0,    DT_VALS, 0,  U_NONE, sizeof(U_NONE)},
{VT_CLOSEDOPEN,     1.0,    DT_VALS, 0,  U_NONE, sizeof(U_NONE)},
{VT_DAYS,           1.0,    DT_VALS, 0,  U_NONE, sizeof(U_NONE)},
{VT_ENUM,           1.0,    DT_ENUM, 0,  U_NONE, sizeof(U_NONE)},
{VT_GRADIENT_SHORT, 1.0,    DT_VALS, 0,  U_GRADIENT, sizeof(U_GRADIENT)},
{VT_HOURS_SHORT,    1.0,    DT_VALS, 0,  U_HOUR, sizeof(U_HOUR)},
{VT_LPBADDR,        1.0,    DT_VALS, 0,  U_NONE, sizeof(U_NONE)},
{VT_MINUTES_SHORT,  1.0,    DT_VALS, 0,  U_MIN, sizeof(U_MIN)},
{VT_MONTHS,         1.0,    DT_VALS, 0,  U_MONTHS, sizeof(U_MONTHS)},
{VT_ONOFF,          1.0,    DT_ENUM, 0,  U_NONE, sizeof(U_NONE)},
{VT_PERCENT,        1.0,    DT_VALS, 0,  U_PERC, sizeof(U_PERC)},
{VT_PERCENT5,       2.0,    DT_VALS, 0,  U_PERC, sizeof(U_PERC)},
{VT_PRESSURE,       10.0,   DT_VALS, 1,  U_BAR, sizeof(U_BAR)},
{VT_SECONDS_SHORT,  1.0,    DT_VALS, 0,  U_SEC, sizeof(U_SEC)},
{VT_SECONDS_SHORT4, 4.0,    DT_VALS, 1,  U_SEC, sizeof(U_SEC)},
{VT_SECONDS_SHORT5, 5.0,    DT_VALS, 1,  U_SEC, sizeof(U_SEC)},
{VT_TEMP_SHORT,     1.0,    DT_VALS, 0,  U_DEG, sizeof(U_DEG)},
{VT_TEMP_SHORT5,    2.0,    DT_VALS, 1,  U_DEG, sizeof(U_DEG)},
{VT_TEMP_SHORT5_US, 2.0,    DT_VALS, 1,  U_DEG, sizeof(U_DEG)},
{VT_TEMP_SHORT64,   64.0,   DT_VALS, 6,  U_GRADIENTKS, sizeof(U_GRADIENTKS)},
{VT_VOLTAGE,        10.0,   DT_VALS, 1,  U_VOLT, sizeof(U_VOLT)},
{VT_VOLTAGEONOFF,   1.0,    DT_ENUM, 0,  U_NONE, sizeof(U_NONE)},
{VT_WEEKDAY,        1.0,    DT_WDAY, 0,  U_NONE, sizeof(U_NONE)},
{VT_YESNO,          1.0,    DT_ENUM, 0,  U_NONE, sizeof(U_NONE)},
{VT_CURRENT,        100.0,  DT_VALS, 2,  U_CURR, sizeof(U_CURR)},
{VT_CURRENT1000,    1000.0, DT_VALS, 2,  U_CURR, sizeof(U_CURR)},
{VT_DAYS_WORD,      1.0,    DT_VALS, 0,  U_NONE, sizeof(U_NONE)},
{VT_ERRORCODE,      1.0,    DT_ENUM, 0,  U_NONE, sizeof(U_NONE)},
{VT_FP1,            10.0,   DT_VALS, 1,  U_NONE, sizeof(U_NONE)},
{VT_FP02,           50.0,   DT_VALS, 2,  U_NONE, sizeof(U_NONE)},
{VT_GRADIENT,       1.0,    DT_VALS, 0,  U_GRADIENT, sizeof(U_GRADIENT)},
{VT_HOUR_MINUTES,   1.0,    DT_HHMM, 0,  U_NONE, sizeof(U_NONE)},
{VT_HOURS_WORD,     1.0,    DT_VALS, 0,  U_HOUR, sizeof(U_HOUR)},
{VT_MINUTES_WORD,   1.0,    DT_VALS, 0,  U_MIN, sizeof(U_MIN)},
{VT_MINUTES_WORD10, 0.1,    DT_VALS, 0,  U_MIN, sizeof(U_MIN)},
{VT_PERCENT_WORD1,  1.0,    DT_VALS, 1,  U_PERC, sizeof(U_PERC)},
{VT_PERCENT_WORD,   2.0,    DT_VALS, 1,  U_PERC, sizeof(U_PERC)},
{VT_PERCENT_100,    100.0,  DT_VALS, 1,  U_PERC, sizeof(U_PERC)},
{VT_POWER_WORD,     10.0,   DT_VALS, 1,  U_KW, sizeof(U_KW)},
{VT_ENERGY_WORD,    10.0,   DT_VALS, 1,  U_KWH, sizeof(U_KWH)},
{VT_PRESSURE_WORD,  10.0,   DT_VALS, 1,  U_BAR, sizeof(U_BAR)},
{VT_PROPVAL,        16.0,   DT_VALS, 2,  U_NONE, sizeof(U_NONE)},
{VT_SECONDS_WORD,   1.0,    DT_VALS, 0,  U_SEC, sizeof(U_SEC)},
{VT_SECONDS_WORD5,  2.0,    DT_VALS, 0,  U_SEC, sizeof(U_SEC)},
{VT_SPEED,          0.02,   DT_VALS, 0,  U_RPM, sizeof(U_RPM)},
{VT_SPEED2,         1.0,    DT_VALS, 0,  U_RPM, sizeof(U_RPM)},
{VT_TEMP,           64.0,   DT_VALS, 1,  U_DEG, sizeof(U_DEG)},
{VT_TEMP_WORD,      1.0,    DT_VALS, 1,  U_DEG, sizeof(U_DEG)},
{VT_TEMP_WORD5_US,  2.0,    DT_VALS, 1,  U_DEG, sizeof(U_DEG)},
{VT_LITERPERHOUR,   1.0,    DT_VALS, 0,  U_LITERPERHOUR, sizeof(U_LITERPERHOUR)},
{VT_LITERPERMIN,    10.0,   DT_VALS, 1,  U_LITERPERMIN, sizeof(U_LITERPERMIN)},
{VT_UINT,           1.0,    DT_VALS, 0,  U_NONE, sizeof(U_NONE)},
{VT_UINT5,          5.0,    DT_VALS, 0,  U_NONE, sizeof(U_NONE)},
{VT_UINT10,         10.0,   DT_VALS, 1,  U_NONE, sizeof(U_NONE)},
{VT_SINT,           1.0,    DT_VALS, 0,  U_NONE, sizeof(U_NONE)},
{VT_SINT1000,       1000,   DT_VALS, 3,  U_NONE, sizeof(U_NONE)},
{VT_PPS_TIME,       1.0,    DT_DWHM, 0,  U_NONE, sizeof(U_NONE)},
{VT_DWORD,          1.0,    DT_VALS, 0,  U_NONE, sizeof(U_NONE)},
{VT_HOURS,          3600.0, DT_VALS, 0,  U_HOUR, sizeof(U_HOUR)},
{VT_MINUTES,        60.0,   DT_VALS, 0,  U_MIN, sizeof(U_MIN)},
{VT_POWER,          10.0,   DT_VALS, 1,  U_KW, sizeof(U_KW)},
{VT_POWER100,       100.0,  DT_VALS, 2,  U_KW, sizeof(U_KW)},
{VT_ENERGY10,       10.0,   DT_VALS, 1,  U_KWH, sizeof(U_KWH)},
{VT_ENERGY,         1.0,    DT_VALS, 0,  U_KWH, sizeof(U_KWH)},
{VT_UINT100,        100.0,  DT_VALS, 2,  U_NONE, sizeof(U_NONE)},
{VT_DATETIME,       1.0,    DT_DTTM, 0,  U_NONE, sizeof(U_NONE)},
{VT_SUMMERPERIOD,   1.0,    DT_DDMM, 0,  U_NONE, sizeof(U_NONE)},
{VT_VACATIONPROG,   1.0,    DT_DDMM, 0,  U_NONE, sizeof(U_NONE)},
{VT_TIMEPROG,       1.0,    DT_DTTM, 0,  U_NONE, sizeof(U_NONE)},
{VT_STRING,         1.0,    DT_STRN, 0,  U_NONE, sizeof(U_NONE)},
{VT_UNKNOWN,        1.0,    DT_VALS, 1,  U_NONE, sizeof(U_NONE)},
};

/****************************************************/
/* PROGMEM TABLES and STRINGS                       */
/****************************************************/
// Menue Kategorien
const char ENUM_CAT[] PROGMEM_LATEST = {
"\x00 Uhrzeit und Datum\0"
"\x01 Bedieneinheit\0"
"\x02 Funk\0"
"\x03 Zeitprogramm Heizkreis 1\0"
"\x04 Zeitprogramm Heizkreis 2\0"
"\x05 Zeitprogramm 3/HKP\0"
"\x06 Zeitprogramm 4\0"
"\x07 Zeitprogramm 5\0"
"\x08 Ferien Heizkreis 1\0"
"\x09 Ferien Heizkreis 2\0"
"\x0a Ferien Heizkreis P\0"
"\x0b Heizkreis 1\0"
"\x0c Kühlkreis 1\0"
"\x0d Heizkreis 2\0"
"\x0e Heizkreis 3/P\0"
"\x0f Trinkwasser\0"
"\x10 Hx-Pumpe\0"
"\x11 Schwimmbad\0"
"\x12 Vorregler/Zubringerpumpe\0"
"\x13 Kessel\0"
"\x14 Sitherm Pro\0"
"\x15 Wärmepumpe\0"
"\x16 Energiezähler\0"
"\x17 Kaskade\0"
"\x18 Zusatzerzeuger\0"
"\x19 Solar\0"
"\x1a Feststoffkessel\0"
"\x1b Pufferspeicher\0"
"\x1c Trinkwasserspeicher\0"
"\x1d Trinkwasser Durchl'erhitzer\0"
"\x1e Konfiguration\0"
"\x1f LPB-System\0"
"\x20 Fehler\0"
"\x21 Wartung/Sonderbetrieb\0"
"\x22 Konfiguration Erweiterungsmodule\0"
"\x23 Ein-/Ausgangstest\0"
"\x24 Status\0"
"\x25 Diagnose Kaskade\0"
"\x26 Diagnose Erzeuger\0"
"\x27 Diagnose Verbraucher\0"
"\x28 Feuerungsautomat\0"
"\x29 Benutzerdefiniert\0"
"\x2a PPS-Bus\0"
"\x2b unbekannte Kategorie"
};

const uint16_t ENUM_CAT_NR[] PROGMEM_LATEST = {
  0, 6,
  20, 70,
  120, 140,
  500, 516,
  520, 536,
  540, 556,
  560, 576,
  600, 616,
  632, 648,
  649, 665,
  666, 682,
  700, 900,
  901, 969,
  1000, 1200,
  1300, 1500,
  1600, 1680,
  2008, 2051,
  2055, 2080,
  2110, 2150,
  2200, 2551,
  2700, 2732,
  2785, 3010,
  3095, 3267,
  3510, 3590,
  3700, 3723,
  3810, 3887,
  4102, 4141,
  4708, 4813,
  5010, 5131,
  5400, 5544,
  5700, 6421,
  6600, 6650,
  6705, 6846,
  7001, 7254,
  7300, 7500,
  7700, 7999,
  8000, 8099,
  8100, 8150,
  8300, 8570,
  8700, 9075,
  9500, 9627,
  10000, 14999,
  15000, 15067
};

 /* Menue Strings */
const char STR0[]   PROGMEM = "Datum/Zeit";
const char STR1[]   PROGMEM = "Stunden/Minuten";
const char STR2[]   PROGMEM = "Tag/Monat";
const char STR3[]   PROGMEM = "Jahr";
const char STR5[]   PROGMEM = "Sommerzeitbeginn Tag/Monat";
const char STR6[]   PROGMEM = "Sommerzeitende Tag/Monat";
const char STR20[]  PROGMEM = "Sprachauswahl";
const char STR21[]  PROGMEM = "Anzeige Sonderbetrieb";
const char STR22[]  PROGMEM = "Info";
const char STR23[]  PROGMEM = "Fehleranzeige";
const char STR25[]  PROGMEM = "Anzeigekontrast";
const char STR26[]  PROGMEM = "Sperre Bedienung";
const char STR27[]  PROGMEM = "Sperre Programmierung";
const char STR28[]  PROGMEM = "Bedieneinheit Direktverstellung";
const char STR29[]  PROGMEM = "Einheiten";
const char STR30[]  PROGMEM = "Bedieneinheit Grundeinstellung sichern";
const char STR31[]  PROGMEM = "Bedieneinheit Grundeinstellung aktivieren";
const char STR40[]  PROGMEM = "Einsatz als";
const char STR42[]  PROGMEM = "Zuordnung Raumgerät 1";
const char STR44[]  PROGMEM = "Bedienung HK 2";
const char STR46[]  PROGMEM = "Bedienung HK P";
const char STR48[]  PROGMEM = "Wirkung Präsenztaste";
const char STR54[]  PROGMEM = "Korrektur Raumfühler";
const char STR70[]  PROGMEM = "Geräte-Version Bedienteil";
const char STR120[] PROGMEM = "Binding";
const char STR121[] PROGMEM = "Testmode";
const char STR130[] PROGMEM = "Raumgerät 1 Status";
const char STR131[] PROGMEM = "Raumgerät 2 Status";
const char STR132[] PROGMEM = "Raumgerät P Status";
const char STR133[] PROGMEM = "Außenfühler P Status";
const char STR134[] PROGMEM = "Repeater P Status";
const char STR135[] PROGMEM = "Bedieneinheit 1 Status";
const char STR136[] PROGMEM = "Bedieneinheit 2 Status";
const char STR137[] PROGMEM = "Bedieneinheit P Status";
const char STR138[] PROGMEM = "Servicegerät Status";
const char STR140[] PROGMEM = "Alle Geräte löschen";
/*
const char STR500[] PROGMEM = "Vorwahl";
const char STR501[] PROGMEM = "Mo-So: 1. Phase Ein";
const char STR502[] PROGMEM = "Mo-So: 1. Phase Aus";
const char STR503[] PROGMEM = "Mo-So: 2. Phase Ein";
const char STR504[] PROGMEM = "Mo-So: 2. Phase Aus";
const char STR505[] PROGMEM = "Mo-So: 3. Phase Ein";
const char STR506[] PROGMEM = "Mo-So: 3. Phase Aus";
*/
const char STR500[] PROGMEM = "Mo";
const char STR501[] PROGMEM = "Di";
const char STR502[] PROGMEM = "Mi";
const char STR503[] PROGMEM = "Do";
const char STR504[] PROGMEM = "Fr";
const char STR505[] PROGMEM = "Sa";
const char STR506[] PROGMEM = "So";
const char STR516[] PROGMEM = "Standardwerte";

const char STR520[] PROGMEM = "Mo";
const char STR521[] PROGMEM = "Di";
const char STR522[] PROGMEM = "Mi";
const char STR523[] PROGMEM = "Do";
const char STR524[] PROGMEM = "Fr";
const char STR525[] PROGMEM = "Sa";
const char STR526[] PROGMEM = "So";
const char STR536[] PROGMEM = "Standardwerte";

const char STR540[] PROGMEM = "Mo";
const char STR541[] PROGMEM = "Di";
const char STR542[] PROGMEM = "Mi";
const char STR543[] PROGMEM = "Do";
const char STR544[] PROGMEM = "Fr";
const char STR545[] PROGMEM = "Sa";
const char STR546[] PROGMEM = "So";
const char STR556[] PROGMEM = "Standardwerte";

const char STR560[] PROGMEM = "Mo";
const char STR561[] PROGMEM = "Di";
const char STR562[] PROGMEM = "Mi";
const char STR563[] PROGMEM = "Do";
const char STR564[] PROGMEM = "Fr";
const char STR565[] PROGMEM = "Sa";
const char STR566[] PROGMEM = "So";
const char STR576[] PROGMEM = "Standardwerte";

const char STR600[] PROGMEM = "Mo";
const char STR601[] PROGMEM = "Di";
const char STR602[] PROGMEM = "Mi";
const char STR603[] PROGMEM = "Do";
const char STR604[] PROGMEM = "Fr";
const char STR605[] PROGMEM = "Sa";
const char STR606[] PROGMEM = "So";
const char STR616[] PROGMEM = "Standardwerte";

/* Die Zeilennummern 632-682 entsprechen nicht den Zeilennummern im Bedienteil,
 * sondern wurden künstlich hinzugefügt */
const char STR632[] PROGMEM = "Periode 1 Beginn Tag/Monat";
const char STR633[] PROGMEM = "Periode 1 Ende Tag/Monat";
const char STR634[] PROGMEM = "Periode 2 Beginn Tag/Monat";
const char STR635[] PROGMEM = "Periode 2 Ende Tag/Monat";
const char STR636[] PROGMEM = "Periode 3 Beginn Tag/Monat";
const char STR637[] PROGMEM = "Periode 3 Ende Tag/Monat";
const char STR638[] PROGMEM = "Periode 4 Beginn Tag/Monat";
const char STR639[] PROGMEM = "Periode 4 Ende Tag/Monat";
const char STR640[] PROGMEM = "Periode 5 Beginn Tag/Monat";
const char STR641[] PROGMEM = "Periode 5 Ende Tag/Monat";
const char STR642[] PROGMEM = "Periode 6 Beginn Tag/Monat";
const char STR643[] PROGMEM = "Periode 6 Ende Tag/Monat";
const char STR644[] PROGMEM = "Periode 7 Beginn Tag/Monat";
const char STR645[] PROGMEM = "Periode 7 Ende Tag/Monat";
const char STR646[] PROGMEM = "Periode 8 Beginn Tag/Monat";
const char STR647[] PROGMEM = "Periode 8 Ende Tag/Monat";
const char STR648[] PROGMEM = "Betriebsniveau Ferien";

#define STR649 STR632
#define STR650 STR633
#define STR651 STR634
#define STR652 STR635
#define STR653 STR636
#define STR654 STR637
#define STR655 STR638
#define STR656 STR639
#define STR657 STR640
#define STR658 STR641
#define STR659 STR642
#define STR660 STR643
#define STR661 STR644
#define STR662 STR645
#define STR663 STR646
#define STR664 STR647
#define STR665 STR648

#define STR666 STR632
#define STR667 STR633
#define STR668 STR634
#define STR669 STR635
#define STR670 STR636
#define STR671 STR637
#define STR672 STR638
#define STR673 STR639
#define STR674 STR640
#define STR675 STR641
#define STR676 STR642
#define STR677 STR643
#define STR678 STR644
#define STR679 STR645
#define STR680 STR646
#define STR681 STR647
#define STR682 STR648

/*
const char STR641[] PROGMEM = "Vorwahl";
const char STR642[] PROGMEM = "Beginn Tag/Monat";
const char STR643[] PROGMEM = "Ende Tag/Monat";
const char STR648[] PROGMEM = "Betriebsniveau";
const char STR651[] PROGMEM = "Vorwahl";
const char STR652[] PROGMEM = "Beginn Tag/Monat";
const char STR653[] PROGMEM = "Ende Tag/Monat";
const char STR658[] PROGMEM = "Betriebsniveau";
const char STR661[] PROGMEM = "Vorwahl";
const char STR662[] PROGMEM = "Beginn Tag/Monat";
const char STR663[] PROGMEM = "Ende Tag/Monat";
const char STR668[] PROGMEM = "Betriebsniveau";
*/

// Heizkreis 1
const char STR700[] PROGMEM = " Mode : auto = programme de chauffe, manu = touche présence";//XXX Betriebsart
const char STR701[] PROGMEM = " Präsenztaste (temporäre Abwesenheit) ";
const char STR710[] PROGMEM = " Consigne T° ambiante ";//XXX Komfortsollwert
const char STR711[] PROGMEM = " Consigne T° ambiante - Maximum ";//XXX Komfortsollwert Maximum
const char STR712[] PROGMEM = " Consigne réduite T° ambiante #27 ";//XXX Reduziertsollwert
const char STR714[] PROGMEM = " Consigne hors gel T° ambiante #60 ";//XXX Frostschutzsollwert
const char STR720[] PROGMEM = "Kennlinie Steilheit";
const char STR721[] PROGMEM = "Kennlinie Verschiebung";
const char STR726[] PROGMEM = "Kennlinie Adaption";
const char STR730[] PROGMEM = "Sommer-/ Winterheizgrenze";
const char STR732[] PROGMEM = "Tagesheizgrenze";
const char STR740[] PROGMEM = "Vorlaufsollwert Minimum";
const char STR741[] PROGMEM = "Vorlaufsollwert Maximum";
const char STR742[] PROGMEM = "Vorlaufsollwert Raumthermostat HK1";
const char STR744[] PROGMEM = "Soll Einschaltverh R'stat";
const char STR750[] PROGMEM = "Raumeinfluss";
const char STR760[] PROGMEM = "Raumtemperaturbegrenzung";
const char STR761[] PROGMEM = "Heizgrenze Raumregler";
const char STR770[] PROGMEM = "Schnellaufheizung";
const char STR780[] PROGMEM = "Schnellabsenkung";
const char STR790[] PROGMEM = "Einschalt-Optimierung Max.";
const char STR791[] PROGMEM = "Ausschalt-Optimierung Max.";
const char STR800[] PROGMEM = "Reduziert-Anhebung Beginn";
const char STR801[] PROGMEM = "Reduziert-Anhebung Ende";
const char STR809[] PROGMEM = "Pumpendauerlauf HK1";
const char STR820[] PROGMEM = "Überhitzschutz Pumpenkreis";
const char STR830[] PROGMEM = "Mischerüberhöhung";
const char STR831[] PROGMEM = "Mischerunterkühlung";
const char STR832[] PROGMEM = "Antrieb Typ";
const char STR833[] PROGMEM = "Schaltdifferenz 2-Punkt";
const char STR834[] PROGMEM = "Antrieb Laufzeit";
const char STR835[] PROGMEM = "Mischer P-Band Xp";
const char STR836[] PROGMEM = "Mischer Nachstellzeit Tn";
const char STR850[] PROGMEM = "Estrichfunktion HK1";
const char STR851[] PROGMEM = "Estrich Sollwert manuell HK1";
const char STR855[] PROGMEM = "Vorlauftemp-Sollwert Estrich-Austrocknung HK1";
const char STR856[] PROGMEM = "Estrich Tag aktuell HK1";
const char STR857[] PROGMEM = "Estrich Tage erfüllt";
const char STR861[] PROGMEM = "Übertemperaturabnahme";
const char STR864[] PROGMEM = "Sperrsignalverstärkung";
const char STR870[] PROGMEM = "Mit Pufferspeicher";
const char STR872[] PROGMEM = "Mit Vorregler/Zubring`pumpe";
const char STR880[] PROGMEM = "HK1 Pumpe Drehzahlreduktion";
const char STR882[] PROGMEM = "Pumpendrehzahl Minimum";
const char STR883[] PROGMEM = "Pumpendrehzahl Maximum";
const char STR884[] PROGMEM = "Drehzahlstufe Ausleg'punkt";
const char STR885[] PROGMEM = "Pumpe-PWM Minimum";
const char STR886[] PROGMEM = "Norm Aussentemperatur";
const char STR887[] PROGMEM = "Vorlaufsoll NormAussentemp";
const char STR888[] PROGMEM = "dt Überhöhungsfaktor";
const char STR888_2[] PROGMEM = "Kennliniekorr bei 50% Drehz";
const char STR890[] PROGMEM = "Vorl'sollwertkorr Drehz'reg HK1";
const char STR894[] PROGMEM = "dT Spreizung Norm Aussent.";
const char STR895[] PROGMEM = "dT Spreizung Maximum";
const char STR898[] PROGMEM = "Betriebsniveauumschaltung";
const char STR900[] PROGMEM = "Betriebsartumschaltung";

// Einstellungen Kühlkreis 1
const char STR901[] PROGMEM = "Betriebsart";
const char STR902[] PROGMEM = "Komfortsollwert";
const char STR904[] PROGMEM = "Schutzsollwert";
const char STR907[] PROGMEM = "Freigabe";
const char STR908[] PROGMEM = "Vorlaufsollwert bei TA 25 °C";
const char STR909[] PROGMEM = "Vorlaufsollwert bei TA 35 °C";
const char STR912[] PROGMEM = "Kühlgrenze bei TA";
const char STR913[] PROGMEM = "Sperrdauer nach Heizende";
const char STR918[] PROGMEM = "Sommerkomp Beginn bei TA";
const char STR919[] PROGMEM = "Sommerkomp Ende bei TA";
const char STR920[] PROGMEM = "Sommerkomp Sollw’anhebung";
const char STR923[] PROGMEM = "Vorlaufsollwert Min bei TA 25 °C";
const char STR924[] PROGMEM = "Vorlaufsollwert Min bei TA 35 °C";
const char STR928[] PROGMEM = "Raumeinfluss";
const char STR932[] PROGMEM = "Raumtemperaturbegrenzung";
const char STR938[] PROGMEM = "Mischerunterkühlung";
const char STR939[] PROGMEM = "Antrieb Typ";
const char STR940[] PROGMEM = "Schaltdifferenz 2-Punkt";
#define STR941 STR834
#define STR942 STR835
#define STR943 STR836
const char STR945[] PROGMEM = "Mischventil im Heizbetrieb";
const char STR946[] PROGMEM = "Sperrdauer Taupunktwächt";
const char STR947[] PROGMEM = "Vorlaufsollw’anhebung Hygro";
const char STR948[] PROGMEM = "Vorl'anhebung Beginn bei r. F.";
const char STR950[] PROGMEM = "Vorlauftemp'diff Taupunkt";
const char STR962[] PROGMEM = "Mit Pufferspeicher";
const char STR963[] PROGMEM = "Mit Vorregler/Zubring'pumpe";
const char STR969[] PROGMEM = "Betriebsartumschaltung";

// Einstellungen Heizkreis 2
const char STR1000[] PROGMEM = "Betriebsart";
#define STR1001 STR710
const char STR1010[] PROGMEM = "Komfortsollwert";
const char STR1011[] PROGMEM = "Komfortsollwert Maximum";
const char STR1012[] PROGMEM = "Reduziertsollwert";
const char STR1014[] PROGMEM = "Frostschutzsollwert";
const char STR1020[] PROGMEM = "Kennlinie Steilheit";
const char STR1021[] PROGMEM = "Kennlinie Verschiebung";
const char STR1026[] PROGMEM = "Kennlinie Adaption";
const char STR1030[] PROGMEM = "Sommer-/Winterheizgrenze";
const char STR1032[] PROGMEM = "Tagesheizgrenze";
const char STR1040[] PROGMEM = "Vorlaufsollwert Minimum";
const char STR1041[] PROGMEM = "Vorlaufsollwert Maximum";
const char STR1042[] PROGMEM = "Vorlaufsollwert Raumthermostat";
const char STR1050[] PROGMEM = "Raumeinfluss";
const char STR1060[] PROGMEM = "Raumtemperaturbegrenzung";
const char STR1070[] PROGMEM = "Schnellaufheizung";
const char STR1080[] PROGMEM = "Schnellabsenkung";
const char STR1090[] PROGMEM = "Einschalt-Optimierung Max.";
const char STR1091[] PROGMEM = "Ausschalt-Optimierung Max.";
const char STR1100[] PROGMEM = "Reduziert-Anhebung Begin";
const char STR1101[] PROGMEM = "Reduziert-Anhebung Ende";
const char STR1109[] PROGMEM = "Pumpendauerlauf HK2";
const char STR1120[] PROGMEM = "Überhitzschutz Pumpenkreis";
#define STR1130 STR830
#define STR1131 STR831
#define STR1132 STR832
#define STR1133 STR833
#define STR1134 STR834
#define STR1135 STR835
#define STR1136 STR836
const char STR1150[] PROGMEM = "Estrichfunktion";
const char STR1151[] PROGMEM = "Estrich Sollwert manuell";
const char STR1155[] PROGMEM = "Estrich Sollwert aktuell";
const char STR1156[] PROGMEM = "Estrich Tag aktuell";
const char STR1157[] PROGMEM = "Estrich Tag erfüllt";
const char STR1161[] PROGMEM = "Übertemperaturabnahme";
const char STR1170[] PROGMEM = "Mit Pufferspeicher";
const char STR1172[] PROGMEM = "Mit Vorregler/Zubring`pumpe";
const char STR1180[] PROGMEM = "HK2 Pumpe Drehzahlreduktion";
const char STR1182[] PROGMEM = "Pumpendrehzahl Minimum";
const char STR1183[] PROGMEM = "Pumpendrehzahl Maximum";
const char STR1200[] PROGMEM = "Betriebsartumschaltung";

// Heizkreis 3/P
const char STR1300[] PROGMEM = "Betriebsart";
#define STR1301 STR701
const char STR1310[] PROGMEM = "Komfortsollwert";
const char STR1311[] PROGMEM = "Komfortsollwert Maximum";
const char STR1312[] PROGMEM = "Reduziertsollwert";
const char STR1314[] PROGMEM = "Frostschutzsollwert";
const char STR1320[] PROGMEM = "Kennlinie Steilheit";
const char STR1321[] PROGMEM = "Kennlinie Verschiebung";
const char STR1326[] PROGMEM = "Kennlinie Adaption";
const char STR1330[] PROGMEM = "Sommer-/ Winterheizgrenze";
const char STR1332[] PROGMEM = "Tagesheizgrenze";
const char STR1340[] PROGMEM = "Vorlaufsollwert Minimum";
const char STR1341[] PROGMEM = "Vorlaufsollwert Maximum";
const char STR1350[] PROGMEM = "Raumeinfluss";
const char STR1360[] PROGMEM = "Raumtemperaturbegrenzung";
const char STR1370[] PROGMEM = "Schnellaufheizung";
const char STR1380[] PROGMEM = "Schnellabsenkung";
const char STR1390[] PROGMEM = "Einschalt-Optimierung Max.";
const char STR1391[] PROGMEM = "Ausschalt-Optimierung Max.";
const char STR1400[] PROGMEM = "Reduziert-Anhebung Begin";
const char STR1401[] PROGMEM = "Reduziert-Anhebung Ende";
const char STR1420[] PROGMEM = "Überhitzschutz Pumpenkreis";
#define STR1430 STR830
#define STR1431 STR831
#define STR1432 STR832
#define STR1433 STR833
#define STR1434 STR834
const char STR1450[] PROGMEM = "Estrichfunktion";
const char STR1451[] PROGMEM = "Estrich sollwert manuell";
const char STR1455[] PROGMEM = "Estrich Sollwert aktuell";
const char STR1456[] PROGMEM = "Estrich Tag aktuell";
const char STR1457[] PROGMEM = "Estrich Tag erfüllt";
const char STR1461[] PROGMEM = "Übertemperaturabnahme";
const char STR1470[] PROGMEM = "Mit Pufferspeicher";
const char STR1472[] PROGMEM = "Mit Vorregler/Zubring`pumpe";
const char STR1482[] PROGMEM = "Pumpendrehzahl Minimum";
const char STR1483[] PROGMEM = "Pumpendrehzahl Maximum";
const char STR1500[] PROGMEM = "Betriebsartumschaltung";

// Trinkwasser
const char STR1600[] PROGMEM = "Trinkwasserbetrieb";
const char STR1601[] PROGMEM = "Manueller TWW-Push";
const char STR1602[] PROGMEM = "TWW Status";
const char STR1610[] PROGMEM = " Consigne T° ECS ";//XXX TWW Nennsollwert
const char STR1612[] PROGMEM = " Consigne réduite T° ECS ";//XXX TWW Reduziertsollwert
const char STR1614[] PROGMEM = " Consigne T° ECS - Maximum ";//XXX TWW Nennsollwert Maximum
const char STR1620[] PROGMEM = "TWW Freigabe";
const char STR1630[] PROGMEM = "TWW Ladevorrang";
const char STR1640[] PROGMEM = "Legionellenfunktion";
const char STR1641[] PROGMEM = "Legionellenfkt. Periodizität";
const char STR1642[] PROGMEM = "Legionellenfkt. Wochentag";
const char STR1644[] PROGMEM = "Legionellenfkt. Zeitpunkt";
const char STR1645[] PROGMEM = "Legionellenfkt. Sollwert";
const char STR1646[] PROGMEM = "Legionellenfkt. Verweildauer";
const char STR1647[] PROGMEM = "Legionellenfkt. Zirk`pumpe";
const char STR1660[] PROGMEM = "Zirkulationspumpe Freigabe";
const char STR1661[] PROGMEM = "Zirk`pumpe Taktbetrieb";
const char STR1663[] PROGMEM = "Zirkulations Sollwert";
const char STR1680[] PROGMEM = "Trinkwasser Betriebsartumschaltung";

// Hx Pumpe
const char STR2008[] PROGMEM = "H1 TWW-Ladevorrang";
const char STR2010[] PROGMEM = "H1 Übertemperaturabnahme";
const char STR2012[] PROGMEM = "H1 mit Pufferspeicher";
const char STR2014[] PROGMEM = "H1 Vorregler/Zubring`pumpe";
const char STR2015[] PROGMEM = "H1 Kälteanforderung";
const char STR2033[] PROGMEM = "H2 TWW-Ladevorrang";
const char STR2035[] PROGMEM = "H2 Übertemperaturabnahme";
const char STR2037[] PROGMEM = "H2 mit Pufferspeicher";
const char STR2039[] PROGMEM = "H2 Vorregler / Zubring'pumpe";
const char STR2040[] PROGMEM = "H2 Kälteanforderung";
const char STR2044[] PROGMEM = "H3 TWW-Ladevorrang";
const char STR2046[] PROGMEM = "H3 Übertemperaturabnahme";
const char STR2048[] PROGMEM = "H3 mit Pufferspeicher";
const char STR2050[] PROGMEM = "H3 Vorregler/Zubring`pumpe";
const char STR2051[] PROGMEM = "H3 Kälteanforderung";

// Schwimmbad
const char STR2055[] PROGMEM = "Sollwert Solarbeheizung";
const char STR2056[] PROGMEM = "Sollwert Erzeugerbeheizung";
const char STR2065[] PROGMEM = "Ladevorrang Solar";
const char STR2070[] PROGMEM = "Schwimmbadtemp Maximum";
const char STR2080[] PROGMEM = "Mit Solareinbindung";

// Vorregler/Zubringerpumpe
const char STR2110[] PROGMEM = "Vorlaufsollwert Minimum";
const char STR2111[] PROGMEM = "Vorlaufsollwert Maximum";
const char STR2112[] PROGMEM = "Vorlaufsollwert Kühlen Min";
#define STR2130 STR830
#define STR2131 STR831
#define STR2132 STR832
#define STR2133 STR833
#define STR2134 STR834
#define STR2135 STR835
#define STR2136 STR836
const char STR2150[] PROGMEM = "Vorregler/Zubringerpumpe";

// Kessel
const char STR2200[] PROGMEM = "Betriebsart";
const char STR2201[] PROGMEM = "Erzeugersperre";
const char STR2203[] PROGMEM = "Freigabe unter Außentemp";
const char STR2204[] PROGMEM = "Freigabe über Außentemp";
const char STR2205[] PROGMEM = "Bei Ökobetrieb";
const char STR2206[] PROGMEM = "Betrieb/Standby";
const char STR2208[] PROGMEM = "Durchladung Pufferspeicher";
const char STR2210[] PROGMEM = "Sollwert Minimum";
const char STR2211[] PROGMEM = "Sollwert Minimum OEM";
const char STR2212[] PROGMEM = " Consigne maximum ";//XXX Sollwert Maximum
const char STR2213[] PROGMEM = "Sollwert Maximum OEM";
const char STR2214[] PROGMEM = "Sollwert Handbetrieb";
const char STR2220[] PROGMEM = "Freigabeintegral Stufe 2";
const char STR2221[] PROGMEM = "Rückstellintegral Stufe 2";
const char STR2222[] PROGMEM = "Zwangseinschaltung Stufe 2";
const char STR2232[] PROGMEM = "Klappenantrieb Laufzeit";
const char STR2233[] PROGMEM = "Klappenantrieb P-Band Xp";
const char STR2234[] PROGMEM = "Klappenantrieb Nach'zeit Tn";
const char STR2235[] PROGMEM = "Klappenantrieb Vorh'zeit Tv";
const char STR2240[] PROGMEM = "Schaltdifferenz Kessel";
const char STR2241[] PROGMEM = "Kessel Brennerlaufzeit Minimum";
const char STR2243[] PROGMEM = "Brennpausenzeit Minimum";
const char STR2245[] PROGMEM = "SD Brennerpause";
const char STR2250[] PROGMEM = "Pumpennachlaufzeit";
const char STR2253[] PROGMEM = "Pumpennachlaufzeit n. TWW-Betrieb";
const char STR2260[] PROGMEM = "Anfahrentlast Verbraucher";
const char STR2261[] PROGMEM = "Anfahrentlast Kesselpumpe";
const char STR2262[] PROGMEM = "Einschaltoptimierung";
const char STR2270[] PROGMEM = "Rücklaufsollwert Minimum";
const char STR2271[] PROGMEM = "Rücklaufsollwert Min OEM";
const char STR2272[] PROGMEM = "Rückl'einfluss Verbraucher";
#define STR2282 STR834
#define STR2283 STR835
#define STR2284 STR836
const char STR2285[] PROGMEM = "Mischer Vorhaltezeit Tv";
const char STR2290[] PROGMEM = "Schaltdiff Bypasspumpe";
const char STR2291[] PROGMEM = "Steuerung Bypasspumpe";
const char STR2300[] PROGMEM = "Anl'frostschutz Kess'pumpe";
const char STR2301[] PROGMEM = "Kesselpumpe bei Erzeugersperre";
const char STR2305[] PROGMEM = "Wirkung Erzeugersperre";
const char STR2310[] PROGMEM = "TR-Funktion";
const char STR2315[] PROGMEM = "Temperaturhub Minimum";
const char STR2316[] PROGMEM = "Temperaturhub Maximum";
const char STR2317[] PROGMEM = "Temperaturhub Nenn";
const char STR2320[] PROGMEM = "Pumpenmodulation";
const char STR2322[] PROGMEM = "Pumpendrehzahl Minimum";
const char STR2323[] PROGMEM = "Pumpendrehzahl Maximum";
const char STR2324[] PROGMEM = "Drehzahl P-Band Xp";
const char STR2325[] PROGMEM = "Drehzahl Nachstellzeit Tn";
const char STR2326[] PROGMEM = "Drehzahl Vorhaltezeit Tv";
const char STR2330[] PROGMEM = "Leistung Nenn";
const char STR2331[] PROGMEM = "Leistung Grundstufe";
const char STR2334[] PROGMEM = "Leistung bei Pumpendehz. min";
const char STR2335[] PROGMEM = "Leistung bei Pumpendehz. max";
const char STR2340[] PROGMEM = "Auto Erz’folge 2 x 1 Kaskade";
const char STR2440[] PROGMEM = "Gebläse-PWM Hz Maximum";
const char STR2441[] PROGMEM = "Gebläsedrehzahl Hz Maximum";
const char STR2441_2[] PROGMEM = "Gebläseleistung Heizen Max";
const char STR2442[] PROGMEM = "Gebläse-PWM Reglerverzögerung";
const char STR2442_2[] PROGMEM = "Gebl'leistung Durchladen Max";
const char STR2443[] PROGMEM = "Gebläse-PWM Startwert DLH";
const char STR2443_2[] PROGMEM = "Gebl'leistung Startwert DLH";
const char STR2444[] PROGMEM = "Leistung Minimum";
const char STR2444_2[] PROGMEM = "Gebläseleistung TWW Max";
const char STR2445[] PROGMEM = "Nennleistung Kessel";
const char STR2445_2[] PROGMEM = "Gebl'abschaltung Heizbetrieb";
const char STR2446[] PROGMEM = "Gebläseabschaltverzögerung";
const char STR2450[] PROGMEM = "Reglerverzögerung";
const char STR2451[] PROGMEM = "Brennerpausenzeit Minimum";
const char STR2452[] PROGMEM = "SD Brennerpause";
const char STR2452_2[] PROGMEM = "Reglerverzög' Gebl'leistung";
const char STR2453[] PROGMEM = "Reglerverzögerung Dauer";
const char STR2454[] PROGMEM = "Schaltdifferenz Ein HK's";
const char STR2455[] PROGMEM = "Schaltdiff Aus Min HK's";
const char STR2456[] PROGMEM = "Schaltdiff Aus Max HK's";
const char STR2457[] PROGMEM = "Einschwingzeit HK's";
const char STR2459[] PROGMEM = "Sperrzeit dynam Schaltdiff";
const char STR2460[] PROGMEM = "Schaltdiff Ein TWW";
const char STR2461[] PROGMEM = "Schaltdiff Aus Min TWW";
const char STR2462[] PROGMEM = "Schaltdiff Aus Max TWW";
const char STR2463[] PROGMEM = "Einschwingzeit TWW";
const char STR2464[] PROGMEM = "Dyn SD bei Sollwertänderung";
const char STR2465[] PROGMEM = "Min Sollwertänderung dyn SD";
const char STR2466[] PROGMEM = "Dyn SD bei Wechsel HK/TWW";
const char STR2467[] PROGMEM = "Dyn SD bei Brenner ein";
const char STR2470[] PROGMEM = "Verz' Wärmeanfo Sonderbet";
const char STR2471[] PROGMEM = "Pumpennachlaufzeit HK's";
const char STR2472[] PROGMEM = "Pumpennachlauftemp TWW";
const char STR2473[] PROGMEM = "Abgastemp Leistungsredukt";
const char STR2474[] PROGMEM = "Abgastemp Abschaltgrenze";
const char STR2476[] PROGMEM = "Abgasüberwach' Abschaltung";
const char STR2477[] PROGMEM = "Abgasüberw Startverhin'zeit";
const char STR2478[] PROGMEM = "Parameter";
const char STR2479[] PROGMEM = "Parameter";
const char STR2480[] PROGMEM = "Statisch' Drucküberw' Absch'";
const char STR2490[] PROGMEM = "Dynam' Drucküberw Abschalt";
const char STR2491[] PROGMEM = "Dyn Überw Druckdiff Min";
const char STR2492[] PROGMEM = "Dyn Überw Druckdiff Max";
const char STR2494[] PROGMEM = "Dyn Überw Druckanhebung";
const char STR2495[] PROGMEM = "Dyn Drucküberw Überw'zeit";
const char STR2496[] PROGMEM = "Dyn Drucküberw Zeitkonst";
const char STR2500[] PROGMEM = "Druckschalter Abschaltung";
const char STR2502[] PROGMEM = "Durchfl'schalter Abschaltung";
const char STR2504[] PROGMEM = "Min Einschaltzeit Schalter";
const char STR2510[] PROGMEM = "Schnellabschaltung Temp'grad";
const char STR2511[] PROGMEM = "Schnellabschalt Überw'zeit";
const char STR2512[] PROGMEM = "Schnellabschalt Überw' RT";
const char STR2521[] PROGMEM = "Frostschutz Einschalttemp";
const char STR2522[] PROGMEM = "Frostschutz Ausschalttemp";
const char STR2527[] PROGMEM = "Kesseltemp Leistungsredukt";
const char STR2528[] PROGMEM = "Schaltdiff Leistungsredukt";
const char STR2531[] PROGMEM = "Auslösetemperatur Wächter";
const char STR2540[] PROGMEM = "Proportionalbeiwert Kp TWW";
const char STR2543[] PROGMEM = "Proportionalbeiwert Kp HK's";
const char STR2550[] PROGMEM = "Gasenergiezählung";
const char STR2551[] PROGMEM = "Gasenergiezähl Korrektur";
const char STR2630[] PROGMEM = "Auto Entlüftungsfunktion";
const char STR2655[] PROGMEM = "Ein'dauer Entlüftung";
const char STR2656[] PROGMEM = "Aus'dauer Entlüftung";
const char STR2657[] PROGMEM = "Anzahl Wiederholungen";
const char STR2662[] PROGMEM = "Entlüft'dauer Heizkreis";
const char STR2663[] PROGMEM = "Entlüft'dauer Trinkwasser";
const char STR2670[] PROGMEM = "Parameter";

//Sitherm Pro
const char STR2700[] PROGMEM = "Ergebnis letzter Drifttest";
const char STR2700_2[] PROGMEM = "Ion'strom gefiltert";
const char STR2702[] PROGMEM = "Auslösen neuer Drifttest";
const char STR2702_2[] PROGMEM = "Position Schrittmotor";
const char STR2703[] PROGMEM = "Reset Drifttest";
const char STR2703_2[] PROGMEM = "Lernwert Gasqualität";
const char STR2704[] PROGMEM = "Untergrenze Drifttest Störung";
const char STR2705[] PROGMEM = "Obergrenze Drifttest Störung";
const char STR2705_2[] PROGMEM = "R-Wert";
const char STR2706[] PROGMEM = "Betriebsphase";
const char STR2720[] PROGMEM = "Freigabe Einstellung Gasart";
const char STR2721[] PROGMEM = "Gasart";
const char STR2727[] PROGMEM = "Zünd und Überwach'bereich";
const char STR2730[] PROGMEM = "Ionisationsstrom";
const char STR2731[] PROGMEM = "Position Schrittmotor";
const char STR2732[] PROGMEM = "Lernwert Gasqualität";
const char STR2741[] PROGMEM = "ADA Punkt Nr";
const char STR2742[] PROGMEM = "ADA Filterwert";
const char STR2743[] PROGMEM = "ADA Korrektur";
const char STR2744[] PROGMEM = "ADA vergangene Zeit";
const char STR2745[] PROGMEM = "ADA Ergebnis";
const char STR2749[] PROGMEM = "Reset Drifttest";
const char STR2750[] PROGMEM = "Anstehende Drifttests";
const char STR2751[] PROGMEM = "ADA Zeitintervall 1";
const char STR2752[] PROGMEM = "ADA Zeitintervall 2";
const char STR2753[] PROGMEM = "ADA Zeitintervall 3";

// Wärmepumpe
const char STR2785[] PROGMEM = "Max Kondensationstemp";
const char STR2786[] PROGMEM = "Max Kondensationstemp SD";
const char STR2787[] PROGMEM = "Max Kondens'temp Reduktion";
const char STR2789[] PROGMEM = "Kondensatorpumpe bei TWW";
const char STR2790[] PROGMEM = "Modulation Kondens'pumpe"; //Temp'spreizung Kondensator
const char STR2792[] PROGMEM = "Pumpendrehzahl Minimum";
const char STR2793[] PROGMEM = "Pumpendrehzahl Maximum";
#define STR2794 STR2324
#define STR2795 STR2325
#define STR2796 STR2326
const char STR2799[] PROGMEM = "Pumpensollw'reduktion";
const char STR2800[] PROGMEM = "Frostschutz Kondens’pumpe";
const char STR2801[] PROGMEM = "Steuerung Kondens’pumpe";
const char STR2802[] PROGMEM = "Vorlaufzeit Kondens’pumpe";
const char STR2803[] PROGMEM = "Nachlaufzeit Kondens’pumpe";
const char STR2804[] PROGMEM = "Max Temp'spreizung Konden";
const char STR2805[] PROGMEM = "Soll Temp’Spreizung Kond";
const char STR2806[] PROGMEM = "Max Abweich Spreiz Kondens";
const char STR2807[] PROGMEM = "Min Kondens'spreizung TWW";
const char STR2809[] PROGMEM = "Temperatur Frost-Alarm";
const char STR2810[] PROGMEM = "Kondensatorfrostschutz";
const char STR2811[] PROGMEM = "Nachlauf Kond'frostschutz";
const char STR2814[] PROGMEM = "Quellentemperatur Maximum";
const char STR2815[] PROGMEM = "Quellentemp Min Wasser";
const char STR2816[] PROGMEM = "Quellentemp Min Sole";
const char STR2817[] PROGMEM = "Schaltdiff Quellenschutz";
const char STR2818[] PROGMEM = "Erhöhung Quellenschutztemp Min Estrich";
const char STR2819[] PROGMEM = "Vorlaufzeit Quelle";
const char STR2820[] PROGMEM = "Nachlaufzeit Quelle";
const char STR2821[] PROGMEM = "Quellen-Anlaufzeit Maximum";
const char STR2822[] PROGMEM = "Zeit Begr Quellentemp Min Sole";
const char STR2823[] PROGMEM = "Soll Temp'spreizungn Verda";
const char STR2824[] PROGMEM = "Max Abweich Spreiz Verda";
const char STR2825[] PROGMEM = "Min Verdampf'temperatur";
const char STR2826[] PROGMEM = "Max Verdampf'temperatur";
const char STR2827[] PROGMEM = "Zeit Begr Quellentemp";
const char STR2829[] PROGMEM = "Erw Bereich min Verda'temp";
const char STR2830[] PROGMEM = "Max Dauer erw Verda'temp";
const char STR2835[] PROGMEM = "Wiederein'sperre Verdichter";
const char STR2836[] PROGMEM = "Beginn Ausschalttemp'absenk";
const char STR2837[] PROGMEM = "Ausschalttemp Max abgesenkt";
const char STR2838[] PROGMEM = "Stabil'zeit Prozessumkehr";
const char STR2839[] PROGMEM = "Stabil'zeit Umschalt TWW/HK";
const char STR2840[] PROGMEM = "Schaltdiff Rücklauftemp";
const char STR2841[] PROGMEM = "Verd'laufzeit min einhalten";
const char STR2842[] PROGMEM = "Verdichterlaufzeit Minimum";
const char STR2843[] PROGMEM = "Verdichtersillstandszeit Min";
const char STR2844[] PROGMEM = "Ausschalttemp. max";
const char STR2845[] PROGMEM = "Reduktion Ausschaltemp Max";
const char STR2846[] PROGMEM = "Heissgastemp Max";
const char STR2847[] PROGMEM = "Schaltdiff Heissgastemp Max";
const char STR2848[] PROGMEM = "Reduktion Heissgastemp Max";
const char STR2849[] PROGMEM = "Sollwert Heissgastemperatur";
const char STR2850[] PROGMEM = "SD Sollwert Heissgastemp";
const char STR2851[] PROGMEM = "Wirksinn Sollw Heissgastemp";
const char STR2852[] PROGMEM = "ND-Verzögerung beim Start";
const char STR2853[] PROGMEM = "ND-Verzögerung im Betrieb";
const char STR2854[] PROGMEM = "ND-Überwachung";
const char STR2860[] PROGMEM = "Sperre Stufe 2 bei TWW";
const char STR2861[] PROGMEM = "Freigabe Stufe 2 unter TA";
const char STR2862[] PROGMEM = "Sperrzeit Stufe/Mod";
const char STR2863[] PROGMEM = "Freigabeintegr Stufe2/Mod";
const char STR2864[] PROGMEM = "Rückstellintegr Stufe2/Mod";
const char STR2865[] PROGMEM = "Verdichterfolge Umschaltung";
const char STR2867[] PROGMEM = "Leistung Optimum";
const char STR2868[] PROGMEM = "Leistung Nenn";
const char STR2870[] PROGMEM = "Verdichtermodulation Max";
const char STR2871[] PROGMEM = "Verdichtermodulation Min";
const char STR2873[] PROGMEM = "Verdichtermod Laufzeit";
const char STR2874[] PROGMEM = "Verdichtermod P-Band Xp";
const char STR2875[] PROGMEM = "Verdichtermod Nach'zeit Tn";
const char STR2878[] PROGMEM = "PWM Periode Digital Scroll";
const char STR2879[] PROGMEM = "Verdichtermod Laufzeit Zu";
const char STR2880[] PROGMEM = "Verwendung Elektro-Vorlauf";
const char STR2881[] PROGMEM = "Sperrzeit Elektro-Vorlauf";
const char STR2882[] PROGMEM = "Freigabeintegr. Elektro-Vorl";
const char STR2883[] PROGMEM = "Rückstellintegr. Elektro-Vorl";
const char STR2884[] PROGMEM = "Freig Elektro-Vorl unter TA";
const char STR2886[] PROGMEM = "Kompensation Wärmedefizit";
const char STR2889[] PROGMEM = "Dauer Fehlerwiederholung";
const char STR2893[] PROGMEM = "Anzahl TWW-Ladeversuche";
const char STR2894[] PROGMEM = "Verzögerung Drehstr'fehler";
const char STR2895[] PROGMEM = "Verzögerung Ström'wächter";
const char STR2896[] PROGMEM = "Ström'wächter Quelle aktiv";
const char STR2898[] PROGMEM = "Min Fluss Str'wächter Quelle";
const char STR2899[] PROGMEM = "Min Fluss Str'wächter Verbr";
const char STR2903[] PROGMEM = "Freigabestrategie";
const char STR2904[] PROGMEM = "Freigabe Leistungszahl";
const char STR2908[] PROGMEM = "TA Grrenzen bei TWW";
const char STR2909[] PROGMEM = "Freigabe unter Aussentemp";
const char STR2910[] PROGMEM = "Freigabe oberhalb TA";
const char STR2911[] PROGMEM = "Für Pufferzwangsladung";
const char STR2912[] PROGMEM = "Durchladung Pufferspeicher";
const char STR2916[] PROGMEM = "Sollwert WP Max TWW";
const char STR2920[] PROGMEM = "Bei EW Sperre";
const char STR2922[] PROGMEM = "Kondensatorüberhitzungsschutz";
const char STR2923[] PROGMEM = "Kond'schutz Pufferfühler";
const char STR2941[] PROGMEM = "Verwendung Umlenkventil Y28";
const char STR2951[] PROGMEM = "Abtaufreigabe unterhalb TA";
const char STR2952[] PROGMEM = "Schaltdifferenz Abtauen";
const char STR2954[] PROGMEM = "Verdampfertemp Abtau-Ende";
const char STR2963[] PROGMEM = "Dauer bis Zwangsabtauen";
const char STR2964[] PROGMEM = "Abtaudauer Maximal";
const char STR2965[] PROGMEM = "Abtropfdauer Verdampfer";
const char STR2966[] PROGMEM = "Abkühldauer Verdampfer";
const char STR2970[] PROGMEM = "Ausschalttemp Minimum";
const char STR3000[] PROGMEM = "Ausschalttemp Max Kühlen";
const char STR3002[] PROGMEM = "Quellentemp min Kühlbetrieb";
const char STR3004[] PROGMEM = "SD Umschalt Kühlen Pas/Akt";
const char STR3006[] PROGMEM = "Während Verdichterbetrieb";
const char STR3007[] PROGMEM = "Im passiven Kühlbetrieb";
const char STR3008[] PROGMEM = "Spreizung Konden Kühlbetr";
const char STR3009[] PROGMEM = "Modulation V'lator/Q'pump";
const char STR3010[] PROGMEM = "Drehz max V'lator/Q'Pump";
const char STR3011[] PROGMEM = "Drehz min V'lator/Q'Pump";
const char STR3012[] PROGMEM = "Quelle Aus unter Temp B83";
const char STR3014[] PROGMEM = "Schaltdifferenz Quelle Aus";

// Energiezähler (Fujitsu Waterstage)
const char STR3095[] PROGMEM = "Durchflussmessung Wärme";
const char STR3097[] PROGMEM = "Durchfluss Heizen";
const char STR3098[] PROGMEM = "Durchfluss Trinkwasser";
const char STR3100[] PROGMEM = "Impulszählung Energie";
const char STR3102[] PROGMEM = "Impulseinheit Energie";
const char STR3103[] PROGMEM = "Impulswert Energie Zähler";
const char STR3104[] PROGMEM = "Impulswert Energie Nenner";
const char STR3109[] PROGMEM = "Zählung Intern Elektro Vorl’";
const char STR3110[] PROGMEM = "Abgegebene Wärme";
const char STR3113[] PROGMEM = "Eingesetzte Energie";
const char STR3121[] PROGMEM = "Abgegeb’ Wärme Heizen 1";
const char STR3122[] PROGMEM = "Abgegeb’ Wärme TWW 1";
const char STR3123[] PROGMEM = "Abgegeb’ Kälte 1";
const char STR3124[] PROGMEM = "Einges’ Energie Heizen 1";
const char STR3125[] PROGMEM = "Einges’ Energie TWW 1";
const char STR3126[] PROGMEM = "Einges’ Energie Kühlen 1";
const char STR3128[] PROGMEM = "Abgegeb’ Wärme Heizen 2";
const char STR3129[] PROGMEM = "Abgegeb’ Wärme TWW 2";
const char STR3130[] PROGMEM = "Abgegeb’ Kälte 2";
const char STR3131[] PROGMEM = "Einges’ Energie Heizen 2";
const char STR3132[] PROGMEM = "Einges’ Energie TWW 2";
const char STR3133[] PROGMEM = "Einges’ Energie Kühlen 2";
const char STR3135[] PROGMEM = "Abgegeb’ Wärme Heizen 3";
const char STR3136[] PROGMEM = "Abgegeb’ Wärme TWW 3";
const char STR3137[] PROGMEM = "Abgegeb’ Kälte 3";
const char STR3138[] PROGMEM = "Einges’ Energie Heizen 3";
const char STR3139[] PROGMEM = "Einges’ Energie TWW 3";
const char STR3140[] PROGMEM = "Einges’ Energie Kühlen 3";
const char STR3142[] PROGMEM = "Abgegeb’ Wärme Heizen 4";
const char STR3143[] PROGMEM = "Abgegeb’ Wärme TWW 4";
const char STR3144[] PROGMEM = "Abgegeb’ Kälte 4";
const char STR3145[] PROGMEM = "Einges’ Energie Heizen 4";
const char STR3146[] PROGMEM = "Einges’ Energie TWW 4";
const char STR3147[] PROGMEM = "Einges’ Energie Kühlen 4";
const char STR3149[] PROGMEM = "Abgegeb’ Wärme Heizen 5";
const char STR3150[] PROGMEM = "Abgegeb’ Wärme TWW 5";
const char STR3151[] PROGMEM = "Abgegeb’ Kälte 5";
const char STR3152[] PROGMEM = "Einges’ Energie Heizen 5";
const char STR3153[] PROGMEM = "Einges’ Energie TWW 5";
const char STR3154[] PROGMEM = "Einges’ Energie Kühlen 5";
const char STR3156[] PROGMEM = "Abgegeb’ Wärme Heizen 6";
const char STR3157[] PROGMEM = "Abgegeb’ Wärme TWW 6";
const char STR3158[] PROGMEM = "Abgegeb’ Kälte 6";
const char STR3159[] PROGMEM = "Einges’ Energie Heizen 6";
const char STR3160[] PROGMEM = "Einges’ Energie TWW 6";
const char STR3161[] PROGMEM = "Einges’ Energie Kühlen 6";
const char STR3163[] PROGMEM = "Abgegeb’ Wärme Heizen 7";
const char STR3164[] PROGMEM = "Abgegeb’ Wärme TWW 7";
const char STR3165[] PROGMEM = "Abgegeb’ Kälte 7";
const char STR3166[] PROGMEM = "Einges’ Energie Heizen 7";
const char STR3167[] PROGMEM = "Einges’ Energie TWW 7";
const char STR3168[] PROGMEM = "Einges’ Energie Kühlen 7";
const char STR3170[] PROGMEM = "Abgegeb’ Wärme Heizen 8";
const char STR3171[] PROGMEM = "Abgegeb’ Wärme TWW 8";
const char STR3172[] PROGMEM = "Abgegeb’ Kälte 8";
const char STR3173[] PROGMEM = "Einges’ Energie Heizen 8";
const char STR3174[] PROGMEM = "Einges’ Energie TWW 8";
const char STR3175[] PROGMEM = "Einges’ Energie Kühlen 8";
const char STR3177[] PROGMEM = "Abgegeb’ Wärme Heizen 9";
const char STR3178[] PROGMEM = "Abgegeb’ Wärme TWW 9";
const char STR3179[] PROGMEM = "Abgegeb’ Kälte 9";
const char STR3180[] PROGMEM = "Einges’ Energie Heizen 9";
const char STR3181[] PROGMEM = "Einges’ Energie TWW 9";
const char STR3182[] PROGMEM = "Einges’ Energie Kühlen 9";
const char STR3184[] PROGMEM = "Abgegeb’ Wärme Heizen 10";
const char STR3185[] PROGMEM = "Abgegeb’ Wärme TWW 10";
const char STR3186[] PROGMEM = "Abgegeb’ Kälte 10";
const char STR3187[] PROGMEM = "Einges’ Energie Heizen 10";
const char STR3188[] PROGMEM = "Einges’ Energie TWW 10";
const char STR3189[] PROGMEM = "Einges’ Energie Kühlen 10";
const char STR3190[] PROGMEM = "Reset Stichtagspeicher";
const char STR3264[] PROGMEM = "Energiepreis HT";
const char STR3265[] PROGMEM = "Energiepreis NT/SG-Wunsch";
const char STR3266[] PROGMEM = "Energiepreis SG-Zwang";
const char STR3267[] PROGMEM = "Energiepreis Alternativ Erz";

// 3500 Kaskade
const char STR3510[] PROGMEM = "Führungsstrategie";
const char STR3511[] PROGMEM = "Leistungsband Minimum";
const char STR3512[] PROGMEM = "Leistungsband Maximum";
const char STR3530[] PROGMEM = "Freigabeintegral Erz’folge";
const char STR3531[] PROGMEM = "Rückstellintegral Erz’folge";
const char STR3532[] PROGMEM = "Wiedereinschaltsperre";
const char STR3533[] PROGMEM = "Zuschaltverzögerung";
const char STR3534[] PROGMEM = "Zwangszeit Grundstufe";
const char STR3540[] PROGMEM = "Auto Erz’folge Umschaltung";
const char STR3541[] PROGMEM = "Auto Erz’folge Ausgrenzung";
const char STR3544[] PROGMEM = "Führender Erzeuger";
const char STR3550[] PROGMEM = "Anfahrentlast Kaskad'pumpe";
const char STR3560[] PROGMEM = "Rücklaufsollwert Minimum";
const char STR3561[] PROGMEM = "Rücklaufsollwert Min OEM";
const char STR3562[] PROGMEM = "Rückl'einfluss Verbraucher";
#define STR3570 STR834
#define STR3571 STR835
#define STR3572 STR836
const char STR3590[] PROGMEM = "Temp’spreizung Minimum";

// 3700 Zusatzerzeuger
const char STR3700[] PROGMEM = "Freigabe unter Außentemp";
const char STR3701[] PROGMEM = "Freigabe über Außentemp";
const char STR3705[] PROGMEM = "Nachlaufzeit";
const char STR3720[] PROGMEM = "Schaltintegral";
const char STR3722[] PROGMEM = "Schaltdifferenz Aus";
const char STR3723[] PROGMEM = "Sperrzeit";

// 3800 Solar
const char STR3810[] PROGMEM = "Temperaturdifferenz Ein";
const char STR3811[] PROGMEM = "Temperaturdifferenz Aus";
const char STR3812[] PROGMEM = "Ladetemp Min TWW-Speicher";
const char STR3813[] PROGMEM = "Temp’diff EIN Puffer";
const char STR3814[] PROGMEM = "Temp’diff AUS Puffer";
const char STR3815[] PROGMEM = "Ladetemp Min Puffer";
const char STR3816[] PROGMEM = "Temp'differenz EIN Sch'bad";
const char STR3817[] PROGMEM = "Temp'differenz AUS Sch'bad";
const char STR3818[] PROGMEM = "Ladetemp Min Schwimmbad";
const char STR3822[] PROGMEM = "Ladevorrang Speicher";
const char STR3825[] PROGMEM = "Ladezeit relativer Vorrang";
const char STR3826[] PROGMEM = "Wartezeit relativer Vorrang";
const char STR3827[] PROGMEM = "Wartezeit Parallelbetrieb";
const char STR3828[] PROGMEM = "Verzögerung Sekundärpumpe";
const char STR3830[] PROGMEM = "Kollektorstartfunktion";
const char STR3831[] PROGMEM = "Mindestlaufzeit Kollek`pumpe";
const char STR3832[] PROGMEM = "Kollektorstartfunktion Ein";
const char STR3833[] PROGMEM = "Kollektorstartfunktion Aus";
const char STR3834[] PROGMEM = "Kollektorstartfkt Gradient";
const char STR3840[] PROGMEM = "Kollektor Frostschutz";
const char STR3850[] PROGMEM = "Kollektorüberhitzschutz";
const char STR3860[] PROGMEM = "Verdampfung Wärmeträger";
const char STR3870[] PROGMEM = "Pumpendrehzahl Minimum";
const char STR3871[] PROGMEM = "Pumpendrehzahl Maximum";
#define STR3872 STR835
#define STR3873 STR836
const char STR3880[] PROGMEM = "Frostschutzmittel";
const char STR3881[] PROGMEM = "Frost'mittel Konzentration";
const char STR3884[] PROGMEM = "Pumpendurchfluss";
const char STR3887[] PROGMEM = "Impulseinheit Ertrag";

// 4100 Feststoffkessel
const char STR4102[] PROGMEM = "Sperrt andere Erzeuger";
const char STR4110[] PROGMEM = "Sollwert Minimum";
const char STR4112[] PROGMEM = "Sollwert Maximum";
const char STR4130[] PROGMEM = "Temperaturdifferenz Ein";
const char STR4131[] PROGMEM = "Temperaturdifferenz Aus";
const char STR4133[] PROGMEM = "Vergleichstemperatur";
const char STR4140[] PROGMEM = "Pumpennachlaufzeit";
const char STR4141[] PROGMEM = "Übertemperaturableitung";
const char STR4170[] PROGMEM = "Anl'frostschutz Kess'pumpe";


// 4700 Pufferspeicher
const char STR4708[] PROGMEM = "Zwangsladungsollwert Kühlen";
const char STR4709[] PROGMEM = "Zwangsladungsoll Heizen Min";
const char STR4710[] PROGMEM = "Zwangsladungsoll Heizen Max";
const char STR4711[] PROGMEM = "Zwangsladung Zeitpunkt";
const char STR4712[] PROGMEM = "Zwangsladung Dauer Max";
const char STR4720[] PROGMEM = "Auto Erzeugersperre";
const char STR4721[] PROGMEM = "Auto Erzeugersperre SD";
const char STR4722[] PROGMEM = "Temp`diff Puffer/Heizkreis";
const char STR4724[] PROGMEM = "Min Speichertemp Heizbetrieb";
const char STR4739[] PROGMEM = "Schichtschutz";
const char STR4740[] PROGMEM = "Schichtschutz Tempdiff Max";
const char STR4743[] PROGMEM = "Schichtschutz Vor’schauzeit";
const char STR4744[] PROGMEM = "Schichtschutz Nachstellzeit";
const char STR4746[] PROGMEM = "Trinkwasserschutz Kombi";
const char STR4750[] PROGMEM = "Ladetemperatur Maximum";
const char STR4751[] PROGMEM = "Speichertemperatur Maximum";
const char STR4755[] PROGMEM = "Rückkühltemperatur";
const char STR4756[] PROGMEM = "Rückkühlung TWW/HK`s";
const char STR4757[] PROGMEM = "Rückkühlung Kollektor";
const char STR4760[] PROGMEM = "Ladefühler Elektroeinsatz";
const char STR4761[] PROGMEM = "Zwangsladung mit Elektro";
const char STR4783[] PROGMEM = "Mit Solareinbindung";
const char STR4790[] PROGMEM = "Temp'diff EIN Rückl'umlenk";
const char STR4791[] PROGMEM = "Temp'diff AUS Rückl'umlenk";
const char STR4795[] PROGMEM = "Vergleichstemp Rückl'umlenk";
const char STR4796[] PROGMEM = "Wirksinn Rücklaufumlenkung";
const char STR4810[] PROGMEM = "Durchladung Puffersp";
const char STR4811[] PROGMEM = "Durchladetemperatur Minimum";
const char STR4813[] PROGMEM = "Durchladefühler";
// 5000 Trinkwasserspeicher
const char STR5010[] PROGMEM = " ECS (Eau Chaude Sanitaire) ";//XXX Trinkwasserladung
const char STR5011[] PROGMEM = "Trinkwasser-Speicher Ladevorlegungszeit";
const char STR5019[] PROGMEM = "TWW Nachlad'Überhöh Schichtensp";
const char STR5020[] PROGMEM = "TWW Vorlaufsollwertüberhöhung";
const char STR5021[] PROGMEM = "TWW Umladeüberhöhung";
const char STR5022[] PROGMEM = "TW Nachladeregelung";
const char STR5022_2[] PROGMEM = "Ladeart";
const char STR5024[] PROGMEM = "TWW Schaltdifferenz 1 ein";
const char STR5025[] PROGMEM = "TWW Schaltdifferenz 1 Aus min";
const char STR5026[] PROGMEM = "TWW Schaltdifferenz 1 Aus max";
const char STR5027[] PROGMEM = "TWW Schaltdifferenz 2 Ein";
const char STR5028[] PROGMEM = "TWW Schaltdifferenz 2 Aus min";
const char STR5029[] PROGMEM = "TWW Schaltdifferenz 2 Aus max";
const char STR5030[] PROGMEM = "TWW Ladezeitbegrenzung";
const char STR5040[] PROGMEM = "TWW Entladeschutz";
const char STR5050[] PROGMEM = "TWW Ladetemperatur Maximum";
const char STR5051[] PROGMEM = "TWW Speichertemperatur Maximum";
const char STR5055[] PROGMEM = "TWW Rückkühltemperatur";
const char STR5056[] PROGMEM = "TWW Rückkühlung Kessel/HK";
const char STR5057[] PROGMEM = "TWW Rückkühlung Kollektor";
const char STR5060[] PROGMEM = "TWW Elektroeinsatz Betriebsart";
const char STR5061[] PROGMEM = "TWW Elektroeinsatz Freigabe";
const char STR5062[] PROGMEM = "TWW Elektroeinsatz Regelung";
const char STR5070[] PROGMEM = "TWW Automatischer Push";
const char STR5071[] PROGMEM = "TWW Ladevorrangzeit Push";
const char STR5085[] PROGMEM = "TWW Übertemperaturabnahme";
const char STR5090[] PROGMEM = "TWW Mit Pufferspeicher";
const char STR5092[] PROGMEM = "TWW Mit Vorregler/Zubring`pumpe";
const char STR5093[] PROGMEM = "TWW Mit Solareinbindung";
const char STR5100[] PROGMEM = "TWW Pumpe-PWM Durchladung";
const char STR5101[] PROGMEM = "TWW Pumpendrehzahl Minimum";
const char STR5102[] PROGMEM = "TWW Pumpendrehzahl Maximum";
#define STR5103 STR2324
#define STR5104 STR2325
#define STR5105 STR2326
#define STR5120 STR830
#define STR5124 STR834
#define STR5125 STR835
#define STR5126 STR836
const char STR5130[] PROGMEM = "TWW Umladestrategie";
const char STR5131[] PROGMEM = "Vergleichstemp Umladung";

// 5400 Trinkwasser Durchlauferhitzer
const char STR5400[] PROGMEM = "Komfortsollwert";
const char STR5406[] PROGMEM = "Min Sollw'diff zu Speich'temp";
const char STR5420[] PROGMEM = "Vorlauf-Sollwertüberhöhung";
const char STR5430[] PROGMEM = "Einschaltdifferenz im BW-Betrieb (Fühler 1)";
const char STR5431[] PROGMEM = "Min. Ausschaltdifferenz im BW-Betrieb (Fühler 1)";
const char STR5432[] PROGMEM = "Max. Ausschaltdifferenz im BW-Betrieb (Fühler 1)";
const char STR5433[] PROGMEM = "Einschaltdifferenz im BW-Betrieb (Fühler 2)";
const char STR5434[] PROGMEM = "Min. Ausschaltdifferenz im BW-Betrieb (Fühler 2)";
const char STR5435[] PROGMEM = "Max. Ausschaltdifferenz im BW-Betrieb (Fühler 2)";
const char STR5450[] PROGMEM = "Schwelle zum Beenden einer Bw-Zapfung bei DLH";
const char STR5451[] PROGMEM = "Schwelle für Bw-Zapfung bei DLH in Komfort";
const char STR5452[] PROGMEM = "Schwelle für Bw-Zapfung bei Dlh in Heizbetrieb";
const char STR5453[] PROGMEM = "Sollwertkorrektur bei Komfortregelung mit 40°C";
const char STR5454[] PROGMEM = "Sollwertkorrektur bei Komfortregelung mit 60°C";
const char STR5455[] PROGMEM = "Sollwertkorrektur bei Auslaufregelung mit 40°C";
const char STR5456[] PROGMEM = "Sollwertkorrektur bei Auslaufregelung mit 60°C";
const char STR5480[] PROGMEM = "Komfortzeit ohne Hz-Anforderung";
const char STR5481[] PROGMEM = "Komfortzeit mit Hz-Anforderung";
const char STR5482[] PROGMEM = "Zeit TWW-FlowSwitch geschlossen";
const char STR5483[] PROGMEM = "Zeit TWW-Komfort FlowSwitch geschlossen";
const char STR5486[] PROGMEM = "Reglerverzögerung bei Takten in DLH Auslaufbetr.";
const char STR5487[] PROGMEM = "Pumpennachlauf Komf in Sek.";
const char STR5488[] PROGMEM = "Pumpennachlauf Komf in Min.";
const char STR5530[] PROGMEM = "Pumpendrehzahl Minimum";
#define STR5544 STR834
#define STR5545 STR835
#define STR5546 STR836
#define STR5547 STR2285
// Konfiguration
const char STR5700[] PROGMEM = "Voreinstellung";
const char STR5701[] PROGMEM = "Hydraulisches Schema";
const char STR5710[] PROGMEM = "Heizkreis 1";
const char STR5711[] PROGMEM = "Kühlkreis 1";
const char STR5712[] PROGMEM = "Verwendung Mischer 1";
const char STR5715[] PROGMEM = "Heizkreis 2";
const char STR5721[] PROGMEM = "Heizkreis 3";
const char STR5730[] PROGMEM = "Trinkwasser-Sensor B3";
const char STR5731[] PROGMEM = "Trinkwasser-Stellglied Q3";
const char STR5732[] PROGMEM = "TWW Pumpenpause Umsch UV";
const char STR5733[] PROGMEM = "TWW Pumpenpause Verzögerung";
const char STR5734[] PROGMEM = "Grundposition TWW Umlenkventil";
const char STR5736[] PROGMEM = "Trinkwasser Trennschaltung";
// const char STR5737[] PROGMEM = "Wirksinn TWW Umlenkventil";
const char STR5760[] PROGMEM = "Vorregler/Zubringerpumpe";
const char STR5761[] PROGMEM = "Zubringerpumpe Q8 Bit 0-3";
const char STR5770[] PROGMEM = "Erzeugertyp";
const char STR5772[] PROGMEM = "Brenner Vorlaufzeit";
const char STR5774[] PROGMEM = "Steuerung Kesselpumpe/TWW Umlenkventil";
const char STR5800[] PROGMEM = "Wärmequelle";
const char STR5806[] PROGMEM = "Typ Elektroeinsatz Vorlauf";  //FUJITSU
const char STR5807[] PROGMEM = "Kälteerzeugung";
const char STR5810[] PROGMEM = "Spreizung HK bei TA –10 °C";
const char STR5840[] PROGMEM = "Solarstellglied";
const char STR5841[] PROGMEM = "Externer Solartauscher";
const char STR5870[] PROGMEM = "Kombispeicher";
const char STR5890[] PROGMEM = "Relaisausgang QX1";
const char STR5890_2[] PROGMEM = "Pumpenfunktion Ausgang K6";
const char STR5891[] PROGMEM = "Relaisausgang QX2";
const char STR5891_2[] PROGMEM = "Pumpenfunktion Ausgang K7";
const char STR5892[] PROGMEM = "Relaisausgang QX3";
const char STR5894[] PROGMEM = "Relaisausgang QX4";
const char STR5895[] PROGMEM = "Relaisausgang QX5";
const char STR5896[] PROGMEM = "Relaisausgang QX6";
const char STR5902[] PROGMEM = "Relaisausgang QX21";
const char STR5904[] PROGMEM = "Relaisausgang QX23";
const char STR5908[] PROGMEM = "Funktion Ausgang QX3-Mod";
const char STR5909[] PROGMEM = "Funktion Ausgang QX4-Mod";
const char STR5920[] PROGMEM = "Programmierbarer Ausgang K2";
const char STR5921[] PROGMEM = "Default K2 auf K1";
const char STR5922[] PROGMEM = "Relaisausgang 1 RelCl";
const char STR5923[] PROGMEM = "Relaisausgang 2 RelCl";
const char STR5924[] PROGMEM = "Relaisausgang 3 RelCl";
const char STR5926[] PROGMEM = "Relaisausgang 1 SolCl";
const char STR5927[] PROGMEM = "Relaisausgang 2 SolCl";
const char STR5928[] PROGMEM = "Relaisausgang 3 SolCl";
const char STR5930[] PROGMEM = "Fühlereingang BX 1";
const char STR5931[] PROGMEM = "Fühlereingang BX 2";
const char STR5932[] PROGMEM = "Fühlereingang BX 3";
const char STR5933[] PROGMEM = "Fühlereingang BX 4";
const char STR5934[] PROGMEM = "Fühlereingang BX5";
const char STR5941[] PROGMEM = "Fühlereingang BX21";
const char STR5942[] PROGMEM = "Fühlereingang BX22";
const char STR5950[] PROGMEM = "Funktion Eingang H1";
const char STR5951[] PROGMEM = "Wirksinn Kontakt H1";
const char STR5952[] PROGMEM = "Minimaler Vorlaufsollwert H1";
const char STR5953[] PROGMEM = "Spannungswert 1 H1";
const char STR5954[] PROGMEM = "Wärmeanforderung 10V H1";
const char STR5954_2[] PROGMEM = "Funktionswert 1 H1";
const char STR5955[] PROGMEM = "Spannungswert 2 H1";
const char STR5956[] PROGMEM = "Druckwert 3.5V H1";
const char STR5956_2[] PROGMEM = "Funktionswert 2 H1";
const char STR5957_2[] PROGMEM = "BA-Umschaltung HK\'s+TWW";
#define STR5957_3 STR5950
const char STR5960_2[] PROGMEM = "Funktion Eingang H2";
const char STR5961_2[] PROGMEM = "Wirksinn Kontakt H2";
const char STR5962_2[] PROGMEM = "Minimaler Vorlaufsollwert H2";
const char STR5963_2[] PROGMEM = "Spannungswert 1 H2";
const char STR5964_2[] PROGMEM = "Temperaturwert 10V H2";
const char STR5957[] PROGMEM = "Modemfunktion";
const char STR5960[] PROGMEM = "Funktion Eingang H3";
const char STR5961[] PROGMEM = "Wirksinn Kontakt H3";
const char STR5962[] PROGMEM = "Minimaler Vorlaufsollwert H3";
const char STR5963[] PROGMEM = "Spannungswert 1 H3";
const char STR5964[] PROGMEM = "Wärmeanforderung 10V H3";
const char STR5965[] PROGMEM = "Spannungswert 2 H3";
const char STR5966[] PROGMEM = "Druckwert 3.5V H2";
const char STR5970[] PROGMEM = "Konfig Raumthermostat 1";
const char STR5970_2[] PROGMEM = "Funktion Eingang H4";
const char STR5971[] PROGMEM = "Konfig Raumthermostat 2";
const char STR5971_2[] PROGMEM = "Wirksinn Kontakt H4";
const char STR5973[] PROGMEM = "Funktion Eingang RelCl";
const char STR5975[] PROGMEM = "Ext. Vorlaufsollwert Maximum";
const char STR5976[] PROGMEM = "Ext. Leistungsvorg. Schwelle";
const char STR5977[] PROGMEM = "Funktion Eingang H5";
const char STR5978[] PROGMEM = "Funktion Eingang SolCl";
const char STR5978_2[] PROGMEM = "Wirksinn Eingang H5";
const char STR5980[] PROGMEM = "Funktion Eingang EX1";
const char STR5981[] PROGMEM = "Wirksinn Eingang EX1";
const char STR5982[] PROGMEM = "Funktion Eingang EX2";
const char STR5983[] PROGMEM = "Wirksinn Eingang EX2";
const char STR5984[] PROGMEM = "Funktion Eingang EX3";
const char STR5985[] PROGMEM = "Wirksinn Eingang EX3";
const char STR5986[] PROGMEM = "Funktion Eingang EX4";
const char STR5987[] PROGMEM = "Wirksinn Eingang EX4";
const char STR5988[] PROGMEM = "Funktion Eingang EX5";
const char STR5989[] PROGMEM = "Wirksinn Eingang EX5";
const char STR5990[] PROGMEM = "Funktion Eingang EX6";
const char STR5992[] PROGMEM = "Funktion Eingang EX7";
const char STR6014[] PROGMEM = "Funktion Mischergruppe 1";
const char STR6015[] PROGMEM = "Funktion Mischergruppe 2";
const char STR6020[] PROGMEM = "Funktion Erweiterungsmodul 1";
const char STR6021[] PROGMEM = "Funktion Erweiterungsmodul 2";
const char STR6030[] PROGMEM = "Relaisausgang QX21 Modul 1";
const char STR6031[] PROGMEM = "Relaisausgang QX22 Modul 1";
const char STR6032[] PROGMEM = "Relaisausgang QX23 Modul 1";
// const char STR6033[] PROGMEM = "Relaisausgang QX21 Modul 2";
// const char STR6034[] PROGMEM = "Relaisausgang QX22 Modul 2";
// const char STR6035[] PROGMEM = "Relaisausgang QX23 Modul 2";
const char STR6040[] PROGMEM = "Fühlereingang BX21 Modul 1";
const char STR6041[] PROGMEM = "Fühlereingang BX22 Modul 1";
const char STR6042[] PROGMEM = "Fühlereingang BX21 Modul 2";
const char STR6043[] PROGMEM = "Fühlereingang BX22 Modul 2";
const char STR6046[] PROGMEM = "Funktion Eingang H2";
const char STR6047[] PROGMEM = "Wirksinn Kontakt H2";
const char STR6048[] PROGMEM = "Minimaler Vorlaufsollwert H2";
const char STR6048_2[] PROGMEM = "Funktionswert Kontakt H2";
const char STR6049[] PROGMEM = "Spannungswert 1 H2";
const char STR6050[] PROGMEM = "Temperaturwert 10V H2";
const char STR6050_2[] PROGMEM = "Funktionswert 1 H2";
const char STR6051[] PROGMEM = "Spannungswert 2 H2";
const char STR6052[] PROGMEM = "Funktionswert 2 H2";
const char STR6070[] PROGMEM = "Funktion Ausgang UX";
const char STR6071[] PROGMEM = "Signallogik Ausgang UX";
const char STR6072[] PROGMEM = "Signal Ausgang UX";
const char STR6075[] PROGMEM = "Temperaturwert 10V UX";
const char STR6085[] PROGMEM = "PWM-Ausgang P1";
const char STR6089[] PROGMEM = "Mod Pumpe Drehzahlstufen";
const char STR6092[] PROGMEM = "Mod Pumpe PWM";
const char STR6097[] PROGMEM = "Fühlertyp Kollektor";
const char STR6098[] PROGMEM = "Korrektur Kollektorfühler";
const char STR6099[] PROGMEM = "Korrektur Kollektorfühler 2";
const char STR6100[] PROGMEM = "Korrektur Aussenfühler";
const char STR6101[] PROGMEM = "Fühlertyp Abgastemperatur";
const char STR6102[] PROGMEM = "Korrektur Abgastemp'fühler";
const char STR6110[] PROGMEM = "Zeitkonstante Gebäude";
const char STR6112[] PROGMEM = "Gradient Raummodell";
const char STR6116[] PROGMEM = "Zeitkonstante Sollw’führung";
const char STR6117[] PROGMEM = "Zentrale Sollwertfuehrung";
const char STR6118[] PROGMEM = "Sollwertabfall Verzögerung";
const char STR6120[] PROGMEM = "Anlagenfrostschutz";
const char STR6127[] PROGMEM = "Pumpen/Ventilkick Dauer";
const char STR6128[] PROGMEM = "Wärm'anfo unter Außentemp";
const char STR6129[] PROGMEM = "Wärm'anfo über Außentemp";
const char STR6130[] PROGMEM = "H1 mit Pufferspeicher";
const char STR6131[] PROGMEM = "Wärm'anfo bei Ökobetrieb";
const char STR6134[] PROGMEM = "H2 mit Pufferspeicher";
const char STR6135[] PROGMEM = "Luftentfeuchter";
const char STR6136[] PROGMEM = "Luftentfeuchter Freigabe";
const char STR6137[] PROGMEM = "Luftentfeuchter r. F. EIN";
const char STR6138[] PROGMEM = "Luftentfeuchter r. F. SD";
const char STR6140[] PROGMEM = "Wasserdruck Maximum";
const char STR6141[] PROGMEM = "Wasserdruck Minimum";
const char STR6142[] PROGMEM = "Wasserdruck kritisch Min";
const char STR6150[] PROGMEM = "Wasserdruck 2 Maximum";
const char STR6151[] PROGMEM = "Wasserdruck 2 Minimum";
const char STR6152[] PROGMEM = "Wasserdruck 2 kritisch Min";
const char STR6180[] PROGMEM = "Wasserdruck 3 Maximum";
const char STR6181[] PROGMEM = "Wasserdruck 3 Minimum";
const char STR6182[] PROGMEM = "Wasserdruck 3 kritisch Min";
const char STR6200[] PROGMEM = "Fühler Speichern";
const char STR6201[] PROGMEM = "Fühler löschen";
const char STR6204[] PROGMEM = "Parameter speichern";
const char STR6205[] PROGMEM = "Parameter zurücksetzen";
const char STR6212[] PROGMEM = "Kontrollnummer Erzeuger 1";
const char STR6213[] PROGMEM = "Kontrollnummer Erzeuger 2";
const char STR6215[] PROGMEM = "Kontrollnummer Speicher";
const char STR6217[] PROGMEM = "Kontrollnummer Heizkreise";
const char STR6220[] PROGMEM = "Software-Version";
const char STR6221[] PROGMEM = "Entwicklungs-Index";
const char STR6222[] PROGMEM = "Gerätebetriebsstunden";
const char STR6223[] PROGMEM = "Bisher unbekannte Geräteabfrage";
const char STR6224[] PROGMEM = "Geräte-Identifikation";
const char STR6225[] PROGMEM = "Gerätefamilie";
const char STR6226[] PROGMEM = "Gerätevariante";
const char STR6227[] PROGMEM = "Objektverzeichnis-Version";
const char STR6229[] PROGMEM = "Hersteller-ID (letzten vier Bytes)";
const char STR6230[] PROGMEM = "KonfigRg0 Bit 0-7";
const char STR6230_2[] PROGMEM = "Konfiguration - Info 1 OEM";
const char STR6231[] PROGMEM = "Konfiguration - Info 2 OEM";
const char STR6232[] PROGMEM = "Zugangscode Inbetriebnahme?";
const char STR6233[] PROGMEM = "Zugangscode Fachmannebene ?";
const char STR6234[] PROGMEM = "Zugangscode OEM?";
const char STR6235[] PROGMEM = "Zugangscode OEM2?";
const char STR6240[] PROGMEM = "KonfigRg1 Bit 0-7";
const char STR6250[] PROGMEM = "KonfigRg2 Bit 0-7";
const char STR6260[] PROGMEM = "KonfigRg3 Bit 0-7";
const char STR6270[] PROGMEM = "KonfigRg4 Bit 0-7";
const char STR6270_2[] PROGMEM = "Überhitzschutztemperatur";
const char STR6271[] PROGMEM = "Überhitzschutz Schaltdiff";
const char STR6272[] PROGMEM = "Überhitzschutzfühler";
const char STR6273[] PROGMEM = "Überhitzschutz Dauer Min.";
const char STR6280[] PROGMEM = "KonfigRg5 Bit 0-7";
const char STR6290[] PROGMEM = "KonfigRg6 Bit 0-7";
const char STR6300[] PROGMEM = "KonfigRg7 Bit 0-7";
const char STR6310[] PROGMEM = "KonfigRg8 Bit 0-7";
const char STR6330[] PROGMEM = "KonfigRg10 Bit 0-7";
const char STR6375[] PROGMEM = "Relaisausgang QX35";  //FUJITSU
const char STR6420[] PROGMEM = "Funktion Eingang H33";  //FUJITSU
const char STR6421[] PROGMEM = "Wirksinn Kontakt H33";  //FUJITSU

const char STR6486[] PROGMEM = "Teilschema Heizkreis 1";
const char STR6487[] PROGMEM = "Teilschema Kühlkreis 1";
const char STR6488[] PROGMEM = "Teilschema Heizkreis 2";
const char STR6489[] PROGMEM = "Teilschema Heizkreis 3/P";
const char STR6490[] PROGMEM = "Teilschema Trinkwasserspeicher";
const char STR6491[] PROGMEM = "Teilschema Umformer";
const char STR6492[] PROGMEM = "Teilschema H1";
const char STR6493[] PROGMEM = "Teilschema H2";
const char STR6494[] PROGMEM = "Teilschema Feststoffkessel";
const char STR6495[] PROGMEM = "Teilschema Oel-/Gasheizkessel";
const char STR6496[] PROGMEM = "Teilschema Schwimmbad";
const char STR6497[] PROGMEM = "Teilschema Trinkwasser Durchlauferhitzer";
const char STR6498[] PROGMEM = "Teilschema Sonnenkollektor";


// LPB-System
const char STR6600[] PROGMEM = "Geräteadresse";
const char STR6601[] PROGMEM = "Segmentadresse";
const char STR6604[] PROGMEM = "Busspeisung Funktion";
const char STR6605[] PROGMEM = "Busspeisung Status";
const char STR6606[] PROGMEM = "LPB-Konfig. 0";
const char STR6610[] PROGMEM = "Anzeige Systemmeldungen";
const char STR6612[] PROGMEM = "Alarmverzögerung";
const char STR6620[] PROGMEM = "Wirkbereich Umschaltungen";
const char STR6621[] PROGMEM = "Sommerumschaltung";
const char STR6623[] PROGMEM = "Betriebsartumschaltung";
const char STR6624[] PROGMEM = "Manuelle Erzeugersperre";
const char STR6625[] PROGMEM = "Trinkwasserzuordnung";
const char STR6627[] PROGMEM = "Kälteanforderung";
const char STR6630[] PROGMEM = "Kaskadenmaster";
const char STR6631[] PROGMEM = "Externe Erzeuger bei Ökobetrieb";
const char STR6632[] PROGMEM = "TA'grenze ext Erz beachten";
const char STR6640[] PROGMEM = "Uhrbetrieb";
const char STR6650[] PROGMEM = "Aussentemperatur Lieferant";
const char STR6699[] PROGMEM = "Software Version Einschub";

// Fehler
const char STR6705[] PROGMEM = "SW Diagnosecode";
const char STR6706[] PROGMEM = "FA Phase Störstellung";
const char STR6710[] PROGMEM = "Reset Alarmrelais";
const char STR6711[] PROGMEM = "Reset Wärmepumpe";
const char STR6740[] PROGMEM = "Vorlauftemperatur 1 Alarm";
const char STR6741[] PROGMEM = "Vorlauftemperatur 2 Alarm";
const char STR6742[] PROGMEM = "Vorlauftemperatur 3 Alarm";
const char STR6743[] PROGMEM = "Kesseltemperatur Alarm";
const char STR6745[] PROGMEM = "Trinkwasserladung Alarm";
const char STR6746[] PROGMEM = "Vorlauftemp Kühlen 1 Alarm";
const char STR6747[] PROGMEM = "Vorlauftemp Kühlen 2 Alarm";

// THISION Fehlerparameter
const char STR6800_2[] PROGMEM = "Historie 1";
const char STR6801_2[] PROGMEM = "Historie 1 Fehlermeldung";
const char STR6805_2[] PROGMEM = "SW Diagnosecode 1";
const char STR6806_2[] PROGMEM = "FA Phase 1";
const char STR6810_2[] PROGMEM = "Historie 2";
const char STR6811_2[] PROGMEM = "Fehlercode 2";
const char STR6813_2[] PROGMEM = "Historie 2 Fehlermeldung";
const char STR6815_2[] PROGMEM = "SW Diagnosecode 2";
const char STR6816_2[] PROGMEM = "FA Phase 2";
const char STR6820_2[] PROGMEM = "Historie 3";
const char STR6821[] PROGMEM = "Fehlercode 3";
const char STR6823_2[] PROGMEM = "Historie 3 Fehlermeldung";
const char STR6825[] PROGMEM = "SW Diagnosecode 3";
const char STR6826[] PROGMEM = "FA Phase 3";
const char STR6830[] PROGMEM = "Historie 4";
const char STR6831[] PROGMEM = "Fehlercode 4";
const char STR6833_2[] PROGMEM = "Historie 4 Fehlermeldung";
const char STR6835[] PROGMEM = "SW Diagnosecode 4";
const char STR6836[] PROGMEM = "FA Phase 4";
const char STR6840_2[] PROGMEM = "Historie 5";
const char STR6843_2[] PROGMEM = "Historie 5 Fehlermeldung";
const char STR6845[] PROGMEM = "SW Diagnosecode 5";
const char STR6846[] PROGMEM = "FA Phase 5";
const char STR6855[] PROGMEM = "SW Diagnosecode 6";
const char STR6856[] PROGMEM = "FA Phase 6";
const char STR6865[] PROGMEM = "SW Diagnosecode 7";
const char STR6866[] PROGMEM = "FA Phase 7";
const char STR6875[] PROGMEM = "SW Diagnosecode 8";
const char STR6876[] PROGMEM = "FA Phase 8";
const char STR6885[] PROGMEM = "SW Diagnosecode 9";
const char STR6886[] PROGMEM = "FA Phase 9";
const char STR6895[] PROGMEM = "SW Diagnosecode 10";
const char STR6896[] PROGMEM = "FA Phase 10";
const char STR6905[] PROGMEM = "SW Diagnosecode 11";
const char STR6906[] PROGMEM = "FA Phase 11";
const char STR6915[] PROGMEM = "SW Diagnosecode 12";
const char STR6916[] PROGMEM = "FA Phase 12";
const char STR6925[] PROGMEM = "SW Diagnosecode 13";
const char STR6926[] PROGMEM = "FA Phase 13";
const char STR6935[] PROGMEM = "SW Diagnosecode 14";
const char STR6936[] PROGMEM = "FA Phase 14";
const char STR6945[] PROGMEM = "SW Diagnosecode 15";
const char STR6946[] PROGMEM = "FA Phase 15";
const char STR6955[] PROGMEM = "SW Diagnosecode 16";
const char STR6956[] PROGMEM = "FA Phase 16";
const char STR6965[] PROGMEM = "SW Diagnosecode 17";
const char STR6966[] PROGMEM = "FA Phase 17";
const char STR6975[] PROGMEM = "SW Diagnosecode 18";
const char STR6976[] PROGMEM = "FA Phase 18";
const char STR6985[] PROGMEM = "SW Diagnosecode 19";
const char STR6986[] PROGMEM = "FA Phase 19";
const char STR6995[] PROGMEM = "SW Diagnosecode 20";
const char STR6996[] PROGMEM = "FA Phase 20";

#define STR6803_2 STR6801_2
#define STR6813_2 STR6810_2
#define STR6823 STR6820_2
#define STR6833 STR6830
#define STR6840 STR6808
#define STR6843 STR6840
#define STR6841 STR6809
#define STR6850 STR6810
#define STR6851 STR6811
#define STR6860 STR6812
#define STR6861 STR6813
#define STR6870 STR6814
#define STR6871 STR6815
#define STR6880 STR6816
#define STR6881 STR6817
#define STR6890 STR6818
#define STR6891 STR6819

// übrige Fehlerparameter
const char STR6800[] PROGMEM = "Historie 1 Datum/Zeit";
const char STR6801[] PROGMEM = "Historie 1 Fehlercode";
const char STR6802[] PROGMEM = "Historie 2 Datum/Zeit";
const char STR6803[] PROGMEM = "Historie 2 Fehlercode";
const char STR6804[] PROGMEM = "Historie 3 Datum/Zeit";
const char STR6805[] PROGMEM = "Historie 3 Fehlercode";
const char STR6806[] PROGMEM = "Historie 4 Datum/Zeit";
const char STR6807[] PROGMEM = "Historie 4 Fehlercode";
const char STR6808[] PROGMEM = "Historie 5 Datum/Zeit";
const char STR6809[] PROGMEM = "Historie 5 Fehlercode";
const char STR6810[] PROGMEM = "Historie 6 Datum/Zeit";
const char STR6811[] PROGMEM = "Historie 6 Fehlercode";
const char STR6812[] PROGMEM = "Historie 7 Datum/Zeit";
const char STR6813[] PROGMEM = "Historie 7 Fehlercode";
const char STR6814[] PROGMEM = "Historie 8 Datum/Zeit";
const char STR6815[] PROGMEM = "Historie 8 Fehlercode";
const char STR6816[] PROGMEM = "Historie 9 Datum/Zeit";
const char STR6817[] PROGMEM = "Historie 9 Fehlercode";
const char STR6818[] PROGMEM = "Historie 10 Datum/Zeit";
const char STR6819[] PROGMEM = "Historie 10 Fehlercode";
const char STR6900[] PROGMEM = "Historie 11 Datum/Zeit";
const char STR6901[] PROGMEM = "Historie 11 Fehlercode";
const char STR6910[] PROGMEM = "Historie 12 Datum/Zeit";
const char STR6911[] PROGMEM = "Historie 12 Fehlercode";
const char STR6920[] PROGMEM = "Historie 13 Datum/Zeit";
const char STR6921[] PROGMEM = "Historie 13 Fehlercode";
const char STR6930[] PROGMEM = "Historie 14 Datum/Zeit";
const char STR6931[] PROGMEM = "Historie 14 Fehlercode";
const char STR6940[] PROGMEM = "Historie 15 Datum/Zeit";
const char STR6941[] PROGMEM = "Historie 15 Fehlercode";
const char STR6950[] PROGMEM = "Historie 16 Datum/Zeit";
const char STR6951[] PROGMEM = "Historie 16 Fehlercode";
const char STR6960[] PROGMEM = "Historie 17 Datum/Zeit";
const char STR6961[] PROGMEM = "Historie 17 Fehlercode";
const char STR6970[] PROGMEM = "Historie 18 Datum/Zeit";
const char STR6971[] PROGMEM = "Historie 18 Fehlercode";
const char STR6980[] PROGMEM = "Historie 19 Datum/Zeit";
const char STR6981[] PROGMEM = "Historie 19 Fehlercode";
const char STR6990[] PROGMEM = "Historie 20 Datum/Zeit";
const char STR6991[] PROGMEM = "Historie 20 Fehlercode";
const char STR6820[] PROGMEM = "Reset Historie";

// Wartung / Sonderbetrieb
const char STR7001[] PROGMEM = "Meldung";
const char STR7007[] PROGMEM = "Anzeige Meldungen";
const char STR7010[] PROGMEM = "Quittierung Meldung";
const char STR7011[] PROGMEM = "Repetitionszeit Meldung";
const char STR7012[] PROGMEM = "Reset Meldungen 1-6";
const char STR7040[] PROGMEM = "Brennerstunden Intervall";
const char STR7041[] PROGMEM = "Brennerstunden seit Wartung";
const char STR7042[] PROGMEM = "Brennerstarts Intervall";
const char STR7043[] PROGMEM = "Brennerstarts seit Wartung";
const char STR7044[] PROGMEM = "Wartungsintervall";
const char STR7045[] PROGMEM = "Zeit seit Wartung";
const char STR7050[] PROGMEM = "Gebläsedrehzahl Ion Strom";
const char STR7051[] PROGMEM = "Meldung Ion Strom";
const char STR7053[] PROGMEM = "Abgastemperaturgrenze";
const char STR7054[] PROGMEM = "Verzögerung Abgasmeldung";
const char STR7056[] PROGMEM = "TWW Verbrühungsgefahr";
const char STR7070[] PROGMEM = "WP Zeitintervall";
const char STR7071[] PROGMEM = "WP Zeit seit Wartung";
const char STR7072[] PROGMEM = "Max Starts Verd1 / Betr’Std";
const char STR7073[] PROGMEM = "Akt Starts Verd1 / Betr’Std";
const char STR7074[] PROGMEM = "Max Starts Verd2 / Betr’Std";
const char STR7075[] PROGMEM = "Akt Starts Verd2 / Betr’Std";
const char STR7076[] PROGMEM = "Spreiz Kondens Max / Wo";
const char STR7077[] PROGMEM = "Akt Spreiz Kondens Max / Wo";
const char STR7078[] PROGMEM = "Spreiz Kondens Min / Wo";
const char STR7079[] PROGMEM = "Akt Spreiz Kondens Min / Wo";
const char STR7080[] PROGMEM = "Spreiz Verdampfer Max / Wo";
const char STR7081[] PROGMEM = "Akt Spreiz Verdampfer Max / Wo";
const char STR7082[] PROGMEM = "Spreiz Verdampfer Min / Wo";
const char STR7083[] PROGMEM = "Akt Spreiz Verdampfer Min / Wo";
const char STR7090[] PROGMEM = "TWW Speicher Zeitintervall";
const char STR7091[] PROGMEM = "TWW Speicher seit Wartung";
const char STR7092[] PROGMEM = "TWW Ladetemp WP Minimum";
const char STR7093[] PROGMEM = "Akt TWW Ladetemperatur WP";
const char STR7119[] PROGMEM = "Ökofunktion";
const char STR7120[] PROGMEM = "Ökobetrieb";
const char STR7130[] PROGMEM = "Schornsteinfegerfunktion";
const char STR7131[] PROGMEM = "Schornsteinfegerfunktion Brennerleistung";
const char STR7140[] PROGMEM = "Handbetrieb";
const char STR7141[] PROGMEM = "Notbetrieb";
const char STR7142[] PROGMEM = "Notbetrieb Funktionsstart";
const char STR7143[] PROGMEM = "Reglerstoppfunktion";
const char STR7145[] PROGMEM = "Reglerstopp Sollwert";
const char STR7146[] PROGMEM = "Entlüftungsfunktion";
const char STR7147[] PROGMEM = "Entlüftungsart";
const char STR7150[] PROGMEM = "Simulation Aussentemperatur";
const char STR7152[] PROGMEM = "Abtauen auslösen";
const char STR7160[] PROGMEM = "Reset Begrenzungszeiten";
const char STR7166[] PROGMEM = "Inbetriebnahmefunktion";
const char STR7170[] PROGMEM = "Telefon Kundendienst";
const char STR7181[] PROGMEM = "Telefon Zuständigkeit 1";
const char STR7183[] PROGMEM = "Telefon Zuständigkeit 2";
const char STR7250[] PROGMEM = "Pstick Pos";
const char STR7251[] PROGMEM = "Pstick Bez Datensatz";
const char STR7252[] PROGMEM = "Pstick Befehl";
const char STR7253[] PROGMEM = "Pstick Fortschritt";

// Konfiguration Erweit'module
const char STR7311[] PROGMEM = "Funktion Eingang H2 Modul 1";
const char STR7376[] PROGMEM = "Relaisausgang QX21 Modul 2";
const char STR7377[] PROGMEM = "Relaisausgang QX22 Modul 2";
const char STR7378[] PROGMEM = "Relaisausgang QX23 Modul 2";
const char STR7386[] PROGMEM = "Funktion Eingang H2 Modul 2";
const char STR7387[] PROGMEM = "Wirksinn Kontakt H2 Modul 2";
const char STR7396[] PROGMEM = "Funktion Eing' H21 Modul 2";
const char STR7399[] PROGMEM = "Eingangswert 1 H21 Modul 2";
const char STR7400[] PROGMEM = "Funkt'wert 1 H21 Modul 2";
const char STR7401[] PROGMEM = "Eingangswert 2 H21 Modul 2";
const char STR7402[] PROGMEM = "Funkt'wert 2 H21 Modul 2";
const char STR7423[] PROGMEM = "Fkt Ausg' UX21 Modul 2";
const char STR7425[] PROGMEM = "Signal Ausg' UX21 Modul 2";
const char STR7430[] PROGMEM = "Fkt Ausg' UX22 Modul 2";
const char STR7432[] PROGMEM = "Signal Ausg' UX22 Modul 2";

// Ein-/Ausgangstest
const char STR7700[] PROGMEM = "Relaistest";
const char STR7705[] PROGMEM = "Mod'sollwert QX3 Relaistest";
const char STR7708[] PROGMEM = "Modulationssignal QX3";
const char STR7710[] PROGMEM = "Ausgangstest UX1";
const char STR7711[] PROGMEM = "Spannungssignal UX1";
const char STR7712[] PROGMEM = "PWM-Signal UX1"; //FUJITSU
const char STR7713[] PROGMEM = "Ausgangstest P1";
const char STR7714[] PROGMEM = "PWM-Signal P1";
const char STR7716[] PROGMEM = "Ausgangstest UX2";  //FUJITSU
const char STR7719[] PROGMEM = "PWM-Signal UX2"; //FUJITSU
const char STR7720[] PROGMEM = "Ausgangstest Digital";
const char STR7721[] PROGMEM = "Digitalausgang D01";
const char STR7722[] PROGMEM = "Kühlbetrieb D2"; //FUJITSU
const char STR7723[] PROGMEM = "Wärmepumpe D3"; //FUJITSU
const char STR7724[] PROGMEM = "Ausgangstest UX3"; //FUJITSU
const char STR7725[] PROGMEM = "Spannungssignal U4 (Ux3)"; //FUJITSU
const char STR7730[] PROGMEM = "Aussentemperatur B9";
const char STR7732[] PROGMEM = "Vorlauftemperatur B1";
const char STR7734[] PROGMEM = "Vorlauftemperatur B12";
const char STR7750[] PROGMEM = "Trinkwassertemperatur B3";
const char STR7760[] PROGMEM = "Kesseltemperatur B2";
const char STR7770[] PROGMEM = "Vorlauftemperatur WP B21";
const char STR7771[] PROGMEM = "Rücklauftemperatur WP B71";
const char STR7772[] PROGMEM = "Heissgastemperatur B81";
const char STR7775[] PROGMEM = "Quelle Eintrittstemp B91";
const char STR7777[] PROGMEM = "Fühlertemperatur B92, B84";
const char STR7784[] PROGMEM = "Ausgangstest UX21 Modul 2";
const char STR7785[] PROGMEM = "Ausg'signal UX21 Modul 2";
const char STR7785_2[] PROGMEM = "Ausg'signal UX21 Modul 2 PWM %";
const char STR7786[] PROGMEM = "Ausgangstest UX22 Modul 2";
const char STR7787[] PROGMEM = "Ausg'signal UX22 Modul 2";
const char STR7787_2[] PROGMEM = "Ausg'signal UX22 Modul 2 PWM %";
const char STR7809[] PROGMEM = "Fühlertemperatur BX6";  //FUJITSU
const char STR7820[] PROGMEM = "Fühlertemperatur BX1";
const char STR7821[] PROGMEM = "Fühlertemperatur BX2";
const char STR7822[] PROGMEM = "Fühlertemperatur BX3";
const char STR7823[] PROGMEM = "Fühlertemperatur BX4";
const char STR7824[] PROGMEM = "Fühlertemperatur BX5";
const char STR7830[] PROGMEM = "Fühlertemp. BX21 Modul 1";
const char STR7831[] PROGMEM = "Fühlertemp. BX22 Modul 1";
const char STR7832[] PROGMEM = "Fühlertemp. BX21 Modul 2";
const char STR7833[] PROGMEM = "Fühlertemp. BX22 Modul 2";
const char STR7840[] PROGMEM = "Spannungssignal H1";
const char STR7841[] PROGMEM = "Kontaktzustand H1";
const char STR7844[] PROGMEM = "Eingangssignal H1";
const char STR7845[] PROGMEM = "Spannungssignal H2";
const char STR7846[] PROGMEM = "Kontaktzustand H2";
const char STR7847[] PROGMEM = "Zustand Kontakt H2, Modul 2";
const char STR7848[] PROGMEM = "Kontaktzustand H2 modul 2";
const char STR7849[] PROGMEM = "Kontaktzustand H2 modul 2 - Parameter";
const char STR7854[] PROGMEM = "Spannungssignal H3";
const char STR7855[] PROGMEM = "Kontaktzustand H3";
const char STR7858[] PROGMEM = "Eingangssignal H3";
const char STR7860[] PROGMEM = "Kontaktzustand H4";
const char STR7865[] PROGMEM = "Kontaktzustand H5";
const char STR7870[] PROGMEM = "Brennerstörung S3";
const char STR7872[] PROGMEM = "Kontaktzustand H6";
const char STR7881[] PROGMEM = "1. Brennerstufe E1";
const char STR7884[] PROGMEM = "STB Fehlermeldung L1";
const char STR7889[] PROGMEM = "Niederdruckwächter E9";
const char STR7890[] PROGMEM = "Hochdruckwächter E10";
const char STR7891[] PROGMEM = "Wickl’schutz Verdicht 1 E11";
const char STR7911[] PROGMEM = "Eingang EX1";
const char STR7912[] PROGMEM = "Eingang EX2";
const char STR7913[] PROGMEM = "Eingang EX3";
const char STR7914[] PROGMEM = "Eingang EX4";
const char STR7915[] PROGMEM = "Eingang EX5";
const char STR7916[] PROGMEM = "Eingang EX6";
const char STR7917[] PROGMEM = "Eingang EX7";
const char STR7950[] PROGMEM = "Eingang EX01 Modul 1";
const char STR7951[] PROGMEM = "Eingang EX01 Modul 2";
const char STR7952[] PROGMEM = "Eingang EX01 Modul 3";
const char STR7973[] PROGMEM = "Fühlertemperatur BX31";  //FUJITSU
const char STR7974[] PROGMEM = "Fühlertemperatur BX32";  //FUJITSU
const char STR7975[] PROGMEM = "Fühlertemperatur BX33";  //FUJITSU
const char STR7976[] PROGMEM = "Fühlertemperatur BX34";  //FUJITSU
const char STR7977[] PROGMEM = "Fühlertemperatur BX35";  //FUJITSU
const char STR7978[] PROGMEM = "Fühlertemperatur BX36";  //FUJITSU
const char STR7996[] PROGMEM = "Zustand Kontakt H33";  //FUJITSU
const char STR7999[] PROGMEM = "Eingangssignal H33";  //FUJITSU

// Status
const char STR8000[] PROGMEM = "Status Heizkreis 1";
const char STR8001[] PROGMEM = "Status Heizkreis 2";
const char STR8002[] PROGMEM = "Status Heizkreis P";
const char STR8003[] PROGMEM = "Status Trinkwasser";
const char STR8004[] PROGMEM = "Status Kühlkreis 1";
const char STR8005[] PROGMEM = "Status Kessel";
const char STR8006[] PROGMEM = "Status Wärmepumpe";
const char STR8007[] PROGMEM = "Status Solar";
const char STR8008[] PROGMEM = "Status Feststoffkessel";
const char STR8009[] PROGMEM = " Statut - pompe off => 8, auto mode => 2";//XXX Status Brenner
const char STR8010[] PROGMEM = "Status Pufferspeicher";
const char STR8011[] PROGMEM = "Status Schwimmbad";
const char STR8022[] PROGMEM = "Status Zusatzerzeuger";
const char STR8023[] PROGMEM = "Status Sitherm Pro";
const char STR8025[] PROGMEM = "Status Kühlkreis 2";
const char STR8050[] PROGMEM = "Zeitstempel Statushistorie 1";
const char STR8051[] PROGMEM = "Statuscode Statushistorie 1";
const char STR8052[] PROGMEM = "Zeitstempel Statushistorie 2";
const char STR8053[] PROGMEM = "Statuscode Statushistorie 2";
const char STR8054[] PROGMEM = "Zeitstempel Statushistorie 3";
const char STR8055[] PROGMEM = "Statuscode Statushistorie 3";
const char STR8056[] PROGMEM = "Zeitstempel Statushistorie 4";
const char STR8057[] PROGMEM = "Statuscode Statushistorie 4";
const char STR8058[] PROGMEM = "Zeitstempel Statushistorie 5";
const char STR8059[] PROGMEM = "Statuscode Statushistorie 5";
const char STR8060[] PROGMEM = "Zeitstempel Statushistorie 6";
const char STR8061[] PROGMEM = "Statuscode Statushistorie 6";
const char STR8062[] PROGMEM = "Zeitstempel Statushistorie 7";
const char STR8063[] PROGMEM = "Statuscode Statushistorie 7";
const char STR8064[] PROGMEM = "Zeitstempel Statushistorie 8";
const char STR8065[] PROGMEM = "Statuscode Statushistorie 8";
const char STR8066[] PROGMEM = "Zeitstempel Statushistorie 9";
const char STR8067[] PROGMEM = "Statuscode Statushistorie 10";
const char STR8068[] PROGMEM = "Zeitstempel Statushistorie 10";
const char STR8069[] PROGMEM = "Statuscode Statushistorie 10";

const char STR8099[] PROGMEM = "Status im Hauptdisplay";

// Diagnose Kaskade
const char STR8100[] PROGMEM = "Priorität / Status Erzeuger 1";
const char STR8102[] PROGMEM = "Priorität / Status Erzeuger 2";
const char STR8104[] PROGMEM = "Priorität / Status Erzeuger 3";
const char STR8106[] PROGMEM = "Priorität / Status Erzeuger 4";
const char STR8108[] PROGMEM = "Priorität / Status Erzeuger 5";
const char STR8110[] PROGMEM = "Priorität / Status Erzeuger 6";
const char STR8112[] PROGMEM = "Priorität / Status Erzeuger 7";
const char STR8114[] PROGMEM = "Priorität / Status Erzeuger 8";
const char STR8116[] PROGMEM = "Priorität / Status Erzeuger 9";
const char STR8118[] PROGMEM = "Priorität / Status Erzeuger 10";
const char STR8120[] PROGMEM = "Priorität / Status Erzeuger 11";
const char STR8122[] PROGMEM = "Priorität / Status Erzeuger 12";
const char STR8124[] PROGMEM = "Priorität / Status Erzeuger 13";
const char STR8126[] PROGMEM = "Priorität / Status Erzeuger 14";
const char STR8128[] PROGMEM = "Priorität / Status Erzeuger 15";
const char STR8130[] PROGMEM = "Priorität / Status Erzeuger 16";
const char STR8138[] PROGMEM = "Kaskadenvorlauftemperatur";
const char STR8139[] PROGMEM = "Kaskadenvorlaufsollwert";
const char STR8140[] PROGMEM = "Kaskadenrücklauftemperatur";
const char STR8141[] PROGMEM = "Kaskadenrücklaufsollwert";
const char STR8150[] PROGMEM = "Erz'folge Umschalt aktuell";
const char STR8199[] PROGMEM = "Kaskaden Zustand";

// 8300 Diagnose Erzeuger
const char STR8300[] PROGMEM = "1. Brennerstufe T2";
const char STR8301[] PROGMEM = "2. Brennerstufe T8";
const char STR8302[] PROGMEM = "Zustand Brennerklappe Auf";
const char STR8303[] PROGMEM = "Zustand Brennerklappe Zu";
const char STR8304[] PROGMEM = "Kesselpumpe Q1";
const char STR8308[] PROGMEM = "Drehzahl Kesselpumpe";
const char STR8310[] PROGMEM = "Kesseltemperatur";
const char STR8311[] PROGMEM = "Kesselsollwert";
const char STR8312[] PROGMEM = "Kesselschaltpunkt";
const char STR8313[] PROGMEM = "Regelfühler";
const char STR8314[] PROGMEM = "Kesselrücklauftemperatur Ist";
const char STR8315[] PROGMEM = "Kesselrücklauftemperatur Soll";
const char STR8316[] PROGMEM = "Abgastemperatur Istwert";
const char STR8318[] PROGMEM = "Abgastemperatur Maximum";
const char STR8319[] PROGMEM = "Regeltemperatur";
const char STR8320[] PROGMEM = "Regelsollwert";
const char STR8321[] PROGMEM = "Aktuelle Regeldifferenz";
const char STR8323[] PROGMEM = "Gebläsedrehzahl";
const char STR8324[] PROGMEM = "Brennergebläsesollwert";
const char STR8325[] PROGMEM = "PWM Drehzahlregler (Proz)";
const char STR8325_2[] PROGMEM = "Aktuelle Gebläseansteuerung";
const char STR8326[] PROGMEM = "Brennermodulation";
const char STR8327[] PROGMEM = "Wasserdruck";
const char STR8328[] PROGMEM = "Betriebsanzeige FA";
const char STR8329[] PROGMEM = "Ionisationsstrom";
const char STR8330[] PROGMEM = "Betriebsstunden 1.Stufe";
const char STR8331[] PROGMEM = "Startzähler 1.Stufe";
const char STR8332[] PROGMEM = "Betriebsstunden 2.Stufe";
const char STR8333[] PROGMEM = "Startzähler 2.Stufe";
const char STR8336[] PROGMEM = "Betriebsstunden Brenner";
const char STR8337[] PROGMEM = "Startzähler Brenner";
const char STR8338[] PROGMEM = "Betriebsstunden Heizbetrieb";
const char STR8339[] PROGMEM = "Betriebsstunden TWW";
const char STR8340[] PROGMEM = "Betriebsstunden ext. Wärmeanforderung";
const char STR8378[] PROGMEM = "Gesamt Gasenergie Heizen";
const char STR8379[] PROGMEM = "Gesamt Gasenergie Trinkwasser";
const char STR8380[] PROGMEM = "Gesamt Gasenergie";
const char STR8381[] PROGMEM = "Gasenergie Heizen Reset";
const char STR8382[] PROGMEM = "Gasenergie TWW Reset";
const char STR8383[] PROGMEM = "Gasenergie";
const char STR8390[] PROGMEM = "Aktuelle Phasennummer";
const char STR8395[] PROGMEM = "Wärmeabgabe";
const char STR8396[] PROGMEM = "Wärmeaufnahme Quelle";
const char STR8397[] PROGMEM = "Leistungsaufnahme";
const char STR8398[] PROGMEM = "Leistungszahl";
const char STR8400[] PROGMEM = "Verdichter 1 K1";
const char STR8401[] PROGMEM = "Verdichter 2 K2";
const char STR8402[] PROGMEM = "Elektroeinsatz 1 Vorlauf";
const char STR8403[] PROGMEM = "Elektroeinsatz 2 Vorlauf";
const char STR8404[] PROGMEM = "Quellenpu Q8 / Ventilat K19";
const char STR8405[] PROGMEM = "Drehzahl Quellenpumpe";
const char STR8406[] PROGMEM = "Kondensatorpumpe Q9";
const char STR8407[] PROGMEM = "Drehzahl Kondensatorpumpe";
const char STR8408[] PROGMEM = "Kühlumlenkventil Quelle";
const char STR8410[] PROGMEM = "Rücklauftemperatur WP";
const char STR8411[] PROGMEM = "Sollwert WP";
const char STR8412[] PROGMEM = "Vorlauftemperatur WP";
const char STR8413[] PROGMEM = "Modulation des Kompressors";
const char STR8414[] PROGMEM = "Elektro-Vorlauf Modulation";
const char STR8415[] PROGMEM = "Heissgastemperatur 1";
const char STR8416[] PROGMEM = "Heissgastemperatur Max";
const char STR8417[] PROGMEM = "Heissgastemperatur 2";
const char STR8420[] PROGMEM = "Kältemitteltemperatur flüssig";
const char STR8423[] PROGMEM = "Kondensatortemperatur";
const char STR8425[] PROGMEM = "Temp’spreizung Kondensator";
const char STR8426[] PROGMEM = "Temp’spreizung Verdampfer";
const char STR8427[] PROGMEM = "Quelle Eintrittstemperatur";
const char STR8428[] PROGMEM = "Quelle Eintritt Min";
const char STR8429[] PROGMEM = "Quelle Austrittstemperatur";
const char STR8430[] PROGMEM = "Quelle Austritt Min";
const char STR8431[] PROGMEM = "Quellenzw'kreis Vorlauftemp";
const char STR8434[] PROGMEM = "Sauggastemperatur";
const char STR8435[] PROGMEM = "Verdampfungstemperatur";
const char STR8436[] PROGMEM = "Überhitzung oder Überhitzungssollwert";
// vorheriges könnte auch 1663 sein weil da noch Überhitzungssollwert übermittelt wird
const char STR8437[] PROGMEM = "Expansionsventil"; // kein Funktion
const char STR8438[] PROGMEM = "Magnetventil";
const char STR8440[] PROGMEM = "Rest Stufe 1 Stillst’zeit Min";
const char STR8441[] PROGMEM = "Rest Stufe 2 Stillst’zeit Min";
const char STR8442[] PROGMEM = "Rest Stufe 1 Laufzeit Min";
const char STR8443[] PROGMEM = "Rest Stufe 2 Laufzeit Min";
const char STR8444[] PROGMEM = "Restzeit Begr Quelle TempMin";
const char STR8446[] PROGMEM = "Verdichterfolge";
const char STR8448[] PROGMEM = "Betr'std erw Verdampf'temp";
const char STR8449[] PROGMEM = "Betr'stunden Kältekreis";
const char STR8450[] PROGMEM = "Betr’stunden Verdichter 1";
const char STR8451[] PROGMEM = "Startzähler Verdichter 1";
const char STR8452[] PROGMEM = "Betr’stunden Verdichter 2";
const char STR8453[] PROGMEM = "Startzähler Verdichter 2";
const char STR8454[] PROGMEM = "Sperrdauer WP";
const char STR8455[] PROGMEM = "Zähler Anzahl Sperren WP";
const char STR8456[] PROGMEM = "Betr’stunden Elektro Vorl";
const char STR8457[] PROGMEM = "Startzähler Elektro Vorlauf";
const char STR8458[] PROGMEM = "Status Smart Grid"; // Keine Funktion
const char STR8460[] PROGMEM = "Wärmepumpendurchfluss"; // l/min
const char STR8461[] PROGMEM = "Quellendurchfluss"; // l/min
const char STR8462[] PROGMEM = "Sauggasttemperatur EVI";
const char STR8463[] PROGMEM = "Verdampfungstemperatur EVI";
// Kommt auch noch ein Telegramm 0x593D1779, könnte Verdampfungsdruck E in bar sein oder vertauscht mit dem oben
const char STR8464[] PROGMEM = "Überhitzung EVI";
// Kommt auch noch ein Telegramm 0x593D17AC, könnte Überhitzungssollwert E in °C sein oder vertauscht mit dem oben
const char STR8465[] PROGMEM = "Expansionsventil EVI";
const char STR8466[] PROGMEM = "Magnetventil EVI"; // Keine Funktion
const char STR8467[] PROGMEM = "Mag'ventil Einspritzkapillare"; // Keine Funktion
const char STR8469[] PROGMEM = "Drehzahl Ventilator";
const char STR8470[] PROGMEM = "Ventilator K19";
const char STR8471[] PROGMEM = "Prozessumkehrventil";
const char STR8475[] PROGMEM = "Verdampfertemperatur";
const char STR8477[] PROGMEM = "Temp'diff Abtauen Istwert";
const char STR8478[] PROGMEM = "Temp'diff Abtauen Sollwert";
const char STR8480[] PROGMEM = "Restzeit Abtausperrung";
const char STR8481[] PROGMEM = "Restzeit Zwangsabtauen";
const char STR8482[] PROGMEM = "Restzeit Abtaustabilisierung";
const char STR8485[] PROGMEM = "Anzahl Abtauversuche";
const char STR8487[] PROGMEM = "Status Abtauen WP";
// Diagnose Erzeuger - Solar
const char STR8499[] PROGMEM = "Zustand Kollektorpumpe (Q5)";
const char STR8499_2[] PROGMEM = "Kollektorpumpe 1";
const char STR8501[] PROGMEM = "Solarstellglied Puffer";
const char STR8502[] PROGMEM = "Solarstellglied Schwimmbad";
const char STR8505[] PROGMEM = "Drehzahl Kollektorpumpe 1";
const char STR8506[] PROGMEM = "Drehzahl Solarpump ext.Tau";
const char STR8507[] PROGMEM = "Drehzahl Solarpumpe Puffer";
const char STR8508[] PROGMEM = "Drehzahl Solarpump Sch'bad";
const char STR8510[] PROGMEM = "Kollektortemperatur 1";
const char STR8511[] PROGMEM = "Kollektortemperatur 1 Max";
const char STR8512[] PROGMEM = "Kollektortemperatur 1 Min";
const char STR8513[] PROGMEM = "dT Kollektor 1/TWW";
const char STR8513_2[] PROGMEM = "dT Kollektor 1/Tauscher 1";
const char STR8514[] PROGMEM = "dT Kollektor 1/Puffer";
const char STR8515[] PROGMEM = "dT Kollektor 1/Schwimmbad";
const char STR8519[] PROGMEM = "Solarvorlauftemperatur";
const char STR8520[] PROGMEM = "Solarrücklauftemperatur";
const char STR8521[] PROGMEM = "Solardurchfluss";
const char STR8526[] PROGMEM = "Tagesertrag Solarenergie";
const char STR8527[] PROGMEM = "Gesamtertrag Solarenergie";
const char STR8530[] PROGMEM = "Betr`stunden Solarertrag";
const char STR8531[] PROGMEM = "Betr`stunden Kollektor`überhitz";
const char STR8532[] PROGMEM = "Betr`stunden Kollektorpumpe";
const char STR8543[] PROGMEM = "Drehzahl Kollektorpumpe 2";
const char STR8547[] PROGMEM = "Kollektortemperatur 2";
const char STR8548[] PROGMEM = "Kollektortemperatur 2 Max";
const char STR8549[] PROGMEM = "Kollektortemperatur 2 Min";
const char STR8550[] PROGMEM = "dT Kollektor 2 / TWW";
const char STR8551[] PROGMEM = "dT Kollektor 2 / Puffer";
const char STR8552[] PROGMEM = "dT Kollektor 2 / Schwimmbad";
const char STR8559[] PROGMEM = "Feststoffkesselsollwert"; // !!! TODO: Parameternummer unklar !!!
const char STR8560[] PROGMEM = "Feststoffkesseltemperatur";
const char STR8568[] PROGMEM = "Drehzahl Festst'pumpe";
const char STR8570[] PROGMEM = "Betr'std Feststoffkessel";

// Diagnose Verbraucher
const char STR8700[] PROGMEM = " T° extérieure (sonde B9) #34 #52.3 ";//XXX Aussentemperatur
const char STR8701[] PROGMEM = "Außentemperatur Minimum";
const char STR8702[] PROGMEM = "Außentemperatur Maximum";
const char STR8703[] PROGMEM = "Aussentemperatur gedämpft";
const char STR8704[] PROGMEM = " T° extérieure moyennée ";//XXX Aussentemperatur gemischt
const char STR8705[] PROGMEM = "Aussentemperatur LPB";
const char STR8720[] PROGMEM = "Relative Raumfeuchte";
const char STR8721[] PROGMEM = " T° ambiante (sonde A6) #33 #52.4 ";//XXX Raumtemperatur
const char STR8722[] PROGMEM = "Taupunkttemperatur";
const char STR8730[] PROGMEM = "Heizkreispumpe Q2";
const char STR8731[] PROGMEM = "Heizkreismischer Auf Y1";
const char STR8732[] PROGMEM = "Heizkreismischer Zu Y2";
const char STR8735[] PROGMEM = "Drehzahl Heizkreispumpe 1";
const char STR8740[] PROGMEM = "Raumtemperatur 1";
const char STR8741[] PROGMEM = "Raumsollwert 1";
const char STR8742[] PROGMEM = "Raumtemperatur 1 Modell";
const char STR8743[] PROGMEM = " T° chaudière (sonde B2) #52.0 ";//XXX
const char STR8744[] PROGMEM = " Consigne T° chaudière ";//XXX Vorlaufsollwert 1
const char STR8749[] PROGMEM = "Raumthermostat 1";
const char STR8750[] PROGMEM = "Mod Pumpe Sollwert";
const char STR8751[] PROGMEM = "Kühlkreispumpe Q24";
const char STR8752[] PROGMEM = "Kühlkreismischer Auf Y23";
const char STR8753[] PROGMEM = "Kühlkreismischer Zu Y24";
const char STR8754[] PROGMEM = "Umlenkventil Kühlen Y21";
const char STR8756[] PROGMEM = "Vorlauftemperatur Kühlen 1";
const char STR8757[] PROGMEM = "Vorlaufsollwert Kühlen1";
const char STR8760[] PROGMEM = "Heizkreispumpe 2";
const char STR8761[] PROGMEM = "Heizkreismischer 2 Auf";
const char STR8762[] PROGMEM = "Heizkreismischer 2 Zu";
const char STR8765[] PROGMEM = "Drehzahl Heizkreispumpe 2";
const char STR8770[] PROGMEM = "Raumtemperatur 2";
const char STR8771[] PROGMEM = "Raumsollwert 2";
const char STR8772[] PROGMEM = "Raumtemperatur 2 Modell";
const char STR8773[] PROGMEM = "Vorlauftemperatur 2";
const char STR8774[] PROGMEM = "Vorlaufsollwert 2";
const char STR8779[] PROGMEM = "Raumthermostat 2";
const char STR8790[] PROGMEM = "Heizkreispumpe 3";
const char STR8791[] PROGMEM = "Heizkreismischer P Auf";
const char STR8792[] PROGMEM = "Heizkreismischer P Zu";
const char STR8795[] PROGMEM = "Drehzahl Heizkreispumpe P";
const char STR8800[] PROGMEM = "Raumtemperatur P";
const char STR8801[] PROGMEM = "Raumsollwert P";
const char STR8802[] PROGMEM = "Raumtemperatur P Modell";
const char STR8803[] PROGMEM = "Vorlaufsollwert P";
const char STR8804[] PROGMEM = "Vorlaufsollwert 3";
const char STR8809[] PROGMEM = "Raumthermostat 3";
const char STR8820[] PROGMEM = "Trinkwasserpumpe Q3";
const char STR8821[] PROGMEM = "Elektroeinsatz TWW K6";
const char STR8825[] PROGMEM = "Drehzahl Trinkwasserpumpe";
const char STR8826[] PROGMEM = "Drehzahl TWW Zw'kreispumpe";
const char STR8827[] PROGMEM = "Drehzahl Dl'erhitzerpumpe";
const char STR8830[] PROGMEM = " T° ECS (sonde B3) #52.1 ";//XXX Trinkwassertemperatur 1
const char STR8831[] PROGMEM = "Trinkwassersollwert";
const char STR8832[] PROGMEM = "Trinkwassertemperatur 2";
const char STR8835[] PROGMEM = "TWW Zirkulationstemperatur";
const char STR8836[] PROGMEM = "TWW Ladetemperatur";
const char STR8840[] PROGMEM = "Betr’stunden TWW-Pumpe";
const char STR8841[] PROGMEM = "Startzähler TWW-Pumpe";
const char STR8842[] PROGMEM = "Betr’stunden Elektro TWW";
const char STR8843[] PROGMEM = "Startzähler Elektro TWW";
const char STR8850[] PROGMEM = "TWW Vorreglertemperatur";
const char STR8851[] PROGMEM = "TWW Vorreglersollwert";
const char STR8852[] PROGMEM = "TWW Durchl'erhitzertemp";
const char STR8853[] PROGMEM = "TWW Durchl'erhitzersollwert";
const char STR8875[] PROGMEM = "Vorlaufsollwert VK1";
const char STR8885[] PROGMEM = "Vorlaufsollwert VK2";
const char STR8895[] PROGMEM = "Vorlaufsollwert Schwimmbad";
const char STR8900[] PROGMEM = "Schwimmbadtemperatur";
const char STR8901[] PROGMEM = "Schwimmbadsollwert";
const char STR8930[] PROGMEM = "Vorreglertemperatur";
const char STR8931[] PROGMEM = "Vorreglersollwert";
const char STR8950[] PROGMEM = "Schienenvorlauftemperatur";
const char STR8951[] PROGMEM = "Schienenvorlaufsollwert";
const char STR8952[] PROGMEM = "Schienenrücklauftemperatur";
const char STR8957[] PROGMEM = "Schienenvorl'sollwert Kälte";
const char STR8962[] PROGMEM = "Leistungssollwert Schiene";
const char STR8970[] PROGMEM = "Elektroeinsatz Puffer";
const char STR8980[] PROGMEM = "Pufferspeichertemperatur 1";
const char STR8981[] PROGMEM = "Pufferspeichersollwert";
const char STR8982[] PROGMEM = "Pufferspeichertemperatur 2";
const char STR8983[] PROGMEM = "Pufferspeichertemperatur 3";
const char STR8990[] PROGMEM = "Betr’stunden Elektro Puffer";
const char STR8991[] PROGMEM = "Startzähler Elektro Puffer";
const char STR9000[] PROGMEM = "Vorlaufsollwert H1";
const char STR9001[] PROGMEM = "Vorlaufsollwert H2";
const char STR9004[] PROGMEM = "Vorlaufsollwert H3";
const char STR9005[] PROGMEM = "Wasserdruck H1";
const char STR9006[] PROGMEM = "Wasserdruck H2";
const char STR9009[] PROGMEM = "Wasserdruck H3";
const char STR9031[] PROGMEM = "Relaisausgang QX1";
const char STR9032[] PROGMEM = "Relaisausgang QX2";
const char STR9033[] PROGMEM = "Relaisausgang QX3";
const char STR9034[] PROGMEM = "Relaisausgang QX4";
const char STR9035[] PROGMEM = "Relaisausgang QX5";
const char STR9036[] PROGMEM = "Relaisausgang QX6";
const char STR9037[] PROGMEM = "Relaisausgang QX7";
const char STR9038[] PROGMEM = "Relaisausgang QX8";
const char STR9050[] PROGMEM = "Relaisausgang QX21 Modul 1";
const char STR9051[] PROGMEM = "Relaisausgang QX22 Modul 1";
const char STR9052[] PROGMEM = "Relaisausgang QX23 Modul 1";
const char STR9053[] PROGMEM = "Relaisausgang QX21 Modul 2";
const char STR9054[] PROGMEM = "Relaisausgang QX22 Modul 2";
const char STR9055[] PROGMEM = "Relaisausgang QX23 Modul 2";
const char STR9071[] PROGMEM = "Relaisausgang QX31";
const char STR9072[] PROGMEM = "Relaisausgang QX32";
const char STR9073[] PROGMEM = "Relaisausgang QX33";
const char STR9074[] PROGMEM = "Relaisausgang QX34";
const char STR9075[] PROGMEM = "Relaisausgang QX35";

// Feuerungsautomat
const char STR9500[] PROGMEM = "Vorlüftzeit";
const char STR9502[] PROGMEM = "Gebl'ansteuerung Vorlüftung";
const char STR9504[] PROGMEM = "Solldrehzahl Vorlüftung";
const char STR9504_2[] PROGMEM = "Sollleistung Vorlüftung";
const char STR9510[] PROGMEM = "Gebl'ansteuerung Zündung";
const char STR9512[] PROGMEM = "Solldrehzahl Zündung";
const char STR9512_2[] PROGMEM = "Sollleistung Zündlast";
const char STR9520[] PROGMEM = "Gebl'ansteuerung Betrieb. Min";
const char STR9522[] PROGMEM = "Gebl'ansteuerung Betrieb. Max";
const char STR9524[] PROGMEM = "Solldrehzahl Betrieb Min";
const char STR9524_2[] PROGMEM = "Sollleistung Teillast";
const char STR9527[] PROGMEM = "Solldrehzahl Betrieb Max";
const char STR9529[] PROGMEM = "Sollleistung Volllast";
const char STR9540[] PROGMEM = "Nachlüftzeit";
const char STR9550[] PROGMEM = "Gebl'ansteuerung Stillstand";
const char STR9560[] PROGMEM = "Gebl'ansteuerung Durchlad";
const char STR9563[] PROGMEM = "Solldrehzahl Durchladung";
const char STR9626[] PROGMEM = "Gebl'Leist/Drehz Steigerung";
const char STR9627[] PROGMEM = "Gebl'Leist/Drehz Y-Abschn";


/* User-defined command numbers */
const char STR10000[] PROGMEM = "Raumtemperatur 1";     // same as 10109
const char STR10001[] PROGMEM = "Raumtemperatur 2";
const char STR10002[] PROGMEM = "Raumtemperatur P";

const char STR10100[] PROGMEM = "INFO Brenner";
const char STR10101[] PROGMEM = "INFO Trinkwasserbereitung";
const char STR10102[] PROGMEM = "INFO HK1 - TBD";
const char STR10103[] PROGMEM = "INFO HK2 - TBD";
const char STR10104[] PROGMEM = "INFO HK3/P - TBD";

const char STR10200[] PROGMEM = "Unknown command";

const char STR15004[] PROGMEM = "T° départ après mélangeur (sonde B1) #52.2 ";
const char STR15009[] PROGMEM = " Bouton rotatif -3/+3 = décalage consigne T° ambiante";//XXX Position Drehknopf
const char STR15011[] PROGMEM = " Touche de présence ";//XXX Präsenztaste
const char STR15012[] PROGMEM = " Jours de vacances restants ";//XXX Verbleibende Ferientage
const char STR15019[] PROGMEM = " Période de chauffe 1 Lundi Début ";//XXX
const char STR15020[] PROGMEM = " Période de chauffe 1 Lundi Fin ";//XXX
const char STR15021[] PROGMEM = " Période de chauffe 2 Lundi Début ";//XXX
const char STR15022[] PROGMEM = " Période de chauffe 2 Lundi Fin ";//XXX
const char STR15023[] PROGMEM = " Période de chauffe 3 Lundi Début ";//XXX
const char STR15024[] PROGMEM = " Période de chauffe 3 Lundi Fin ";//XXX
const char STR15025[] PROGMEM = " Période de chauffe 1 Mardi Début ";//XXX
const char STR15026[] PROGMEM = " Période de chauffe 1 Mardi Fin ";//XXX
const char STR15027[] PROGMEM = " Période de chauffe 2 Mardi Début ";//XXX
const char STR15028[] PROGMEM = " Période de chauffe 2 Mardi Fin ";//XXX
const char STR15029[] PROGMEM = " Période de chauffe 3 Mardi Début ";//XXX
const char STR15030[] PROGMEM = " Période de chauffe 3 Mardi Fin ";//XXX
const char STR15031[] PROGMEM = " Période de chauffe 1 Mercredi Début ";//XXX
const char STR15032[] PROGMEM = " Période de chauffe 1 Mercredi Fin ";//XXX
const char STR15033[] PROGMEM = " Période de chauffe 2 Mercredi Début ";//XXX
const char STR15034[] PROGMEM = " Période de chauffe 2 Mercredi Fin ";//XXX
const char STR15035[] PROGMEM = " Période de chauffe 3 Mercredi Début ";//XXX
const char STR15036[] PROGMEM = " Période de chauffe 3 Mercredi Fin ";//XXX
const char STR15037[] PROGMEM = " Période de chauffe 1 Jeudi Début ";//XXX
const char STR15038[] PROGMEM = " Période de chauffe 1 Jeudi Fin ";//XXX
const char STR15039[] PROGMEM = " Période de chauffe 2 Jeudi Début ";//XXX
const char STR15040[] PROGMEM = " Période de chauffe 2 Jeudi Fin ";//XXX
const char STR15041[] PROGMEM = " Période de chauffe 3 Jeudi Début ";//XXX
const char STR15042[] PROGMEM = " Période de chauffe 3 Jeudi Fin ";//XXX
const char STR15043[] PROGMEM = " Période de chauffe 1 Vendredi Début ";//XXX
const char STR15044[] PROGMEM = " Période de chauffe 1 Vendredi Fin ";//XXX
const char STR15045[] PROGMEM = " Période de chauffe 2 Vendredi Début ";//XXX
const char STR15046[] PROGMEM = " Période de chauffe 2 Vendredi Fin ";//XXX
const char STR15047[] PROGMEM = " Période de chauffe 3 Vendredi Début ";//XXX
const char STR15048[] PROGMEM = " Période de chauffe 3 Vendredi Fin ";//XXX
const char STR15049[] PROGMEM = " Période de chauffe 1 Samedi Début ";//XXX
const char STR15050[] PROGMEM = " Période de chauffe 1 Samedi Fin ";//XXX
const char STR15051[] PROGMEM = " Période de chauffe 2 Samedi Début ";//XXX
const char STR15052[] PROGMEM = " Période de chauffe 2 Samedi Fin ";//XXX
const char STR15053[] PROGMEM = " Période de chauffe 3 Samedi Début ";//XXX
const char STR15054[] PROGMEM = " Période de chauffe 3 Samedi Fin ";//XXX
const char STR15055[] PROGMEM = " Période de chauffe 1 Dimanche Début ";//XXX
const char STR15056[] PROGMEM = " Période de chauffe 1 Dimanche Fin ";//XXX
const char STR15057[] PROGMEM = " Période de chauffe 2 Dimanche Début ";//XXX
const char STR15058[] PROGMEM = " Période de chauffe 2 Dimanche Fin ";//XXX
const char STR15059[] PROGMEM = " Période de chauffe 3 Dimanche Début ";//XXX
const char STR15060[] PROGMEM = " Période de chauffe 3 Dimanche Fin ";//XXX
const char STR15061[] PROGMEM = " Heure chaudière ";//XXXU hrzeit
const char STR15062[] PROGMEM = " Modèle de sonde d'ambiance QAA ";//XXX QAA Modell
const char STR15064[] PROGMEM = " Température cible : 15009+15014 ou 15015 #54 ";//XXX Zieltemperatur
const char STR15065[] PROGMEM = "Nächstes Schaltprogramm";
const char STR15066[] PROGMEM = "Chauffage en local/manuel : horloge pas sélectionnée sur la chaudière ";//XXX Manuelles Heizen
const char STR15067[] PROGMEM = "Connexion interrompue ";//XXX Verbindung unterbrochen

// A catch-all description string for unrecognised command codes
const char STR99999[] PROGMEM = "UNKNOWN command code";



/* ENUM tables */
const char ENUM20[] PROGMEM_LATEST = { // numerical values are hypothetical
"\x01 ?English\0"
"\x02 ?Deutsch\0"
"\x03 ?Francais\0"
"\x04 ?Nederlands\0"
"\x05 ?Italiano\0"
"\x06 ?Espanol\0"
"\x07 ?Polski\0"
"\x08 ?Ceski"
};
// numerical values are hypothetical
const char ENUM22[] PROGMEM_LATEST = {"\x01 Temporär\0\x02 Permanent"};
const char ENUM23[] PROGMEM_LATEST = {"\x00 ?Code\0\x01 ?Code und Text"};
const char ENUM28[] PROGMEM_LATEST = {"\x01 Speichern automatisch\0\x02 Speichern mit Bestätigung"};
const char ENUM29[] PROGMEM_LATEST = {"\x01 °C,bar\0\x02 °F,PSI"};
const char ENUM40[] PROGMEM_LATEST = {
"\x00 ?Raumgerät 1\0"
"\x01 ?Raumgerät 2\0"
"\x02 ?Raumgerät P\0"
"\x03 ?Bediengerät 1\0"
"\x04 ?Bediengerät 2\0"
"\x05 Servicegerät"
};
const char ENUM42[] PROGMEM_LATEST = {	// numerical values are hypothetical
"\x00 ?Heizkreis 1\0"
"\x01 ?Heizkreis 1 und 2\0"
"\x02 ?Heizkreis 1 und P\0"
"\x03 ?Alle Heizkreise"
};
const char ENUM44[] PROGMEM_LATEST = {"\x01 Gemeinsam mit HK1\0\x02 Unabhängig"};
#define ENUM46 ENUM44
const char ENUM47[] PROGMEM_LATEST = {  // NovoCondens WOB20C / WOB25C
"\x01 ?Heizkreis 1\0"
"\x02 ?Für alle zugeord'Heizkreise"
};
// Nur am Raumgerät sichtbar, numerical values are hypothetical
const char ENUM48[] PROGMEM_LATEST = {"\x00 ?Keine\0\x01 ?Heizkreis 1\0\x02 ?Heizkreis 2\0\x03 ?Gemeinsam"};

const char ENUM130[] PROGMEM_LATEST = {"\x00 Fehlt\0\x01 In Betrieb\0\x02 ?Kein Empfang\0\x03 ?Batt. wechseln"};
#define ENUM131 ENUM130
#define ENUM132 ENUM130
#define ENUM133 ENUM130
#define ENUM134 ENUM130
#define ENUM135 ENUM130
#define ENUM136 ENUM130
#define ENUM137 ENUM130
#define ENUM138 ENUM130

/*
const char ENUM648[] PROGMEM_LATEST = {"\x00 Frostschutz\0\x01 Reduziert"};
#define ENUM658 ENUM648
#define ENUM668 ENUM648
*/

const char ENUM648[] PROGMEM_LATEST = {"\x00 Frostschutz\0\x01 Reduziert"};
#define ENUM665 ENUM648
#define ENUM682 ENUM648

const char ENUM700[] PROGMEM_LATEST = {"\x00 Schutzbetrieb\0\x01 Automatik\0\x02 Reduziert\0\x03 Komfort"};

const char ENUM780[] PROGMEM_LATEST = {"\x00 Aus\0\x01 Bis Reduziertsollwert\0\x02 Bis Frostschutzsollwert"};
const char ENUM832[] PROGMEM_LATEST = {"\x00 2-Punkt\0\x01 3-Punkt"};
const char ENUM850[] PROGMEM_LATEST = {"\x00 Aus\0\x01 Funktionsheizen\0\x02 Belegreifheizen\0\x03 Funktions-/Belegreifheizen\0\x04 Belegreif-/Funktionsheizen\0\x05 Manuell"};
const char ENUM861[] PROGMEM_LATEST = {"\x00 Aus\0\x01 Heizbetrieb\0\x02 Immer"};
const char ENUM880[] PROGMEM_LATEST = {"\x00 Betriebsniveau\0\x01 Kennlinie\0\x02 Temperaturhub Nenn"};
const char ENUM898[] PROGMEM_LATEST = {"\x00 Schutzbetrieb\0\x01 Reduziert\0\x02 Komfort"};

const char ENUM900[] PROGMEM_LATEST = {"\x00 Keine\0\x01 Schutzbetrieb\0\x02 Reduziert\0\x03 Komfort\0\x04 Automatik"};
const char ENUM900_2[] PROGMEM_LATEST = {"\x00 Schutzbetrieb\0\x01 Reduziert\0\x03 Komfort\0\x04 Automatik"};

const char ENUM1000[] PROGMEM_LATEST = {"\x00 Schutzbetrieb\0\x01 Automatik\0\x02 Reduziert\0\x03 Komfort"};

#define ENUM1080 ENUM780         // Schnellabsenkung HK2
#define ENUM1132 ENUM832         // Antrieb Typ HK2
#define ENUM1150 ENUM850         // Estrichfunktion HK2
#define ENUM1161 ENUM861         // Übertemperaturabnahme HK2
#define ENUM1200 ENUM900         // Betriebsartumschaltung HK2
#define ENUM1200_2 ENUM900_2         // Betriebsartumschaltung HK2

#define ENUM1180 ENUM880

const char ENUM1300[] PROGMEM_LATEST = {"\x00 Schutzbetrieb\0\x01 Automatik\0\x02 Reduziert\0\x03 Komfort"};
#define ENUM1350 ENUM850
#define ENUM1380 ENUM780
#define ENUM1450 ENUM850

#define ENUM1461 ENUM861         // Uebertemperaturabnahme HK P/3
#define ENUM1500 ENUM900         // Betriebsartumschaltung HK P/3
#define ENUM1500_2 ENUM900_2         // Betriebsartumschaltung HK P/3

const char ENUM1600[] PROGMEM_LATEST = {
"\x00 Aus\0"
"\x01 Ein\0"
"\x02 Eco"
};

const char ENUM1602[] PROGMEM_LATEST = {
"\x00\x02 TWW-Push nicht aktiv\0"
"\x02\x02 TWW-Push aktiv\0"
"\x00\x04 TWW aus\0"
"\x04\x04 TWW an\0"
"\x00\x08 TWW Ladung nicht aktiv\0"
"\x08\x08 TWW Ladung aktiv"
};

const char ENUM1620[] PROGMEM_LATEST = {"\x00 24h/Tag\0\x01 Zeitprogramme Heizkreise\0\x02 Zeitprogramm 4/TWW"};
const char ENUM1620_2[] PROGMEM_LATEST = {"\x00 24h/Tag\0\x01 Zeitprogramme Heizkreise\0\x04 Zeitprogramm 4/TWW"};
const char ENUM1630[] PROGMEM_LATEST = {"\x00 Absolut\0\x01 Gleitend\0\x02 Kein\0\x03 MK gleitend PK absolut\0\x04 Aus"};
const char ENUM1640[] PROGMEM_LATEST = {"\x00 Aus\0\x01 Periodisch\0\x02 Fixer Wochentag"};
const char ENUM1660[] PROGMEM_LATEST = {"\x01 Zeitprogramm 3/HKP\0\x02 Trinkwasser Freigabe\0\x03 Zeitprogramm 4/TWW\0\x04 Zeitprogramm 5"};
const char ENUM1680[] PROGMEM_LATEST = {"\x00 Keine\0\x01 Aus\0\x02 Ein"};

// Vorregler/Zubringerpumpe

const char ENUM2132[] PROGMEM_LATEST = {  // ENUM values hypothetical
"\x00 2-Punkt\0"
"\x01 3-Punkt"
};

const char ENUM2150[] PROGMEM_LATEST = {  // ENUM values hypothetical
"\x00 Von Pufferspeicher\0"
"\x01 Nach Pufferspeicher"
};

// Kessel
const char ENUM2200[] PROGMEM_LATEST = {"\x00 Dauerbetrieb\0\x01 Automatik\0\x02 Auto, verlängerte Laufzeit"};
const char ENUM2205[] PROGMEM_LATEST = {"\x00 Aus\0\x01 Ein Trinkwasser\0\x02 Ein"};
const char ENUM2206[] PROGMEM_LATEST = {"\x00 Betrieb\0\x01 Standby"};
const char ENUM2291[] PROGMEM_LATEST = {"\x00 Parallel Brennerbetrieb\0\x01 Rücklauftemperatur"};

const char ENUM2305[] PROGMEM_LATEST = {
"\x00 Nur Heizbetrieb\0"
"\x01 Heiz- und Trinkwasserbetrieb"
};

const char ENUM2305_2[] PROGMEM_LATEST = {
"\x01 Nur Heizbetrieb\0"
"\x02 Heiz- und Trinkwasserbetrieb"
};

const char ENUM2320[] PROGMEM_LATEST = {
"\x00 Keine\0"
"\x01 Bedarf\0"
"\x02 Kesselsollwert\0"
"\x03 Temperaturhub Nenn\0"
"\x04 Brennerleistung"
};

const char ENUM2450[] PROGMEM_LATEST = {
"\x00 Aus\0"
"\x01 Nur Heizbetrieb\0"
"\x02 Nur Trinkwasserbetrieb\0"
"\x03 Heiz- und Trinkwasserbetrieb"
};

const char ENUM2480[] PROGMEM_LATEST = {
"\x00 Startverhinderung\0"
"\xff Störstellung"
};

const char ENUM2500[] PROGMEM_LATEST = {
"\x00 Startverhinderung\0"
"\x01 Störstellung"
};

// Sitherm Pro
const char ENUM2706[] PROGMEM_LATEST = {
"\x00 Gesperrt\0"
"\x01 Prüfmodus Schrittmotor\0"
"\x02 Start manueller Drifttest\0"
"\x03 Standby\0"                     // verifiziert an WMS (LP)
"\x04 Initialisierung\0"
"\x05 Zünden\0"
"\x06 Kaltstarterkennung\0"
"\x07 Anregelung\0"                  // verifiziert an WMS (LP)
"\x08 Stabilisierung\0"              // verifiziert an WMS (LP)
"\x09 Regelt\0"                      // verifiziert an WMS (LP)
"\x0a Exotengasbetrieb\0"
"\x0b Drifttest aktiv\0"
"\x0c Drifttest fällig\0"
"\x0d Drifttest überfällig\0"
"\x12 ADA Intervall 1 fällig"        // verifiziert an WMS (LP)
}; // todo Hinweis: x03, x07, x08, x12 sind definitiv richtig. Die anderen muessen noch verifiziert werden.

const char ENUM2721[] PROGMEM_LATEST = {
"\x01 Erdgas\0"
"\x02 Flüssiggas"
}; // todo Hinweis: x01 Erdgas ist definitiv richtig. Die anderen muessen noch verifiziert werden.

const char ENUM2727[] PROGMEM_LATEST = {
"\x01 Bereich 1\0"
"\x02 Bereich 2\0"
"\x03 Bereich 3"
};

const char ENUM2740[] PROGMEM_LATEST = {
"\x00 Nein\0"
"\x01 Alle Punkte\0"
"\x02 Alle fälligen Punkte\0"
"\x03 Punkt 1\0"
"\x04 Punkt 2\0"
"\x05 Punkt 3\0"
"\x06 Punkt 4\0"
"\x07 Punkt 5\0"
"\x08 Punkt 6\0"
"\x09 Punkt 7"
}; // todo Hinweis: x00 Nein ist definitiv richtig. Die anderen muessen noch verifiziert werden.

const char ENUM2749[] PROGMEM_LATEST = {
"\x00 Nein\0"
"\x01 Neue Elektrode\0"
"\x02 Gebrauchte Elektrode"
}; // todo Hinweis: x00 Nein ist definitiv richtig. Die anderen muessen noch verifiziert werden.

// ProgNr 2920 "Bei EW Sperre" FUJITSU
const char ENUM2920[] PROGMEM_LATEST = {
"\x00 Gesperrt\0"
"\x01 Freigegeben"
};

// Energiezähler

// "Durchflussmessung Wärme"
const char ENUM3095[] PROGMEM_LATEST = {
"\x00 Keine\0"
"\x01 Mit Eingang H1\0"
"\x02 Mit Eingang H2 Modul 1\0"
"\x03 Mit Eingang H2 Modul 2\0"
"\x04 Mit Eingang H2 Modul 3\0"
"\x05 Mit Eingang H21 Modul 1\0"
"\x06 Mit Eingang H21 Modul 2\0"
"\x07 Mit Eingang H21 Modul 3\0"
"\x08 Mit Eingang H22 Modul 1\0"
"\x09 Mit Eingang H22 Modul 2\0"
"\x0a Mit Eingang H22 Modul 3\0"
"\x0b Mit Eingang H3\0"
"\x0c Mit Eingang H31\0"
"\x0d Mit Eingang H32"
};
// "Impulszählung Energie"
const char ENUM3100[] PROGMEM_LATEST = {
"\x00 Keine\0"
"\x01 Mit Eingang H1\0"
"\x02 Mit Eingang H21 Modul 1\0"
"\x03 Mit Eingang H21 Modul 2\0"
"\x04 Mit Eingang H21 Modul 3\0"
"\x05 Mit Eingang H22 Modul 1\0"
"\x06 Mit Eingang H22 Modul 2\0"
"\x07 Mit Eingang H22 Modul 3\0"
"\x08 Mit Eingang H3\0"
"\x09 Mit Eingang H31\0"
"\x0a Mit Eingang H32"
};
// "Impulseinheit Energie"
const char ENUM3102[] PROGMEM_LATEST = {
"\x00 Keine\0"
"\x01 kWh\0"
"\x02 m3"
};
// "Zählung Intern Elektro Vorl’"
const char ENUM3109[] PROGMEM_LATEST = {
"\x00 Keine\0"
"\x01 Abgegebene Wärme\0"
"\x02 Eingesetzte Energie\0"
"\x03 Beide"
};
// Kaskade
const char ENUM3510[] PROGMEM_LATEST = {  // numerical values are hypothetical
"\x00 ?Spät ein, früh aus\0"
"\x01 ?Spät ein, spät aus\0"
"\x02 ?Früh ein, spät aus"
};
const char ENUM3541[] PROGMEM_LATEST = {  // numerical values are hypothetical
"\x00 ?Keine\0"
"\x01 ?Erster\0"
"\x02 Letzter"
};
const char ENUM3544[] PROGMEM_LATEST = {  // numerical values are hypothetical
"\x00 ?Erzeuger 1\0"
"\x01 ?Erzeuger 2\0"
"\x02 ?Erzeuger 3\0"
"\x03 ?Erzeuger 4\0"
"\x04 ?Erzeuger 5\0"
"\x05 ?Erzeuger 6\0"
"\x06 ?Erzeuger 7\0"
"\x07 ?Erzeuger 8\0"
"\x08 ?Erzeuger 9\0"
"\x09 ?Erzeuger 10\0"
"\x0a ?Erzeuger 11\0"
"\x0b ?Erzeuger 12\0"
"\x0c ?Erzeuger 13\0"
"\x0d ?Erzeuger 14\0"
"\x0e ?Erzeuger 15\0"
"\x0f ?Erzeuger 16"
};

// Solar
const char ENUM3822[] PROGMEM_LATEST = {"\x00 Kein\0\x01 Trinkwasserspeicher\0\x02 Pufferspeicher"};
const char ENUM3880[] PROGMEM_LATEST = {"\x01 Kein\0\x02 Ethylenglykol\0\x03 Propylenglykol\0\x04 Ethylen- und Propylenglykol"};
const char ENUM3887[] PROGMEM_LATEST = {"\x01 Kein\0\x02 kWh\0\x03 Liter"};

//Feststoffkessel
const char ENUM4133[] PROGMEM_LATEST = {
"\x01 Trinkwasserfühler B3\0"
"\x02 Trinkwasserfühler B31\0"
"\x03 Pufferspeicherfühler B4\0"
"\x04 Pufferspeicherfühler B41\0"
"\x05 Vorlaufsollwert\0"
"\x06 Sollwert Minimum"
};

// Pufferspeicher
const char ENUM4720[] PROGMEM_LATEST = {"\x00 Keine\0\x01 Mit B4\0\x02 Mit B4 und B42/41"};
const char ENUM4757[] PROGMEM_LATEST = {"\x00 Aus\0\x01 Sommer\0\x02 Immer"};
const char ENUM4795[] PROGMEM_LATEST = {"\x01 Mit B4\0\x02 Mit B41\0\x03 Mit B42"};
const char ENUM4796[] PROGMEM_LATEST = {"\x01 Temperaturabsenkung\0\x02 Temperaturanhebung"};
const char ENUM4810[] PROGMEM_LATEST = {"\x00 Aus\0\x01 Heizbetrieb\0\x02 Immer"};
const char ENUM4813[] PROGMEM_LATEST = {"\x01 Mit B4\0\x02 Mit B42/B41"};
// Trinkwasserspeicher
const char ENUM5010[] PROGMEM_LATEST = {"\x00 Einmal/Tag\0\xff Mehrmals/Tag"};
const char ENUM5022[] PROGMEM_LATEST = {"\x01 Mit B3\0\x02 Mit B3/B31\0\x03 Mit B3, Legio B3/31"};
const char ENUM5022_2[] PROGMEM_LATEST = {"\x01 Nachladen\0\x02 Durchladen\0\x03 Durchladen Legio\0\x04 Durchladen 1. Ladung\0\x05 Durchladen Legio und 1. Ladung"};
const char ENUM5040[] PROGMEM_LATEST = {"\x00 Aus\0\x01 Immer\0\x02 Automatisch"};
const char ENUM5057[] PROGMEM_LATEST = {"\x00 Aus\0\x01 Sommer\0\x02 Immer"};
const char ENUM5060[] PROGMEM_LATEST = {"\x01 Ersatz\0\x02 Sommer\0\x03 Immer"};
const char ENUM5061[] PROGMEM_LATEST = {"\x01 24h/Tag\0\x02 Trinkwasser Freigabe\0\x03 Zeitprogramm 4/TWW"};
const char ENUM5062[] PROGMEM_LATEST = {"\x01 Externer Thermostat\0\x02 Trinkwasserfühler"};
const char ENUM5130[] PROGMEM_LATEST = {"\x00 Immer\0\x01 Warmwasser Freigabe"};
const char ENUM5131[] PROGMEM_LATEST = {"\x00 Trinkwasserfühler B3\0\x01 Trinkwasserfühler B31"};
// Konfiguration
const char ENUM5700[] PROGMEM_LATEST = { //FUJITSU
"\x01 Voreinstellung 1 : 1 Heizkreislauf mit oder ohne Heizwiderstand und mit oder ohne WW.\0"
"\x02 Voreinstellung 2 : 2 Heizkreisläufe mit oder ohne Heizwiderstand und mit oder ohne WW.\0"
"\x03 Voreinstellung 3 : Übernahme vom Heizkessel, 1 Heizkreislau mit oder ohne WW.\0"
"\x04 Voreinstellung 4 : Übernahme vom Heizkessel, 2 Heizkreisläufe mit oder ohne WW.\0"
"\x05 Nicht verwendet"
};
const char ENUM5711[] PROGMEM_LATEST = { //FUJITSU
"\x00 Aus\0"
"\x01 4-Leitersystem\0"
"\x02 2-Leitersystem"
};

const char ENUM5712[] PROGMEM_LATEST = {
"\x01 Heizen\0"
"\x02 Kühlen\0"
"\x03 Heizen+Kühlen"
};

const char ENUM5730[] PROGMEM_LATEST = {"\x00 Fühler\0\x01 Thermostat"};
const char ENUM5731[] PROGMEM_LATEST = {"\x00 kein\0\x01 Ladepumpe\0\x02 Umlenkventil"};
const char ENUM5734[] PROGMEM_LATEST = {"\x00 Letzte Anforderung\0\x01 Heizkreis\0\x02 Trinkwasser"};
const char ENUM5760[] PROGMEM_LATEST = {"\x00 Vor Pufferspeicher\0\x01 Nach Pufferspeicher"};

const char ENUM5761[] PROGMEM_LATEST = {
"\x01\x01 Zonen mit Zubringerpumpe\0"
"\x02\x02 HK1 mit Zubringerpumpe\0"
"\x04\x04 HK2 mit Zubringerpumpe\0"
"\x08\x08 TWW mit Zubringerpumpe"
};

const char ENUM5770[] PROGMEM_LATEST = {
"\x00 Kein Erzeuger oder PPS-BMU\0"
"\x01 1-stufig\0"
"\x02 2-stufig\0"
"\x03 Modulierend 3-Punkt Luftklappenantrieb\0"
"\x04 Modulierend 2-Punkt Luftklappenantrieb\0"
"\x05 Kaskade (zwei 1-stufige Brenner)"
};

const char ENUM5774[] PROGMEM_LATEST = {
  "\x00 Alle Anforderungen\0"
  "\xFF Nur Anforderung HK1/TWW"};

const char ENUM5806[] PROGMEM_LATEST = { //FUJITSU
"\x01 3-stufig\0"
"\x02 2-stufig ausschliessend\0"
"\x03 2-stufig ergänzend\0"
"\x04 Modulierend UX"
};
const char ENUM5840[] PROGMEM_LATEST = {"\x00 Ladepumpe\0\x01 Umlenkventil"};
const char ENUM5841[] PROGMEM_LATEST = {"\x00 Gemeinsam\0\x01 Trinkwasserspeicher\0\x02 Pufferspeicher"};

// Konfiguration - Relaisausgang QX1
const char ENUM5890[] PROGMEM_LATEST = {
"\x00 Kein\0"
"\x01 Zirkulationspumpe Q4\0"
"\x02 Elektroeinsatz TWW K6\0"
"\x03 Kollektorpumpe Q5\0"
"\x04 H1-Pumpe Q15\0"
"\x05 Kesselpumpe Q1\0"
"\x06 Bypasspumpe Q12\0"
"\x07 Alarmausgang K10\0"
"\x08 2.Pumpenstufe HK1 Q21\0"
"\x09 2.Pumpenstufe HK2 Q22\0"
"\x0a 2.Pumpenstufe HKP Q23\0"
"\x0b Heizkreispumpe HKP Q20\0"
"\x0c H2-Pumpe Q18\0"
"\x0d Zubringerpumpe Q14\0"
"\x0e Erzeugersperrventil Y4\0"
"\x0f Feststoffkesselpumpe Q10\0"
"\x10 Zeitprogramm 5 K13\0"
"\x11 Pufferrücklaufventil Y15\0"
"\x12 Solarpumpe ext. Tauscher K9\0"
"\x13 Solarstellglied Puffer K8\0"
"\x14 Solarstellglied Schw'bad K18\0"
"\x15 Kollektorpumpe 2 Q16\0"
"\x16 H3-Pumpe Q19\0"
"\x17 Abgasrelais K17\0"
"\x19 Kaskadenpumpe Q25\0"
"\x1a Speicherumladepumpe Q11\0"
"\x1b TWW Durchmischpumpe Q35\0"
"\x1c TWW Zwisch'kreispumpe Q33\0"
"\x1d Wärmeanforderung K27\0"
"\x21 Heizkreispumpe HK1 Q2\0"
"\x28 Meldeausgang K35\0"
"\x29 Betriebsmeldung K36"
};

const char ENUM5890_2[] PROGMEM_LATEST = {
"\x00 Keine Funktion\0"
"\x01 Heizkreispumpe 2\0"
"\x02 Zubringerpumpe nach BW\0"
"\x03 Zubringerpumpe vor BW\0"
"\x04 Zubringerpumpe bei ext. Anforderung\0"
"\x05 Brauchwasser-Zirkulationspumpe\0"
"\x06 Brauchwasser-Elektroeinsatz\0"
"\x07 Solar-Pumpe\0"
"\x08 H1 Pumpe\0"
"\x09 Kesselpumpe\0"
"\x0a Kessel-Bypasspumpe\0"
"\x0b Alarmausgang"
};

#define ENUM5891 ENUM5890               // Relaisausgang QX2
#define ENUM5892 ENUM5890               // Relaisausgang QX3
#define ENUM5894 ENUM5890               // Relaisausgang QX4
#define ENUM5902 ENUM5890               // Relaisausgang QX21
#define ENUM5904 ENUM5890               // Relaisausgang QX23
#define ENUM5908 ENUM5890               // Relaisausgang QX3-Mod
/* Possibly the same as 5890:
#define ENUM5909 ENUM5890               // Relaisausgang QX4-Mod
*/
// The numerical values are undocumented in the Broetje Systemhandbuch
// Values here are hypothetical.
const char ENUM5895[] PROGMEM_LATEST = {        // Relaisausgang QX5
"\x00 ?Kein\0"
"\x01 ?Heizkreispumpe HK1 Q2\0"
"\x02 ?Trinkwasserstellglied Q3\0"
"\x03 ?Verdichterstufe 2 K2\0"
"\x04 ?Prozessumkehrventil Y22\0"
"\x05 ?Heissgastemperatur K31\0"
"\x06 ?Elektroeinsatz1 Vorlauf K25\0"
"\x07 ?Elektroeinsatz2 Vorlauf K26\0"
"\x07 ?Umlenkventil Kühl Quelle Y28\0"
"\x08 ?Zirkulationspumpe Q4\0"
"\x09 ?Elektroeinsatz TWW K6\0"
"\x0a ?Elektroeinsatz Puffer K16\0"
"\x0b ?Kollektorpumpe Q5\0"
"\x0c ?H1-Pumpe Q15\0"
"\x0d ?Kesselpumpe Q1\0"
"\x0e ?Bypasspumpe Q12\0"
"\x0f ?Alarmausgang K10\0"
"\x10 ?2. Pumpenstufe HK1 Q21\0"
"\x11 ?2. Pumpenstufe HK2 Q22\0"
"\x12 ?2. Pumpenstufe HKP Q23\0"
"\x13 ?Heizkreispumpe HKP Q20\0"
"\x14 ?H2-Pumpe Q18\0"
"\x15 ?Zubringerpumpe Q14\0"
"\x16 ?Feststoffkesselpumpe Q10\0"
"\x17 ?Zeitprogramm 5 K13\0"
"\x18 ?Pufferrücklaufventil Y15\0"
"\x19 ?Solarpumpe ext. Tauscher\0"
"\x1a ?Solarstellglied Puffer K8\0"
"\x1b ?Solarstellglied Schw'bad K18\0"
"\x1c ?Kollektorpumpe 2 Q16\0"
"\x1d ?H3-Pumpe Q19\0"
"\x1e ?Abgasrelais K17\0"
"\x1f ?Umlenkventil Kühlen Y21\0"
"\x20 ?Umlenkventil Kühl Quelle Y28\0"
"\x21 ?Quell'pumpe Q8\0"
"\x22 ?Ventilat K19\0"
"\x23 ?Kondensatorpumpe Q9\0"
"\x24 ?Luftentfeuchter K29\0"
"\x25 ?Kaskadenpumpe Q25\0"
"\x26 ?Speicherumladepumpe Q11\0"
"\x27 ?TWW Durchmischpumpe Q35\0"
"\x28 ?TWW Zwisch'kreispumpe Q33\0"
"\x29 ?Wärmeanforderung K27\0"
"\x2a ?Kälteanforderung K28\0"
"\x2b ?Verdichterstufe 1 K1\0"
"\x2c ?Zusatzerzeuger Regelung K32"
};

// Konfiguration - Thision 5922 Relaisausgang 1 RelCl
const char ENUM5920[] PROGMEM_LATEST = {
"\x00 Default, Keine Funktion\0"
"\x01 Meldeausgang\0"
"\x02 Alarmausgang\0"
"\x03 Betriebsmeldung\0"
"\x04 Externer Trafo\0"
"\x05 Heizkreispumpe HK2 (Q2Y2)\0"
"\x06 Zirkulationspumpe\0"
"\x07 Torschleierfunktion\0"
"\x08 Pumpe Hydraulische Weiche\0"
"\x09 Zubringerpumpe Q8\0"
"\x0a Grundfunktion K2\0"
"\x0b Trinkwasserdurchladung\0"
"\x0c Schwelle Analogsignal\0"
"\x0d Abgasklappe\0"
"\x0e Kollektorpumpe\0"
"\x0f Gebläseabschaltung\0"
"\x10 Pumpe Q1\0"
"\x11 TWW Durchmischpumpe Q35"
};
#define ENUM5922 ENUM5920               // Thision 5923 Relaisausgang 2 RelCl
#define ENUM5923 ENUM5920               // Thision 5923 Relaisausgang 2 RelCl
#define ENUM5924 ENUM5920               // Thision 5924 Relaisausgang 3 RelCl
#define ENUM5926 ENUM5920               // Thision 5926 Relaisausgang 1 SolCl
#define ENUM5927 ENUM5920               // Thision 5927 Relaisausgang 2 SolCl
#define ENUM5928 ENUM5920               // Thision 5928 Relaisausgang 3 SolCl

// Konfiguration - Fuehlereingang BX1
const char ENUM5930[] PROGMEM_LATEST = {
"\x00 Kein\0"
"\x01 Trinkwasserfühler B31\0"
"\x02 Kollektorfühler B6\0"
"\x03 Rücklauffühler B7\0"
"\x04 TWW Zirkulationsfühler B39\0"
"\x05 Pufferspeicherfühler B4\0"
"\x06 Pufferspeicherfühler B41\0"
"\x07 Abgastemperaturfühler B8\0"
"\x08 Schienenvorlauffühler B10\0"
"\x09 Feststoffkesselfühler B22\0"
"\x0a TWW Ladefühler B36\0"
"\x0b Pufferspeicherfühler B42\0"
"\x0c Schienenrücklauffühler B73\0"
"\x0d Kaskadenrücklauffühler B70\0"
"\x0e Schwimmbadfühler B13\0"
"\x0f Kollektorfühler 2 B61\0"
"\x10 Solarvorlauffühler B63\0"
"\x11 Solarrücklauffühler B64"
};

#define ENUM5931 ENUM5930               // Konfiguration - Fühlereingang BX 2
#define ENUM5932 ENUM5930               // Konfiguration - Fühlereingang BX 3
#define ENUM5933 ENUM5930               // Konfiguration - Fühlereingang BX 4
#define ENUM5941 ENUM5930               // Konfiguration - Fühlereingang BX21
#define ENUM5942 ENUM5930               // Konfiguration - Fühlereingang BX22


// Konfiguration - Funktion Eingang H1 (LOGON B)
const char ENUM5950[] PROGMEM_LATEST = {
"\x01 BA-Umschaltung HK's + TWW\0"
"\x02 BA-Umschaltung HK's\0"
"\x03 BA-Umschaltung HK1\0"
"\x04 BA-Umschaltung HK2\0"
"\x05 BA-Umschaltung HKP\0"
"\x06 Erzeugersperre\0"
"\x07 Fehler- / Alarmmeldung\0"
"\x08 Minimaler Vorlaufsollwert\0"
"\x09 Übertemperaturableitung\0"
"\x0a Freigabe Schwimmbad\0"
"\x0b Taupunktwächter\0"
"\x0c Vorlaufsollw'anhebung Hygro\0"
"\x0d Wärmeanforderung 10V\0"
"\x0e Druckmessung 10V"
};

// Konfiguration - Funktion Eingang H1 THISION
const char ENUM5950_2[] PROGMEM_LATEST = {
"\x00 Keine Funktion\0"
"\x01 Modemfunktion\0"
"\x02 Modemfunktion invers\0"
"\x03 Torschleierfunktion\0"
"\x07 Rückmeldung AbgKlp\0"
"\x08 Erzeugersperre\0"
"\x09 Erzeugersperre invers"
};

// Konfiguration - Funktion Eingang H1 Brötje
const char ENUM5950_3[] PROGMEM_LATEST = {
"\x01 BA-Umschaltung HK's + TWW\0"
"\x02 BA-Umschaltung HK's\0"
"\x03 BA-Umschaltung HK1\0"
"\x04 BA-Umschaltung HK2\0"
"\x05 BA-Umschaltung HKP\0"
"\x06 Erzeugersperre\0"
"\x07 Fehler- / Alarmmeldung\0"
"\x08 Minimaler Vorlaufsollwert\0"
"\x09 Wärmeanforderung 10V"
};

// Konfiguration - Funktion Eingang H1 Brötje BOB
const char ENUM5950_4[] PROGMEM_LATEST = {
"\x00 Keine\0"
"\x01 BA-Umschaltung HK's + TWW\0"
"\x02 BA-Umschaltung TWW\0"
"\x03 BA-Umschaltung HK's\0"
"\x04 BA-Umschaltung HK1\0"
"\x05 BA-Umschaltung HK2\0"
"\x06 BA-Umschaltung HK3\0"
"\x07 Erzeugersperre\0"
"\x08 Fehler- / Alarmmeldung\0"
"\x09 Verbr'anforderung VK1\0"
"\x0a Verbr'anforderung VK2\0"
"\x0b Freigabe Schw'bad Erzeuger\0"
"\x0c Übertemperaturableitung\0"
"\x0d Freigabe Schw'bad Erzeuger Solar\0"
"\x0e Betriebsniveau TWW\0"
"\x0f Betriebsniveau HK1\0"
"\x10 Betriebsniveau HK2\0"
"\x11 Betriebsniveau HK3\0"
"\x12 Raumthermostat HK1\0"
"\x13 Raumthermostat HK2\0"
"\x14 Raumthermostat HK3\0"
"\x16 Trinkwasserthermostat\0"
"\x17 Zirk'pumpenthermostat\0"
"\x18 Impulszählung\0"
"\x1d Startverhinderung\0"
"\x1e Kessel-Rückflussthermostat\0"
"\x32 Durchflussmessung Hz\0"
"\x33 Verbraucheranforderung VK1 10V\0"
"\x34 Verbraucheranforderung VK2 10V\0"
"\x38 Raumtemperatur 10V"
};

const char ENUM5950_5[] PROGMEM_LATEST = {
"\x01 BA-Umschaltung HK's + TWW\0"
"\x02 BA-Umschaltung HK's\0"
"\x03 BA-Umschaltung HK1\0"
"\x04 BA-Umschaltung HK2\0"
"\x05 BA-Umschaltung HKP\0"
"\x06 Erzeugersperre\0"
"\x07 Fehler- / Alarmmeldung\0"
"\x08 Minimaler Vorlaufsollwert\0"
"\x09 Übertemperaturableitung\0"
"\x0a Freigabe Schwimmbad\0"
"\x0b Taupunktwächter\0"
"\x0c Vorlaufsollw'anhebung Hygro\0"
"\x0d Kälteanforderung\0"
"\x0e Wärmeanforderung 10V\0"
"\x0f Kälteanforderung 10V\0"
"\x11 Relative Raumfeuchte 10V\0"
"\x12 Raumtemperatur 10V"};

// Konfiguration - Funktion Eingang H1 RVA63.244
const char ENUM5950_6[] PROGMEM_LATEST = {
"\x00 BA-Umschaltung HK's + TWW\0"
"\x01 BA-Umschaltung alle HK\0"
"\x02 Minimal-Vorlauftemperatur-Sollwert (TVHw)\0"
"\x03 Wärmeerzeuger-Sperre\0"
"\x04 Wärmeanforderung 0-10V"
};

const char ENUM5951[] PROGMEM_LATEST = {"\x00 Ruhekontakt\0\x01 Arbeitskontakt"};

// Konfiguration - 5957 BA-Umschaltung HK's+TWW
const char ENUM5957[] PROGMEM_LATEST = {
  "\x01 in allen Heizkreisen und Trinkwasser\0"
  "\x02 in allen Heizkreisen\0"
  "\x03 in Heizkreis 1\0"
  "\x04 in Heizkreis 2"
};

const char ENUM5957_2[] PROGMEM_LATEST = {
  "\x00 in allen Heizkreisen und Trinkwasser\0"
  "\x01 in allen Heizkreisen\0"
  "\x02 Minimal-Vorlauftemperatur-Sollwert (TVHw)\0"
  "\x03 Wärmeerzeuger-Sperre\0"
  "\x04 Wärmeanforderung 0...10 V"
};

#define ENUM5960 ENUM5950               // Konfiguration - Funktion Eingang H3
#define ENUM5960_2 ENUM5950_2           // Konfiguration - Funktion Eingang H3

const char ENUM5960_3[] PROGMEM_LATEST = {
"\x00 Brauchwassertemperatur-Fühler 2\0"
"\x01 Minimal-Vorlauftemperatur-Sollwert (TVHw)\0"
"\x02 Wärmeerzeuger-Sperre\0"
"\x03 Puffertemperatur-Fühler 2\0"
};

#define ENUM5961 ENUM5951               // Konfiguration - Wirksinn Kontakt H3
#define ENUM5961_2 ENUM5951             // Konfiguration - Wirksinn Kontakt H3

// Konfiguration - Thision 5970 Konfig Raumthermostat 1
const char ENUM5970[] PROGMEM_LATEST = {
"\x00 Kein\0"
"\x01 Raumthermostat\0"
"\x02 Schaltuhr Raumniveau\0"
"\x03 Schaltuhr Heizungsanforderung\0"
"\x04 Schaltuhr TWW Niveau"
};
#define ENUM5970_2 ENUM5950_4

#define ENUM5971 ENUM5970               // Thision 5971 Konfig Raumthermostat 2
#define ENUM5971_2 ENUM5951

// Konfiguration - Thision 5973 Funktion Eingang RelCl
const char ENUM5973[] PROGMEM_LATEST = {
"\x00 Keine Funktion\0"
"\x01 Modemfunktion\0"
"\x02 Modemfunktion invers\0"
"\x03 Torschleierfunktion\0"
"\x04 Sollwertvorgabe\0"
"\x05 Leistungsvorgabe\0"
"\x06 Fühler hydraulische Weiche\0"
"\x07 Rückmeldung AbgKlp\0"
"\x08 Erzeugersperre\0"
"\x09 Erzeugersperre invers\0"
"\x0b Erzeugersperre Fühler"
};

#define ENUM5977_2 ENUM5970_2

// Konfiguration - Thision 5978 Funktion Eingang SolCl
const char ENUM5978[] PROGMEM_LATEST = {
"\x00 kein\0"
"\x0a Kollektor Fühler"
};

#define ENUM5978_2 ENUM5971_2

// 5980 Konfiguration - Funktion Eingang EX1
// The System-Handbuch does not document numerical values.
const char ENUM5980[] PROGMEM_LATEST = {
  "\x00 Keine\0"
  "\x01 EWSperre E6\0"
  "\x02 Niedertarif E5\0"
  "\x03 ?Überlast Quelle E14\0"
  "\x04 ?Druckwächter Quelle E26\0"
  "\x05 ?Ström'wächter Quelle E15\0"
  "\x06 ?Ström'wächter Verbrau E24\0"
  "\x07 ?Abtauen manuell E17\0"
  "\x08 ?Sammelstörung WP E20\0"
  "\x09 ?Störung Sanftanlasser E25\0"
  "\x0a ?Niederdruckwächter E9\0"
  "\x0b ?Hochdruckwächter E10\0"
  "\x0c ?Überlast Verdichter 1 E11\0"
  "\x0f Fehler- / Alarmmeldung\0"
  "\x10 ?Netzüberwachung E21\0"
  "\x11 ?Druckdiff Abtauen E28\0"
  "\x12 ?Druckw Quellzw'kreis E29\0"
  "\x13 ?Strömw Quellzw'kreis E30\0"
  "\x14 ?Smart Grid E61\0"
  "\x15 ?Smart Grid E62\0"
  "\x16 ?BA-Umschaltung HK's\0"
  "\x1a Trinkwasser Push"
};

#define ENUM5981 ENUM5951               // Konfiguration - Wirksinn Eingang EX1

// Konfiguration - Funktion Eingang EX2
const char ENUM5982[] PROGMEM_LATEST = {
"\x01 Zähler 2.Brennerstufe\0"
"\x02 Erzeugersperre\0"
"\x03 Fehler- / Alarmmeldung\0"
"\x04 STB Fehlermeldung\0"
"\x05 Übertemperaturableitung"};

#define ENUM5983 ENUM5951               // Konfiguration - Wirksinn Eingang EX2
#define ENUM5984 ENUM5980               // Konfiguration - 5984 Funktion Eingang EX3
#define ENUM5985 ENUM5951               // Konfiguration - Wirksinn Eingang EX3
#define ENUM5986 ENUM5980               // Konfiguration - 5986 Funktion Eingang EX4
#define ENUM5987 ENUM5951               // Konfiguration - Wirksinn Eingang EX4
#define ENUM5989 ENUM5951               // Konfiguration - Wirksinn Eingang EX5

// Konfiguration - 5988 Funktion Eingang EX5
// The System-Handbuch does not document numerical values.
// !FIXME! Values here are hypothetical.
const char ENUM5988[] PROGMEM_LATEST = {
  "\x00 ?Keine\0"
  "\x01 ?EWSperre E6\0"
  "\x02 ?Niedertarif E5\0"
  "\x03 ?Überlast Quelle E14\0"
  "\x04 ?Druckwächter Quelle E26\0"
  "\x05 ?Ström'wächter Quelle E15\0"
  "\x06 ?Ström'wächter Verbrau E24\0"
  "\x07 ?Abtauen manuell E17\0"
  "\x08 ?Sammelstörung WP E20\0"
  "\x09 ?Störung Sanftanlasser E25\0"
  "\x0a ?Niederdruckwächter E9\0"
  "\x0b ?Hochdruckwächter E10\0"
  "\x0c ?Überlast Verdichter 1 E11\0"
  "\x0d ?Fehler- / Alarmmeldung\0"
  "\x0e ?Drehstrom E21\0"
  "\x0f ?Drehstrom E22\0"
  "\x10 ?Drehstrom E23"
};
#define ENUM5990 ENUM5988           // Konfiguration - 5990 Funktion Eingang EX6
#define ENUM5992 ENUM5988           // Konfiguration - 5992 Funktion Eingang EX7

// Konfiguration - Funktion Mischergruppe 1
const char ENUM6014[] PROGMEM_LATEST = {
"\x01 Heizkreis 1\0"
"\x02 Rücklaufregler\0"           // ISR-SSR Solarsystemregler Handbuch
"\x03 Vorregler / Zubringerpumpe\0"
"\x04 Trinkwasser Vorregler\0"
"\x05 Trinkwasser Durchl'erhitzer\0"
"\x06 Rücklaufregler Kaskade"
};
#define ENUM6015 ENUM6014           // Konfiguration - 6015 Funktion Mischergruppe 2

// Konfiguration - Funktion Erweiterungsmodul 1
const char ENUM6020[] PROGMEM_LATEST = {
"\x00 Keine Funktion\0"
"\x01 Multifunktional\0"
"\x02 Heizkreis 2\0"
"\x03 Rücklaufregler\0"
"\x04 Solar Trinkwasser\0"
"\x05 Vorregler / Zubringerpumpe\0"
"\x06 Trinkwasser Vorregler\0"
"\x07 Trinkwasser Durchl'erhitzer\0"
"\x08 Rücklaufregler Kaskade"
};
#define ENUM6021 ENUM6020           // Konfiguration - Funktion Erweiterungsmodul 2


// The predominant reason why this ProgNr (6030) has been included is the mention of
// Solarstellglied Puffer and Solarstellglied Schwimmbad. My search for these
// names lead me here.  It seems that Relaisausgang QX21 is (a) unused and
// (b) not supported in all installations. (comment by miwi)

// Konfiguration - Relaisausgang QX21
// The Broetje System-Handbuch ISR Plus does not document numerical values;
// inserting hypothetical values.
// !FIXME! !TODO! Figure out the real numerical values.
const char ENUM6030[] PROGMEM_LATEST = {
  "\x00 ?Kein\0"                           // with all controllers
  "\x01 ?Heizkreispumpe HK1 Q2\0"          // with      BSW,BLW
  "\x02 ?Trinkwasserstellglied Q3\0"       // with      BSW,BLW
  "\x03 ?Verdichterstufe 2 K2\0"           // with      BSW
  "\x04 ?Prozessumkehrventil Y22\0"        // with      BSW,BLW
  "\x05 ?Heissgastemperatur K31\0"         // with      BSW,BLW
  "\x06 ?Elektroeinsatz 1 Vorlauf K25\0"   // with      BSW,BLW
  "\x07 ?Elektroeinsatz 2 Vorlauf K26\0"   // with      BSW,BLW
  "\x07 ?Umlenkventil Kühl Quelle Y28\0"   // with      BSW,BLW
  "\x08 ?Zirkulationspumpe Q4\0"           // with      BSW,BLW, BCA,        Kessel L,TE,SOB
  "\x09 ?Elektroeinsatz TWW K6\0"          // with SSR, BSW,BLW, BCA,        Kessel L,TE,SOB
  "\x0a ?Elektroeinsatz Puffer K16\0"      // with SSR, BSW,BLW
  "\x0b ?Kollektorpumpe Q5\0"              // with SSR, BSW,BLW,             Kessel L,TE,SOB
  "\x0c ?H1-Pumpe Q15\0"                   // all controllers
  "\x0d ?Kesselpumpe Q1\0"                 // with SSR, BSW,     BCA,        Kessel L,TE,SOB
  "\x0e ?Bypasspumpe Q12\0"                // with SSR, BSW,BLW, BCA, ZR1/2, Kessel L,TE,SOB
  "\x0f ?Alarmausgang K10\0"               // with all controllers
  "\x10 ?2. Pumpenstufe HK1 Q21\0"         // with SSR, BSW,     BCA, ZR1/2, Kessel L,TE,SOB
  "\x11 ?2. Pumpenstufe HK2 Q22\0"         // with SSR, BSW,     BCA, ZR1/2, Kessel L,TE,SOB
  "\x12 ?2. Pumpenstufe HKP Q23\0"         // with SSR, BSW,     BCA, ZR1/2, Kessel L,TE,SOB
  "\x13 ?Heizkreispumpe HKP Q20\0"         // with all controllers
  "\x14 ?H2-Pumpe Q18\0"                   // with all controllers
  "\x15 ?Zubringerpumpe Q14\0"             // with all controllers
  "\x16 ?Erzeugersperrventil Y4\0"         // with SSR, BSW,                 Kessel L,TE,SOB
  "\x17 ?Feststoffkesselpumpe Q10\0"       // with SSR, BSW,BLW, BCA
  "\x18 ?Zeitprogramm 5 K13\0"             // with SSR, BSW           ZR1/2
  "\x19 ?Pufferrücklaufventil Y15\0"       // with SSR, BSW
  "\x1a ?Solarpumpe ext. Tauscher K9\0"    // with SSR, BSW,BLW
  "\x1b ?Solarstellglied Puffer K8\0"      // with SSR, BSW,BLW
  "\x1c ?Solarstellglied Schwimmbad K18\0" // with SSR, BSW,BLW
  "\x1d ?Kollektorpumpe 2 Q16\0"           // with SSR, BSW
  "\x1e ?H3-Pumpe Q19\0"                   // with      BSW,BLW
  "\x1f ?Abgasrelais K17\0"                // with      BSW,     BCA
  "\x20 ?Umlenkventil Kühlen Y21\0"        // with      BSW,BLW,      ZR1/2
  "\x21 ?Umlenkventil Kühl Quelle Y28\0"   // with      BSW
  "\x22 ?Quell'pumpe Q8\0"                 // with      BSW,BLW
  "\x23 ?Ventilator K19\0"                 // with      BSW
  "\x24 ?Kondensatorpumpe Q9\0"            // with SSR, BSW,BLW
  "\x25 ?Luftentfeuchter K29\0"            // with SSR, BSW,BLW       ZR1/2
  "\x26 ?Kaskadenpumpe Q25\0"              // with SSR, BSW,BLW, BCA
  "\x27 ?Speicherumladepumpe Q11\0"        // with SSR, BSW
  "\x28 ?TWW Durchmischpumpe Q35\0"        // with BSW,          BCA
  "\x29 ?TWW Zwisch'kreispumpe Q33\0"      // with SSR, BSW,     BCA
  "\x2a ?Wärmeanforderung K27\0"           // with      BSW,BLW  BCA, ZR1/2
  "\x2b ?Kälteanforderung K28\0"           // with      BSW,BLW       ZR1/2
  "\x2c ?Verdichterstufe 1 K1\0"           // with          BLW
  "\x2d ?Zusatzerzeuger Regelung K32"    // with          BLW
};

#define ENUM6031 ENUM6030
#define ENUM6032 ENUM6030
// #define ENUM6033 ENUM6030     // Relaisausgang QX21 Modul 2 / identity with 6030: analogous guess
// #define ENUM6034 ENUM6030     // Relaisausgang QX22 Modul 2 / identity with 6030: analogous guess
// #define ENUM6035 ENUM6030     // Relaisausgang QX23 Modul 2 / identity with 6030: analogous guess

// Konfiguration - 6040 Fühlereingang BX21
const char ENUM6040[] PROGMEM_LATEST = {
  "\x00 Kein\0"
  "\x01 Trinkwasserfühler B31\0"
  "\x02 Kollektorfühler B6\0"
  "\x03 ---\0"
  "\x04 TWW Zirkulationsfühler B39\0"
  "\x05 Pufferspeicherfühler B4\0"
  "\x06 Pufferspeicherfühler B41\0"
  "\x07 Abgastemperaturfühler B8\0"
  "\x08 Schienenvorlauffühler B10\0"
  "\x09 Feststoffkesselfühler B22\0"
  "\x0a TWW Ladefühler B36\0"
  "\x0b Pufferspeicherfühler B42\0"
  "\x0c Schienenrücklauffühler B73\0"
  "\x0d Kaskadenrücklauffühler B70\0"
  "\x0e Schwimmbadfühler B13\0"
  "\x0f Kollektorfühler 2 B61\0"
  "\x10 Solarvorlauffühler B63\0"
  "\x11 Solarrücklauffühler B64"
};
#define ENUM6041 ENUM6040	// Konfiguration - 6041 Fühlereingang BX22
// #define ENUM6042 ENUM6040 // Fühlereingang BX21 Modul 2 / identity with 6040: analogous guess
// #define ENUM6043 ENUM6040 // Fühlereingang BX22 Modul 2 / identity with 6040: analogous guess
#define ENUM6046 ENUM5950	// Konfiguration - Funktion Eingang H2
#define ENUM6046_2 ENUM5977_2  // Konfiguration - Funktion Kontakt H2 EM1
#define ENUM6047 ENUM5951	// Konfiguration - Wirksinn Kontakt H2
#define ENUM6047_2 ENUM5978_2  // Konfiguration - Wirksinn Eingang H2 EM1
// Konfiguration - 6070 Funktion Ausgang UX
const char ENUM6070[] PROGMEM_LATEST = {"\x00 Kesselsollwert\0\x01 Leistungsanforderung\0\x02 Wärmeanforderung"};
// Konfiguration - 6071 Signallogik Ausgang UX
const char ENUM6071[] PROGMEM_LATEST = {"\x00 Standard\0\x01 Invertiert"};

const char ENUM6085[] PROGMEM_LATEST = {
"\x00 Keine\0"
"\x01 Kesselpumpe Q1\0"
"\x02 Trinkwasserpumpe Q3\0"
"\x04 Heizkreispumpe HK1 Q2\0"
"\x05 Heizkreispumpe HK2 Q6\0"
"\x06 Heizkreispumpe HK3 Q20\0"
"\x07 Kollektorpumpe Q5"
};

// Konfiguration - Fühlertyp Kollektor
const char ENUM6097[] PROGMEM_LATEST = {"\x01 NTC\0\x02 Pt 1000"};
#define ENUM6101 ENUM6097           // Fühlertyp Abgastemperatur

// Konfiguration - Wärm'anfo bei Ökobetrieb AUS| EIN Trinkwasser | ein
const char ENUM6131[] PROGMEM_LATEST = {
"\x00 Aus\0"
"\x01 Ein Trinkwasser\0"
"\x02 Ein"
};

const char ENUM6136[] PROGMEM_LATEST = {
"\x01 24/Tag\0"
"\x02 Zeitprogramm Heizkreis\0"
"\x03 Zeitprogramm 5"
};


// Konfiguration - KonfigRG0

const char ENUM6230[] PROGMEM_LATEST = {
"\x00\x01 Fühlerunterbruch Rücklauffühler unterdrücken\0"
"\x01\x01 Fühlerunterbruch Rücklauffühler ausgeben\0"
"\x00\x02 Fühlerunterbruch Trinkwasserfühler unterdrücken\0"
"\x02\x02 Fühlerunterbruch Trinkwasserfühler ausgeben\0"
"\x00\x04 Fühlerunterbruch Abgastemperaturfühler unterdrücken\0"
"\x04\x04 Fühlerunterbruch Abgastemperaturfühler ausgeben\0"
"\x00\x08 Fühlerunterbruch Außentemperaturfühler unterdrücken\0"
"\x08\x08 Fühlerunterbruch Außentemperaturfühler ausgeben\0"
"\x00\x10 Fühlerunterbruch Wasserdruckfühler unterdrücken\0"
"\x10\x10 Fühlerunterbruch Wasserdruckfühler ausgeben\0"
"\x00\x20 Fühlerunterbruch Vorlauffühler unterdrücken\0"
"\x20\x20 Fühlerunterbruch Vorlauffühler ausgeben\0"
"\x00\x40 Fühlerunterbruch Fühler am ClipIn unterdrücken\0"
"\x40\x40 Fühlerunterbruch Fühler am ClipIn ausgeben"
};

// Konfiguration - KonfigRG1

const char ENUM6240[] PROGMEM_LATEST = {
"\x00\x03 Vorrang Trinkwasser: absolut\0"
"\x01\x03 Vorrang Trinkwasser: gleitend\0"
"\x02\x03 Vorrang Trinkwasser: kein\0"
"\x00\x08 Klemmenbelegung RT: RT\0"
"\x08\x08 Klemmenbelegung RT: Schaltuhr\0"
"\x00\x10 Anlagenfrostschutz aus\0"
"\x10\x10 Anlagenfrostschutz ein\0"
"\x00\x80 Betriebsart des Heizkreises bei Modemfunktion: Standby\0"
"\x80\x80 Betriebsart des Heizkreises bei Modemfunktion: Reduz."
};

// Konfiguration - KonfigRG2

const char ENUM6250[] PROGMEM_LATEST = {
"\x00\x01 Pumpennachlauf TWW in den Heizkreis\0"
"\x01\x01 Pumpennachlauf TWW in den TWW-Wärmetauscher\0"
"\x00\x02 Komforttemperaturniveau wie Auslauftemp.\0"
"\x02\x02 Komforttemperaturniveau wie Bereitschaftstemp.\0"
"\x00\x0B Komfort PID Regelungsfühler: Kesselvorlauf\0"
"\x04\x0B Komfort PID Regelungsfühler: TWW-Fühler\0"
"\x08\x0B Komfort PID Regelungsfühler: Kesselrücklauf\0"
"\x00\x30 Fühleranordnung Schichtenspeicher SSP: KVF\0"
"\x10\x30 Fühleranordnung Schichtenspeicher SSP: KRF, nicht bei SSP\0"
"\x20\x30 Fühleranordnung Schichtenspeicher SSP: KRF, nur SSP"
};

// Konfiguration - KonfigRG3

const char ENUM6260[] PROGMEM_LATEST = {
"\x01\x1F AD-Wandler Eingänge Konfiguration 1\0"
"\x02\x1F AD-Wandler Eingänge Konfiguration 2\0"
"\x03\x1F AD-Wandler Eingänge Konfiguration 3\0"
"\x04\x1F AD-Wandler Eingänge Konfiguration 4\0"
"\x05\x1F AD-Wandler Eingänge Konfiguration 5\0"
"\x06\x1F AD-Wandler Eingänge Konfiguration 6\0"
"\x07\x1F AD-Wandler Eingänge Konfiguration 7\0"
"\x00\x20 AD-Wandler Heizanforderung 1: nach Bedarf\0"
"\x20\x20 AD-Wandler Heizanforderung 1: permanent\0"
"\x00\x40 AD-Wandler Heizanforderung 2: nach Bedarf\0"
"\x40\x40 AD-Wandler Heizanforderung 2: permanent\0"
"\x00\x80 AD-Wandler Heizanforderung Zone: nach Bedarf\0"
"\x80\x80 AD-Wandler Heizanforderung Zone: permanent"
};

// Konfiguration - KonfigRG4

const char ENUM6270[] PROGMEM_LATEST = {
"\x00\x01 Zubringerfunktion Q8: aus\0"
"\x01\x01 Zubringerfunktion Q8: ein\0"
"\x00\x02 Gebäudebauweise: leicht\0"
"\x02\x02 Gebäudebauweise: schwer\0"
"\x00\x04 Anschlussklemme TW-Thermostat: Fühler an X10/TWF\0"
"\x04\x04 Anschlussklemme TW-Thermostat: Thermostat an X10/TWF\0"
"\x00\xE0 Konfiguration 3-Wege-Ventil: kein\0"
"\x20\xE0 Konfiguration 3-Wege-Ventil: Magnetventil\0"
"\x40\xE0 Konfiguration 3-Wege-Ventil: Motorventil\0"
"\x60\xE0 Konfiguration 3-Wege-Ventil: Motorventil invers"
};

const char ENUM6272[] PROGMEM_LATEST = {
"\x00 Kein\0"
"\x06 Pufferspeicherfühler B41\0"
"\x07 Abgastemperaturfühler B8\0"
"\x08 Schienenvorlauffühler B10\0"
"\x09 Feststoffkesselfühler B22\0"
"\x0B Pufferspeicherfühler B42\0"
"\x0C Schienenrücklauffühler B73\0"
"\x0D Kaskadenrücklauffühler B70\0"
"\x0E Schwimmbadfühler B13\0"
"\x15 Kesselfühler B2\0"
"\x18 Trinkwasserfühler B3\0"
};

// Konfiguration - KonfigRG5

const char ENUM6280[] PROGMEM_LATEST = {
"\x00\x03 Wassermangelsicherung Strömungswächter->Störstellung\0"
"\x01\x03 Wassermangelsicherung Strömungswächter->Startverhinderung\0"
"\x02\x03 Wassermangelsicherung Wasserdruckwächter->Störstellung\0"
"\x03\x03 Wassermangelsicherung Wasserdruckwächter->Startverhinderung\0"
"\x00\x04 Wassermangelsicherung Drehzahlbegrenzung aus\0"
"\x04\x04 Wassermangelsicherung Drehzahlbegrenzung ein\0"
"\x00\xF8 Bits 3-7: Grundeinstellung; nicht verändern!"
};

// Konfiguration - KonfigRG6

const char ENUM6290[] PROGMEM_LATEST = {
"\x00\x01 Initialisierung ISR: Sofort. Übernahme Stellgröße n. Freig.\0"
"\x01\x01 Initialisierung ISR: Stoßfreier Übergang n. Freig.\0"
"\x00\x02 Verriegelung Fremd-Room Units: aus\0"
"\x02\x02 Verriegelung Fremd-Room Units: ein\0"
"\x00\x04 Quelle BW-Sollwert: RU\0"
"\x04\x04 Quelle BW-Sollwert: HMI\0"
"\x00\x08 Sperrsignalberechnung deaktiviert\0"
"\x08\x08 Sperrsignalberechnung aktiviert\0"
"\x00\x20 Schnelle Wechsel der Drehzahlgrenzen: Normale Abarb.\0"
"\x20\x20 Schnelle Wechsel der Drehzahlgrenzen: Beschleunigt\0"
"\x00\x40 Initialisierung ISR: Nur bei Betriebsartwechsel\0"
"\x40\x40 Initialisierung ISR: Immer bei Brennerstart\0"
"\x00\x80 PWM-Gebläserampen: aus\0"
"\x80\x80 PWM-Gebläserampen: ein"
};

// Konfiguration - KonfigRG7

const char ENUM6300[] PROGMEM_LATEST = {
"\x00\x01 Heizkreispumpe: stufig\0"
"\x01\x01 Heizkreispumpe: modulierend\0"
"\x00\x02 Delta-T-Begrenzung: aus\0"
"\x02\x02 Delta-T-Begrenzung: ein\0"
"\x00\x04 Delta-T-Überwachung: aus\0"
"\x04\x04 Delta-T-Überwachung: ein\0"
"\x00\x18 Anlagenvolumen: klein\0"
"\x08\x18 Anlagenvolumen: mittel\0"
"\x10\x18 Anlagenvolumen: groß\0"
"\x00\x20 Delta-T-Überwachung im Reduz.-Betrieb: aus\0"
"\x20\x20 Delta-T-Überwachung im Reduz.-Betrieb: ein\0"
"\x00\x40 Reglerverzögerung: nur im Heizbetrieb aktiv\0"
"\x40\x40 Reglerverzögerung: in allen Betriebsarten aktiv\0"
"\x00\x80 Pumpe Q1 Modulation in Syst. 51,54,55,67,70,71: aus\0"
"\x80\x80 Pumpe Q1 Modulation in Syst. 51,54,55,67,70,71: ein"
};

// Konfiguration - KonfigRG8

const char ENUM6310[] PROGMEM_LATEST = {
"\x00\x0F Sekundärtauscher: Plattenwärmetauscher\0"
"\x01\x0F Sekundärtauscher: Wendelwärmetauscher primärseitig\0"
"\x02\x0F Sekundärtauscher: Wendelwärmetauscher sekundärs.\0"
"\x00\x10 1. Maximum Durchlauferhitzer-Regelung: auswerten\0"
"\x10\x10 1. Maximum Durchlauferhitzer-Regelung: ignorieren\0"
"\x00\x20 Durchlauferhitzer Anfrage über DLH1 Sensor oder Flow-Switch\0"
"\x20\x20 Durchl.Erh.Anfrage nur über Flow-Switch\0"
"\x00\x40 Position von Verteilventil nach Durchlauferhitzer.: Letzte\0"
"\x40\x40 Position von Verteilventil nach Durchlauferhitzer.: Heizpos."
};

// Konfiguration - KonfigRG10

const char ENUM6330[] PROGMEM_LATEST = {
"\x00\x01 Kesselpumpe bei Brennersperre: keine Abschaltung\0"
"\x01\x01 Kesselpumpe bei Brennersperre: Abschaltung\0"
"\x00\x02 Brennersperre nur bei Heizanforderung\0"
"\x02\x02 Brennersperre nur bei Heiz- und TWW-Anforderung\0"
"\x00\x04 Durchlauferhitzertaktschutz durch Temperaturerhöhung: aus\0"
"\x04\x04 Durchlauferhitzertaktschutz durch Temperaturerhöhung: ein\0"
"\x00\x08 Position des TWW-Speichers: vor hydraulischer Weiche\0"
"\x08\x08 Position des TWW-Speichers: nach hydraulischer Weiche\0"
"\x00\x10 Zubringerpumpe bei Brennersperre: keine Abschaltung\0"
"\x10\x10 Zubringerpumpe bei Brennersperre: Abschaltung\0"
"\x00\x20 Gebläseabschaltung bei Heizanforderung: Freigabe\0"
"\x20\x20 Gebläseabschaltung bei Heizanforderung: keine Freigabe\0"
"\x00\x40 Pumpennachlauf TWW bei weiteren Wärmeanf.: Unterdrücken\0"
"\x40\x40 Pumpennachlauf TWW bei weiteren Wärmeanf.: Durchführen"
};

// Konfiguration - Relaisausgang QX35  //FUJITSU
const char ENUM6375[] PROGMEM_LATEST = {
"\x00 Kein\0"
"\x02 Prozessumkehrventil Y22\0"
"\x03 Heissgastemperatur K31\0"
"\x04 Elektroeinsatz1 Vorlauf K25\0"
"\x05 Elektroeinsatz2 Vorlauf K26\0"
"\x06 Umlenkventil Kühl Quelle Y28\0"
"\x07 Zubringerpumpe Q14\0"
"\x08 Kaskadenpumpe Q25\0"
"\x09 Erzeugersperrventil Y4\0"
"\x0a Elektroeinsatz TWW K6\0"
"\x0b Zirkulationspumpe Q4\0"
"\x0c Speicherumladepumpe Q11\0"
"\x0d TWW Zwisch'kreispumpe Q33\0"
"\x0e TWW Durchmischpumpe Q35\0"
"\x0f Kollektorpumpe Q5\0"
"\x10 Kollektorpumpe 2 Q16\0"
"\x11 Solarpumpe ext.Tauscher K9\0"
"\x12 Solarstellglied Puffer K8\0"
"\x13 Solarstellglied Schw'bad K18\0"
"\x14 Elektroeinsatz Puffer K16\0"
"\x15 Verb'kreispumpe VK1 Q15\0"
"\x16 Verb'kreispumpe VK2 Q18\0"
"\x17 Schwimmbadpumpe Q19\0"
"\x18 Heizkreispumpe HK3 Q20\0"
"\x19 2. Pumpenstufe HK1 Q21\0"
"\x1a 2. Pumpenstufe HK2 Q22\0"
"\x1b 2. Pumpenstufe HK3 Q23\0"
"\x1c Umlenkventil HK/KK1 Y21\0"
"\x1d Luftentfeuchter K29\0"
"\x1e Wärmeanforderung K27\0"
"\x1f Kälteanforderung K28\0"
"\x20 Alarmausgang K10\0"
"\x21 Zeitprogramm 5 K13\0"
"\x22 Heizkreispumpe HK1 Q2\0"
"\x23 Trinkwasserstellglied Q3\0"
"\x24 Quell'pumoe Q8/Ventilat K19\0"
"\x25 Kondensatorpumpe Q9\0"
"\x26 Verdichterstufe 1 K1\0"
"\x27 Zus'erzeuger Regelung K32\0"
"\x28 unbelegt\0"
"\x29 Heizkreispumpe HK2 Q6\0"
"\x2a Durchl'erhitzerstellglied Q34\0"
"\x2b unbelegt\0"
"\x2c unbelegt\0"
"\x2d Umlenkventil HK/KK2 Y45\0"
"\x2e Umlenkventil HK/KK3 Y46\0"
"\x2f Kühlkreispumpe KK1 Q24\0"
"\x30 Kühlkreispumpe KK2 Q28\0"
"\x31 Kühlkreispumpe KK2 Q29\0"
"\x32 Feststoffkesselpumpe Q10\0"
"\x33 Abgasrelais K17\0"
"\x34 Anfeuer'hilfe Ventilator K30\0"
"\x35 Ölsumpfheizung K40\0"
"\x36 Abtropfwannenheizung K41\0"
"\x37 Ventil Verdampfer K81\0"
"\x38 Ventil EVI K82\0"
"\x39 Ventil Einspritzkapillare K83\0"
"\x3a 58\0"
"\x3b 59\0"
"\x3c 60"
};

// Konfiguration - Funktion Eingang H33  //FUJITSU
const char ENUM6420[] PROGMEM_LATEST = {
"\x00 Nicht verwendet\0"
"\x01 Betriebsartumschaltung HKW+TWW\0"
"\x02 Betriebsartumschaltung HKW\0"
"\x03 Betriebsartumschaltung HKW1\0"
"\x04 Betriebsartumschaltung HKW2\0"
"\x05 Betriebsartumschaltung HKP\0"
"\x06 Nicht verwendet\0"
"\x07 Nicht verwendet\0"
"\x08 Nicht verwendet\0"
"\x09 Nicht verwendet\0"
"\x0a Nicht verwendet\0"
"\x0b Betriebsartumschaltung Heizung Swimmingpool\0"
"\x0c Nicht verwendet\0"
"\x0d Nicht verwendet"
};

#define ENUM6421 ENUM5951               // Konfiguration - Wirksinn Kontakt H33 //FUJITSU

// LPB   - Busspeisung Funktion
const char ENUM6604[] PROGMEM_LATEST = {
"\x00 Aus\0"
"\x01 Automatisch"
};

// LPB   - LPBKonfig0

const char ENUM6606[] PROGMEM_LATEST = {
"\x00\x03 Uhrzeitlieferant Autonom\0"
"\x01\x03 Uhrzeitlieferant Slave ohne Fernverstellung\0"
"\x02\x03 Uhrzeitlieferant Slave mit Fernverstellung\0"
"\x03\x03 Uhrzeitlieferant Systemzeit Master\0"
"\x00\x04 Verteilte Busspeisung aus\0"
"\x04\x04 Verteilte Busspeisung Automatik\0"
"\x00\x08 Status Bussppeisung aus\0"
"\x08\x08 Status Busspeisung ein\0"
"\x00\x10 Ereignisverhalten nicht erlaubt\0"
"\x10\x10 Ereignisverhalten erlaubt\0"
"\x00\x60 Brauchwasserzuordnung Eigener Regler\0"
"\x20\x60 Brauchwasserzuordnung Alle Regler Segment\0"
"\x40\x60 Brauchwasserzuordnung Alle Regler Verbund\0"
"\x00\x80 Vorrang LMU-Anforderung aus\0"
"\x80\x80 Vorrang LMU-Anforderung ein"
};

// LPB   - Wirkbereich Umschaltungen
const char ENUM6620[] PROGMEM_LATEST = {
"\x00 Segment\0"
"\x01 System\0"
"\xff System"
};

// LPB   - Sommerumschaltung
const char ENUM6621[] PROGMEM_LATEST = {
"\x00 Lokal\0"
"\x01 Zentral\0"
"\xff Zentral"
};

const char ENUM6623[] PROGMEM_LATEST = {
"\x00 Lokal\0"
"\x01 Zentral"
};

const char ENUM6624[] PROGMEM_LATEST = { // numerical values are hypothetical
"\x00 ?Lokal\0"
"\x01 ?Segment"
};

// LPB   - Trinkwasserzuordnung
// Texts in the ACS Programm: "Eigener Regler", "Alle Regler im eigenen Segment", "Alle Regler im Verbund"
const char ENUM6625[] PROGMEM_LATEST = {
"\x00 Lokale Heizkreise\0"
"\x01 Alle Heizkreise im Segment\0"
"\x02 Alle Heizkreise im System"
};

#define ENUM6627 ENUM6623

const char ENUM6630[] PROGMEM_LATEST = { // numerical values are hypothetical
"\x00 ?Immer\0"
"\x01 ?Automatisch"
};

const char ENUM6631[] PROGMEM_LATEST = {	// numerical values are hypothetical
  "\x00 ?Aus\0"
  "\x01 ?Ein Trinkwasser\0"
  "\x02 ?Ein"
};

// LPB   - Uhrbetrieb
const char ENUM6640[] PROGMEM_LATEST = {
"\x00 Autonom\0"
"\x01 Slave ohne Fernverstellung\0"
"\x02 Slave mit Fernverstellung\0"
"\x03 Master"
};
// !TODO! ProgNo 6670 is not defined elsewhere
const char ENUM6670[] PROGMEM_LATEST = {
"\x00 Kesselsollwert\0"
"\x01 Leistungsanforderung\0"
"\x02 Wärmeanforderung"
};

#define ENUM7119 ENUM2920    // ProgNr 7119 "Ökofunktion" FUJITSU

const char ENUM7131[] PROGMEM_LATEST = {
"\x01 Teillast\0"         // ENUM-Wert überprüfen!
"\x02 Volllast\0"
"\x03 Maximale Heizlast"  // ENUM-Wert überprüfen!
};

const char ENUM7142[] PROGMEM_LATEST = {
"\x01 Manuell\0"
"\x02 Automatisch"
};

const char ENUM7147[] PROGMEM_LATEST = {
"\x00 Keine\0"
"\x01 Heizkreis Dauerlauf\0"
"\x02 Heizkreis Getaktet\0"
"\x03 Trinkwasser Dauerlauf\0"
"\x04 Trinkwasser Getaktet"
}; // todo Hinweis: x00 Keine ist definitiv richtig. Die anderen muessen noch verifiziert werden.

const char ENUM7252[] PROGMEM_LATEST = {
"\x00 Keine Operation\0"
"\x01 Lesen von Stick\0"
"\x02 Schreiben auf Stick"
};

// Konfiguration Erweit'module - Relaisausgang QX21 Modul 2
const char ENUM7376[] PROGMEM_LATEST = {
"\x00 Kein\0"
"\x01 Zirkulationspumpe Q4\0"
//"\x02 Elektroeinsatz TWW K6\0"
"\x03 Kollektorpumpe Q5\0"
"\x04 Verbr'kreispumpe VK1 Q15\0"
//"\x05 Kesselpumpe Q1\0"
//"\x06 Bypasspumpe Q12\0"
"\x07 Alarmausgang K10\0"
//"\x08 2.Pumpenstufe HK1 Q21\0"
//"\x09 2.Pumpenstufe HK2 Q22\0"
//"\x0a 2.Pumpenstufe HKP Q23\0"
//"\x0b Heizkreispumpe HKP Q20\0"
//"\x0c H2-Pumpe Q18\0"
//"\x0d Zubringerpumpe Q14\0"
//"\x0e Erzeugersperrventil Y4\0"
//"\x0f Feststoffkesselpumpe Q10\0"
//"\x10 Zeitprogramm 5 K13\0"
//"\x11 Pufferrücklaufventil Y15\0"
//"\x12 Solarpumpe ext. Tauscher K9\0"
//"\x13 Solarstellglied Puffer K8\0"
//"\x14 Solarstellglied Schw'bad K18\0"
//"\x15 Kollektorpumpe 2 Q16\0"
//"\x16 H3-Pumpe Q19\0"
//"\x17 Abgasrelais K17\0"
//"\x19 Kaskadenpumpe Q25\0"
//"\x1a Speicherumladepumpe Q11\0"
"\x1b TWW Durchmischpumpe Q35\0"
//"\x1c TWW Zwisch'kreispumpe Q33\0"
//"\x1d Wärmeanforderung K27\0"
"\x21 Heizkreispumpe HK1 Q2\0"
"\x28 Meldeausgang K35\0"
"\x29 Betriebsmeldung K36"};


const char ENUM7425[] PROGMEM_LATEST = {
"\x00 0..10V\0"
"\x01 PWM"
};

// Ein-/Ausgangstest - Relaistest
const char ENUM7700[] PROGMEM_LATEST = {
"\x00 Kein Test\0"
"\x01 Alles aus\0"
"\x02 ---\0"
"\x03 ---\0"
"\x04 Trinkwasserpumpe Q3\0"
"\x05 Heizkreispumpe Q2\0"
"\x06 Heizkreismischer Auf Y1\0"
"\x07 Heizkreismischer Zu Y2\0"
"\x08 Heizkreispumpe Q6\0"
"\x09 Heizkreismischer Auf Y5\0"
"\x0a Heizkreismischer Zu Y6\0"
"\x0b Relaisausgang QX1\0"
"\x0c Relaisausgang QX2\0"
"\x0d Relaisausgang QX3\0"
"\x0e Relaisausgang QX4\0"
"\x0f Relaisausgang QX21 Modul 1\0"
"\x10 Relaisausgang QX22 Modul 1\0"
"\x11 Relaisausgang QX23 Modul 1\0"
"\x12 Relaisausgang QX21 Modul 2\0"
"\x13 Relaisausgang QX22 Modul 2\0"
"\x14 Relaisausgang QX23 Modul 2"
};

const char ENUM7700_2[] PROGMEM_LATEST = {
"\x00 Regelbetrieb nach Betriebszustand\0"
"\x01 Alle Ausgänge AUS\0"
"\x02 Brennerstufe 1 EIN K4\0"
"\x03 Brenerstufe 1 und 2 EIN K4 / K5\0"
"\x04 Brauchwasser-Ladepumpe EIN Q3 / Y3\0"
"\x05 Heizkreispumpe 1 / Q2\0"
"\x06 Mischer 1 auf Y1\0"
"\x07 Mischer 2 zu Y2\0"
"\x08 Multifunktionaler Ausgang EIN K6\0"
"\x09 Multifunktionaler Ausgang EIN K7"
};

//Eingangssignal H33  //FUJITSU
const char ENUM7999[] PROGMEM_LATEST = {
"\x00 Keine\0"
"\x01 Geschl'(ooo), Offen (---)\0"
"\x02 ?Puls\0"
"\x03 ?Frequenz Hz\0"
"\x04 ?Spannung V"
};

// Status Heizkreis 1, 2, 3
const char ENUM8000[] PROGMEM_LATEST = {
"\x00 ---\0"
"\x03 Wächter angesprochen\0"
"\x04 Handbetrieb aktiv\0"
"\x11 Nachlauf aktiv\0"
"\x16 Anlagenfrostschutz aktiv\0"
"\x17 Frostschutz aktiv\0"
"\x18 Aus\0"
"\x38 Überhitzschutz aktiv\0"
"\x65 Raumfrostschutz aktiv\0"
"\x66 Estrichfunktion aktiv\0"
"\x67 Eingeschränkt, Kesselschutz\0"
"\x68 Eingeschränkt, TWW-Vorrang\0"
"\x69 Eingeschränkt, Puffer\0"
"\x6a Heizbetrieb eingeschränkt\0"
"\x6b Zwangsabnahme Puffer\0"
"\x6c Zwangsabnahme TWW\0"
"\x6d Zwangsabnahme Erzeuger\0"
"\x6e Zwangsabnahme\0"
"\x6f Einschaltopt + Schnellaufheiz\0"
"\x70 Einschaltoptimierung\0"
"\x71 Schnellaufheizung\0"
"\x72 Heizbetrieb Komfort\0"
"\x73 Ausschaltoptimierung\0"
"\x74 Heizbetrieb Reduziert\0"
"\x75 Vorlauffrostschutz aktiv\0"
"\x76 Sommerbetrieb\0"
"\x77 Tages-Eco aktiv\0"
"\x78 Absenkung Reduziert\0"
"\x79 Absenkung Frostschutz\0"
"\x7a Raumtemp’begrenzung"};

#define ENUM8001 ENUM8000               // Status - Status Heizkreis 2
#define ENUM8002 ENUM8000               // Status - Status Heizkreis P/3


//Status Trinkwasser
const char ENUM8003[] PROGMEM_LATEST = {
"\x00 ---\0"
"\x03 Wächter angesprochen\0"
"\x04 Handbetrieb aktiv\0"
"\x11 Nachlauf aktiv\0"
"\x18 Frostschutz aktiv\0"
"\x19 Aus\0"
"\x35 Rückkühlung aktiv\0"
"\x42 Ladung Elektroeinsatz\0"
"\x43 Zwangsladung aktiv\0"
"\x45 Ladung aktiv\0"
"\x46 Geladen, Max Speichertemp\0"
"\x47 Geladen, Max Ladetemp\0"
"\x4b Geladen\0"
"\x4d Rückkühlung via Kollektor\0"
"\x4e Rückkühlung via Erz / Hk's\0"
"\x4f Entladeschutz aktiv\0"
"\x50 Ladezeitbegrenzung aktiv\0"
"\x51 Ladung gesperrt\0"
"\x52 Ladesperre aktiv\0"
"\x53 Zwang, Max Speichertemp\0"
"\x54 Zwang, Max Ladetemperatur\0"
"\x55 Zwang, Legionellensollwert\0"
"\x56 Zwang, Nennsollwert\0"
"\x57 Ladung Elektro, Leg’sollwert\0"
"\x58 Ladung Elektro, Nennsollwert\0"
"\x59 Ladung Elektro, Red’sollwert\0"
"\x5a Ladung Elektro, Fros’sollwert\0"
"\x5b Elektroeinsatz freigegeben\0"
"\x5c Push, Legionellensollwert\0"
"\x5d Push, Nennsollwert\0"
"\x5e Push aktiv\0"
"\x5f Ladung, Legionellensollwert\0"
"\x60 Ladung, Nennsollwert\0"
"\x61 Ladung, Reduziertsollwert\0"
"\x62 Geladen, Legio’temperatur\0"
"\x63 Geladen, Nenntemperatur\0"
"\x64 Geladen, Reduz’temperatur\0"
"\xc7 Zapfbetrieb\0"
"\xc8 Bereit\0"
"\xc9 Bereitschaftsladung"
};

//Status Kühlkreis 1  //FUJITSU
const char ENUM8004[] PROGMEM_LATEST = {
"\x00 ---\0"
"\x8A Kühlbetrieb aus"
};

//Status Kessel
const char ENUM8005[] PROGMEM_LATEST = {
"\x00 ---\0"
"\x01 STB angesprochen\0"
"\x02 Störung\0"
"\x03 Wächter angesprochen\0"
"\x04 Handbetrieb aktiv\0"
"\x05 Schornsteinfegerfkt, Vollast\0"
"\x06 Schornsteinfegerfkt, Teillast\0"
"\x07 Schornsteinfegerfkt aktiv\0"
"\x08 Gesperrt, Manuell\0"
"\x09 Gesperrt, Automatisch\0"
"\x0a Gesperrt\0"
"\x0b Anfahrentlastung\0"
"\x0c Anfahrentlastung, Teillast\0"
"\x0d Rückl’begrenzung\0"
"\x0e Rückl’begrenzung, Teillast\0"
"\x0f Freigegeben\0"
"\x10 Freigegeben, Teillast\0"
"\x11 Nachlauf aktiv\0"
"\x12 In Betrieb\0"
"\x13 Freigegeben\0"
"\x14 Minimalbegrenzung\0"
"\x15 Minimalbegrenzung, Teillast\0"
"\x16 Minimalbegrenzung aktiv\0"
"\x17 Anlagenfrostschutz aktiv\0"
"\x18 Frostschutz aktiv\0"
"\x19 Aus\0"
"\x3b Ladung Pufferspeicher\0"
"\x7b STB Test aktiv\0"
"\xa6 In Betrieb für Heizkreis\0"
"\xa7 In Teillastbetrieb für HK\0"
"\xa8 In Betrieb für Trinkwasser\0"
"\xa9 In Teillastbetrieb für TWW\0"
"\xaa In Betrieb für HK, TWW\0"
"\xab In Teillastbetrieb für HK, TWW\0"
"\xac Gesperrt, Feststoffkessel\0"
"\xad Freigegeben für HK, TWW\0"
"\xae Freigeben für TWW\0"
"\xaf Freigegeben für HK\0"
"\xb0 Gesperrt, Außentemperatur\0"
"\xc6 Gesperrt, Ökobetrieb"
};

//Status Waermepumpe  //FUJITSU
const char ENUM8006[] PROGMEM_LATEST = {
"\x00 ---\0"
"\x02 Störung\0"
"\x0A Gesperrt\0"      //10
"\x11 Nachlauf aktiv\0"      //17
"\x17 Anlagefrostschutz aktiv\0"
"\x18 Frostschutz aktiv\0"      //24
"\x19 Aus\0"      //25
"\x1a Notbetrieb\0"
"\x1b Gesperrt, extern\0"      //27
"\x1d HD bei WP-Betrieb\0"      //29
"\x1e Ström'wächter W'quelle\0"      //30
"\x1f Druckwächter W'quelle\0"      //31
"\x20 Begr Heissgas Verdichter 1\0"      //32
"\x21 Begr Heissgas Verdichter 2\0"      //33
"\x22 Begr Ausschalttemp Max\0"      //34
"\x23 Verd'stillstandzeit Min aktiv\0"
"\x24 Kompensat Wärmeüberschuss\0"      //36
"\x25 Begrenzungszeit aktiv\0"      //37
"\x26 Verd'laufzeit Min aktiv\0"
"\x27 Kompensation Wärmedefizit\0"      //39
"\x28 Begr Spreiz Kondens Max\0"      //40
"\x29 Begr Spreiz Kondens Min\0"      //41
"\x2a Begr Spreiz Verda Max\0"      //42
"\x2b Begr Spreiz Verda Min\0"      //43
"\x2c Verdichter und Elektro ein\0"      //44
"\x2d Verdichter 1 und 2 Ein\0"      //45
"\x2e Verdichter 1 Ein\0"
"\x2f Verdichter 2 Ein\0"      //47
"\x30 Frostschutz Wärmepumpe\0"      //48
"\x31 Vorlauf aktiv\0"
"\x33 Keine Anforderung\0"      //51
"\x32 Freigegeben, Verd bereit\0"
"\x33 keine Anforderung\0"
"\x7d Abtauen aktiv\0"
"\x7e Abtropfen\0"      //126
"\x7f Aktiver Kühlbetrieb\0"      //127
"\x80 Passiver Kühlbetrieb\0"      //128
"\x81 Abkühlen Verdampfer\0"      //129
"\x82 Vorwärmen für Abtauen\0"      //130
"\x89 Heizbetrieb\0"      //137
"\x8b Begr Ausschalttemp. Min\0"      //139
"\x91 Begr Aus'temp max Kühlen\0"      //145
"\xb0 Gesperrt, Aussentemperatur\0"
"\xb4 Drehstrom asymmetrisch\0"      //180
"\xb5 Niederdruck\0"      //181
"\xb6 Ventilator Überlast\0"      //182
"\xb7 Verdichter 1 Überlast\0"      //183
"\xb8 Verdichter 2 Überlast\0"      //184
"\xb9 Quellenpumpe Überlast\0"      //185
"\xba Ström'wächter Verbraucher\0"      //186
"\xbb Einsatzgrenze TA Min\0"      //187
"\xbc Einsatzgrenze TA Max\0"      //188
"\xbd Begr Quellentemp Min Wasser\0"      //189
"\xbe Begr Quellentemp Min Sole\0"      //190
"\xbf Begr Quellentemp Max\0"      //191
"\xc0 Zwangsabtauen Verdichter\0"      //192
"\xc1 Zwangsabtauen Ventilator\0"      //193
"\xc2 Abtauen mit Verdichter\0"      //194
"\xc3 Abtauen mit Ventilator\0"      //195
"\xc4 Begr Quellentemp Min Kühlen\0"      //196
"\xc5 Elektro Ein\0"      //197
"\xc6 Gesperrt, Ökobetrieb\0"      //198
"\xcf Verd'laufzeit Min aktiv, Kühl\0"      //207
"\xd0 Verd' 1 und 2 ein, Kühlbetr\0"      //208
"\xd1 Verdichter 1 ein,Kühlbetrieb\0"      //209
"\xd2 Verdichter 2 ein,Kühlbetrieb\0"      //210
"\xeb Wasserdruck zu niedrig\0"
"\xf2 Umschichtung aktiv\0"      //242
"\xf6 Netzunterspannung\0"      //246
"\xfe Kältemittel abpumpen, Manuell\0"      //254
"\x01\x00 Kältemittel abpumpen\0"      //256
"\x01\x01 Startverzögerung Abtauen\0"      //257
"\x01\x02 Verdichter gesperrt\0"      //258
"\x01\x03 Gesperrt, Quellentemp Max\0"      //259
"\x01\x04 Gesperrt, Quellentemp Min\0"      //260
"\x01\x05 Gesperrt, Rücklauftemp Max\0"      //261
"\x01\x06 Gesperrt, Rücklauftemp Min\0"      //262
"\x01\x07 Gesperrt, Vorlauftemp Max\0"      //263
"\x01\x08 Gesperrt, Vorlauftemp Min\0"      //264
"\x01\x09 Gesperrt, Kondens'temp Max\0"      //265
"\x01\x0a Gesperrt, Verdamp'temp Min\0"      //266
"\x01\x0b Gesperrt, Heissgastemp Max\0"      //267
"\x01\x0c Begr Verdampfungstemp Min\0"      //268
"\x01\x0d Begr Kondensationstemp Max\0"      //269
"\x01\x0e Begr Verdampfungstemp Max"      //270
};


//Status Solar
const char ENUM8007[] PROGMEM_LATEST = {
"\x00 ---\0"
"\x04 Handbetrieb aktiv\0"
"\x02 Störung\0"
"\x34 Kollektorfrostschutz aktiv\0"
"\x35 Rückkühlung aktiv\0"
"\x36 Max Speichertemp erreicht\0"
"\x37 Verdampfungsschutz aktiv\0"
"\x38 Überhitzschutz aktiv\0"
"\x39 Max Ladetemp erreicht\0"
"\x3a Ladung Trinkwasser\0"
"\x3b Ladung Pufferspeicher\0"
"\x3c Ladung Schwimmbad\0"
"\x3d Min Ladetemp nicht erreicht\0"
"\x3e Temp’differenz ungenügend\0"
"\x3f Einstrahlung ungenügend\0"
"\x97 Lad'ng TWW + Puffer + Sch'bad\0"
"\x98 Ladung Trinkwasser + Puffer\0"
"\x99 Ladung Trinkwasser + Sch'bad\0"
"\x9a Ladung Puffer + Schwimmbad"
};


//Status Feststoffkessel
const char ENUM8008[] PROGMEM_LATEST = {
"\x00 ---\0"
"\x02 Störung\0"
"\x04 Handbetrieb aktiv\0"
"\x08 Gesperrt, Manuell\0"
"\x09 Gesperrt, Automatisch\0"
"\x0a Gesperrt\0"
"\x0b Anfahrentlastung\0"
"\x0c Anfahrentlastung, Teillast\0"
"\x0d Rücklaufbegrenzung\0"
"\x0e Rücklaufbegrenzung, Teillast\0"
"\x11 Nachlauf aktiv\0"
"\x12 In Betrieb\0"
"\x13 Freigegeben\0"
"\x14 Minimalbegrenzung\0"
"\x15 Minimalbegrenzung, Teillast\0"
"\x16 Minimalbegrenzung aktiv\0"
"\x17 Anlagenfrostschutz aktiv\0"
"\x18 Frostschutz aktiv\0"
"\x19 Aus\0"
"\x38 Überhitzschutz aktiv\0"
"\x3a Ladung Trinkwasser\0"
"\x3b Ladung Pufferspeicher\0"
"\x8d Kesselfrostschutz aktiv\0"
"\xa3 Anfeuerungshilfe aktiv\0"
"\xa6 In Betrieb für Heizkreis\0"
"\xa7 In Teillastbetrieb für HK\0"
"\xa8 In Betrieb für Trinkwasser\0"
"\xa9 In Teillastbetrieb für TWW\0"
"\xaa In Betrieb für HK, TWW\0"
"\xab In Teillastbetrieb für HK, TWW\0"
"\xf1 Restwärmenutzung"
};

// Status Brenner
// Text messages are taken from Installationshandbuch NovoCondens WOB 20-25
// The enum numerical values with question marks are unknown and are placeholders
// !TODO! Determine the enum numerical values

// Thision
const char ENUM8009_2[] PROGMEM_LATEST = {
"\x00 ?---\0"                 // !TODO! "no text" is only an analogous deduction
"\x01 ?Störstellung\0"        // !TODO! enum value is hypothetical
"\x02 ?Startverhinderung\0"   // !TODO! enum value is hypothetical
"\x04 In Betrieb\0"
"\x12 In Betrieb\0"
"\xD6 ?Sicherheitszeit\0"
"\xDA ?Vorlüften\0"
"\xD7 ?Inbetriebsetzung\0"
"\xD8 Standby\0"
"\x09 ??Außerbetriebsetzung\0" // !TODO! enum value is hypothetical
"\xD9 ?Heimlauf\0"
"\xDB ?Nachlüften"
};

// Brötje BSW / WMS / WMC
const char ENUM8009[] PROGMEM_LATEST = {
"\x00 ?---\0"                 // !TODO! "no text" is only an analogous deduction
"\x01 ?Störstellung\0"        // !TODO! enum value is hypothetical
"\x02 ?Startverhinderung\0"   // !TODO! enum value is hypothetical
"\x12 In Betrieb\0"           // verifiziert an WMS (LP)
"\xD6 Sicherheitszeit\0"
"\xDA Vorlüften\0"
"\xD7 Inbetriebsetzung\0"     // verifiziert an WMS (LP)
"\xD8 Standby\0"              // verifiziert an WMS (LP)
"\x09 ?Außerbetriebsetzung\0" // !TODO! enum value is hypothetical
"\xD9 Heimlauf\0"
"\xDB Nachlüften\0"
"\xE0 Zünden\0"               // verifiziert an WMS (LP)
"\xE1 Einschwingzeit"         // verifiziert an WMS (LP)
};

//Status Pufferspeicher
const char ENUM8010[] PROGMEM_LATEST = {
"\x00 ---\0"
"\x18 Frostschutz aktiv\0"
"\x33 Keine Wärmeanforderung\0"
"\x35 Rückkühlung aktiv\0"
"\x40 Ladung Elektro, Notbetrieb\0"
"\x41 Ladung Elektro, Quell’schutz\0"
"\x42 Ladung Elektroeinsatz\0"
"\x43 Zwangsladung aktiv\0"
"\x44 Teilladung aktiv\0"
"\x45 Ladung aktiv\0"
"\x46 Geladen, Max Speichertemp\0"
"\x47 Geladen, Max Ladetemp\0"
"\x48 Geladen, Zwanglad Solltemp\0"
"\x49 Geladen, Solltemperatur\0"
"\x4a Teilgeladen, Solltemperatur\0"
"\x4b Geladen\0"
"\x4c Kalt\0"
"\x4d Rückkühlung via Kollektor\0"
"\x51 Ladung gesperrt\0"
"\x68 Eingeschränkt, TWW-Vorrang\0"
"\x7c Ladung eingeschränkt\0"
"\x83 Ladung Elektro, Abtauen\0"
"\x87 Sperrdauer nach Heizen\0"
"\x8e Rückkühlung via TWW / Hk’s\0"
"\x8f Geladen, Min Ladetemp\0"
"\x93 Warm\0"
"\xa4 Ladung Elektro, Zwang\0"
"\xa5 Ladung Elektro, Ersatz\0"
"\xca Frostschutz Kühlen aktiv\0"
"\xcb Durchladung aktiv\0"
"\xf4 Erzeuger freigegeben"
};

// Status Schwimmbad
const char ENUM8011[] PROGMEM_LATEST = {
"\x00 ---\0"
"\x02 Störung\0"
"\x04 Handbetrieb aktiv\0"
"\x4c Kalt\0"
"\x6a Heizbetrieb eingeschränkt\0"
"\x6e Zwangsabnahme\0"
"\x89 Heizbetrieb\0"
"\x9b Heizbetrieb Erzeuger\0"
"\x9c Geheizt, Max Schw\'badtemp\0"
"\x9d Geheizt, Sollwert Erzeuger\0"
"\x9e Geheizt, Sollwert Solar\0"
"\x9f Geheizt\0"
"\xa0 Heizbetrieb Solar aus\0"
"\xa1 Heizbetrieb Erzeuger aus\0"
"\xa2 Heizbetrieb aus"
};

//Status Zusatzerzeuger  //FUJITSU
const char ENUM8022[] PROGMEM_LATEST = {
"\x00 ---"
};

#define ENUM8051 ENUM8006               // Status - Status Historie 1
#define ENUM8053 ENUM8051               // Status - Status Historie 2
#define ENUM8055 ENUM8051               // Status - Status Historie 3
#define ENUM8057 ENUM8051               // Status - Status Historie 4
#define ENUM8059 ENUM8051               // Status - Status Historie 5
#define ENUM8061 ENUM8051               // Status - Status Historie 6
#define ENUM8063 ENUM8051               // Status - Status Historie 7
#define ENUM8065 ENUM8051               // Status - Status Historie 8
#define ENUM8067 ENUM8051               // Status - Status Historie 9
#define ENUM8069 ENUM8051               // Status - Status Historie 10

#define ENUM8099 ENUM8006               // Status - Hauptdisplay. Achtung! 8099 kann zukünftig direkt von einem Hersteller vergeben werden, dann muss dieser Parameter "umziehen"...

// Diagnose Kaskade
const char ENUM8100[] PROGMEM_LATEST = { // numerical values are hypothetical
"\x00 ?Fehlt\0"
"\x01 ?In Störung\0"
"\x02 ?Handbetrieb aktiv\0"
"\x03 ?Erzeugersperre aktiv\0"
"\x04 ?Schornsteinfegerfkt aktiv\0"
"\x05 ?TWW-Trennschaltung aktiv\0"
"\x06 ?Aussentemp'grenze aktiv\0"
"\x07 ?Nicht freigegeben\0"
"\x08 ?Freigegeben"
};
#define ENUM8102 ENUM8100
#define ENUM8104 ENUM8100
#define ENUM8106 ENUM8100
#define ENUM8108 ENUM8100
#define ENUM8110 ENUM8100
#define ENUM8112 ENUM8100
#define ENUM8114 ENUM8100
#define ENUM8116 ENUM8100
#define ENUM8118 ENUM8100
#define ENUM8120 ENUM8100
#define ENUM8122 ENUM8100
#define ENUM8124 ENUM8100
#define ENUM8126 ENUM8100
#define ENUM8128 ENUM8100
#define ENUM8130 ENUM8100

// Diagnose Erzeuger - 8304 Kesselpumpe Q1
// NovoCondens WOB 20-25
// !TODO! Collect the other possible values (probably 0=Aus, 1=Ein, 255=Ein)
const char ENUM8304[] PROGMEM_LATEST = {
  "\x00 Aus\0"    // precision guesswork
  "\x01 Ein\0"    // precision guesswork
  "\xff Ein\0"    // vom LCD abgelesen (Python code)
  "\x01\x00 Keine Funktion"
};

const char ENUM8313[] PROGMEM_LATEST = {
  "\x01 Kesselfühler B2\0"               // verifiziert an WMS (LP)
  "\x02 Rücklauffühler B7\0"
  "\x03 TWW Ladefühler B36\0"
  "\x04 TWW Zapffühler B38\0"
  "\x05 TWW Zirkulationsfühler B39\0"
  "\x06 Kaskadenfühler B10/ B70"
}; // todo Hinweis: x01 ist definitiv richtig. Die anderen muessen noch verifiziert werden.

const char ENUM8390[] PROGMEM_LATEST = {
  "\x01 1\0"
  "\x02 2\0"
  "\x03 TNN\0"        // verifiziert an WMS (LP)
  "\x04 STY\0"        // verifiziert an WMS (LP)
  "\x05 5\0"
  "\x06 6\0"
  "\x07 7\0"
  "\x08 8\0"
  "\x09 9\0"
  "\x0a 10\0"
  "\x0b 11\0"
  "\x0c 12\0"
  "\x0d TSA\0"        // verifiziert an WMS (LP)
  "\x0e 14\0"
  "\x0f 15\0"
  "\x10 MOD\0"        // verifiziert an WMS (LP)
  "\x11 17\0"
  "\x12 18\0"
  "\x13 19\0"
  "\x14 20\0"
  "\x15 21\0"
  "\x16 22\0"
  "\x17 23\0"
  "\x18 24"           // verifiziert an WMS (LP)
};

// Diagnose Verbraucher 8749 Raumthermostat 1
// Texts taken from manual
const char ENUM8749[] PROGMEM_LATEST = {     // numerical values unverified
  "\x00 Kein Bedarf\0"
  "\x01 Bedarf"
};
#define ENUM8779 ENUM8749  // 8779 Raumthermostat 2

// PPS Betriebsart
const char ENUM15010[] PROGMEM_LATEST = {
/*XXX "\x00 Automatisch\0" 
  "\x01 Manuell\0"
  "\x02 Aus"*/
  "\x00 Automatique \0" 
  "\x01 Manuel \0"
  "\x02 Veille"
};

const char ENUM15062[] PROGMEM_LATEST = {
  "\x52 QAA 50\0"
  "\x53 QAA 70"
};

/* SPECIAL ENUM tables */
//Fehlercodes
const char ENUM_ERROR[] PROGMEM_LATEST = {
"\x00 kein Fehler\0"
"\x0a Außentemperatur Fühlerfehler\0"
"\x14 Kesseltemperatur 1 Fühlerfehler\0"
"\x19 Feststoffkesseltemperatur (Holz) Fühlerfehler\0"
"\x1a Gemeinsame Vorlauftemperatur Fühlerfehler\0"
"\x1c Rauch- / Abgastemperatur Fühlerfehler\0"
"\x1e Vorlauftemperatur 1 Fühlerfehler\0"
"\x1f Vorlauftemperatur 1 Kühlen Fühlerfehler\0"
"\x20 Vorlauftemperatur 2 Fühlerfehler\0"
"\x26 Vorlauftemperatur Vorregler Fühlerfehler\0"
"\x28 Rücklauftemperatur 1 Fühlerfehler\0"
"\x2e Rücklauftemperatur Kaskade Fühlerfehler\0"
"\x2f Gemeinsame Rücklauftemperatur Fühlerfehler\0"
"\x32 Trinkwassertemperatur 1 Fühlerfehler\0"
"\x34 Trinkwassertemperatur 2 Fühlerfehler\0"
"\x36 TWW-Vorregler Fühlerfehler\0"
"\x39 TWW-Zirkulationstemperatur Fühlerfehler\0"
"\x3c Raumtemperatur 1 Fühlerfehler\0"
"\x41 Raumtemperatur 2 Fühlerfehler\0"
"\x44 Raumtemperatur 3 Fühlerfehler\0"
"\x46 Pufferspeichertemperatur 1 Fühlerfehler\0"
"\x47 Pufferspeichertemperatur 2 Fühlerfehler\0"
"\x48 Pufferspeichertemperatur 3 Fühlerfehler\0"
"\x49 Kollektortemperatur 1 Fühlerfehler\0"
"\x4a Kollektortemperatur 2 Fühlerfehler\0"
"\x51 LPB-Kurzschluss\0"
"\x52 LPB-Adresskollision\0"
"\x53 BSB-Draht Kurzschluss\0"
"\x54 BSB-Adresskollision\0"
"\x55 BSB-Funk Kommunikationsfehler\0"
"\x5b EEPROM-Fehler bei Verriegelungsinformation\0"
"\x62 Erweiterungsmodul 1 Fehler (Sammelfehler)\0"
"\x63 Erweiterungsmodul 2 Fehler (Sammelfehler)\0"
"\x64 Zwei Uhrzeitmaster (LPB)\0"
"\x66 Uhrzeitmaster ohne Gangreserve (LPB)\0"
"\x69 Wartungsmeldung\0"
"\x6d Kesseltemperatur Überwachung\0"
"\x6e Sicherheitstemperaturbegrenzung Störabschaltung\0"
"\x6f Temperaturwächterabschaltung\0"
"\x75 Obere Druckgrenze (überschritten)\0"
"\x76 Kritische untere Druckgrenze (unterschritten)\0"
"\x77 Fehler Druckschalter\0"
"\x79 Vorlauftemperatur 1 (HK1) Überwachung\0"
"\x7a Vorlauftemperatur 2 (HK2) Überwachung\0"
"\x7e Trinkwasser-Ladeüberwachung\0"
"\x7f Legionellentemperatur nicht erreicht\0"
"\x80 Flammenausfall in Betrieb\0"
"\x83 Brennerstörung\0"
"\x84 Gasdruckwächter- oder Luftdruckwächterfehler\0"
"\x85 Sicherheitszeit überschritt\0"
"\x92 Konfigurationsfehler Sammelmeldung\0"
"\x97 Interner Fehler\0"
"\x98 Parametrierungsfehler\0"
"\xa0 Gebläsefehler\0"
"\xa2 Luftdruckwächter schließt nicht\0"
"\xab Alarmkontakt 1 (H1 oder H4) aktiv\0"
"\xac Alarmkontakt 2 (EM1, EM2 oder EM3) oder H5 aktiv\0"
"\xad Alarmkontakt 3 (EX2 / 230 VAC) aktiv\0"
"\xae Alarmkontakt 4 (H3) aktiv\0"
"\xb0 Obere Druckgrenze 2 (überschritten)\0"
"\xb1 Kritische untere Druckgrenze 2 (unterschritten)\0"
"\xb2 Temperaturwächter Heizkreis 1\0"
"\xb3 Temperaturwächter Heizkreis 2\0"
"\xb7 Gerät im Parametriermodus\0"
"\xcf Störung Kühlkreis\0"
"\xd9 Fühler- / Sensorfehler Sammelmeldung\0"
"\xda Drucküberwachung Sammelmeldung\0"
"\xde Hochdruck bei Wärmepumpenbetrieb\0"
"\xf1 Vorlauffühler Solar Fühlerfehler\0"
"\xf2 Rücklauffühler Solar Fühlerfehler\0"
"\xf3 Schwimmbadtemperatur Fühlerfehler\0"
"\x01\x04 Vorlauftemperatur 3 Fühlerfehler\0"
"\x01\x0e Wächterfunktion\0"
"\x01\x3d Netzfrequenz außerh. zul. Bereich\0"
"\x01\x40 TWW Ladetemperatur Fühlerfehler\0"
"\x01\x41 Durchl’erhitzer Zapftemperatur Fühlerfehler\0"
"\x01\x42 Obere Druckgrenze 3 (überschritten)\0"
"\x01\x43 Kritische untere Druckgrenze 3 (unterschritten)\0"
"\x01\x44 BX gleiche Fühler\0"
"\x01\x45 BX/Erweiterungsmodul gleiche Fühler\0"
"\x01\x46 BX/Mischergruppe gleiche Fühler\0"
"\x01\x47 Erweiterungsmodul gleiche Funktion\0"
"\x01\x48 Mischergruppe gleiche Funktion\0"
"\x01\x49 Erweit’modul / Mischergruppe gleiche Funktion\0"
"\x01\x4a Fühler BX1 keine Funktion\0"
"\x01\x4b Fühler BX2 keine Funktion\0"
"\x01\x4c Fühler BX3 keine Funktion\0"
"\x01\x4d Fühler BX4 keine Funktion\0"
"\x01\x4e Fühler BX5 keine Funktion\0"
"\x01\x4f Fühler BX21 keine Funktion\0"
"\x01\x50 Fühler BX22 keine Funktion\0"
"\x01\x51 Fühler BX1 keine Funktion\0"
"\x01\x52 Fühler BX12 keine Funktion\0"
"\x01\x53 Kollektorpumpe Q5 fehlt\0"
"\x01\x54 Kollektorpumpe Q16 fehlt\0"
"\x01\x55 Kollektorfühler B6 fehlt\0"
"\x01\x56 Solar TWW-Fühler B31 fehlt\0"
"\x01\x57 Solareinbindung fehlt\0"
"\x01\x58 Solarstellglied Puffer K8 fehlt\0"
"\x01\x59 Solarstellglied Schwimmbad K18 fehlt\0"
"\x01\x5a Feststoffkesselpumpe Q10 fehlt\0"
"\x01\x5b Feststoffkessel Vergleichsfühler fehlt\0"
"\x01\x5c Feststoffkessel Adressfehler\0"
"\x01\x5d Pufferrücklaufventil Y15 fehlt\0"
"\x01\x5e Pufferspeicher Adressfehler\0"
"\x01\x5f Vorregler / Zubringerpumpe Adressfehler\0"
"\x01\x60 Hydraulische Weiche Adressfehler\0"
"\x01\x61 Kaskadenfühler B10 fehlt\0"
"\x01\x65 Vorlauftemperatur Kühlkreis 1 Überwachung\0"
"\x01\x6e Raumtemperatur Hx Fühlerfehler\0"
"\x01\x6f Relative Raumfeuchte Hx Fühlerfehler\0"
"\x01\x72 Thermodynamischer Erzeuger\0"  //FUJITSU
"\x01\x73 Vorlauftemperatur 3 (HK3) Überwachung\0"
"\x01\x74 Temperaturwächter HK3\0"
"\x01\x75 Erweiterungsmodul 3 Fehler (Sammelfehler)\0"
"\x01\x7a Repetitionszähler interner Fehler abgelaufen\0"
"\x01\x7e Repetitionszähler Gebläsefehler abgelaufen\0"
"\x01\x80 Fremdlicht\0"
"\x01\x81 Netzunterspannung\0"
"\x01\x82 Gebläsedrehzahl hat gültigen Bereich verlassen\0"
"\x01\x83 Luftdruckwächterfehler\0"
"\x01\xab Konfiguration Abgasklappe\0"
"\x01\xb0 Funktionserde X17 nicht angeschlossen"
};

// Wartungs-Codes
const char ENUM_WARTUNG[] PROGMEM_LATEST = {
"\x01 Brennerbetriebsstunden überschritten\0"
"\x02 Brennerstarts überschritten\0"
"\x03 Wartungsintervall überschritten\0"
"\x05 Wasserdruck Heizkreis zu niedrig (Untere Druckgrenze 1 unterschritten)\0"
"\x12 Wasserdruck 2 Heizkreis zu niedrig (Untere Druckgrenze 2 unterschritten)\0"
"\x0a Batterie Außenfühler wechseln\0"
"\x15 Maximale Abgastemperatur überschritten\0"
"\x16 Wasserdruck 3 Heizkreis zu niedrig (Untere Druckgrenze 3 unterschritten)"
};

// Sonderbetriebs-Codes
const char ENUM_SONDERBETRIEB[] PROGMEM_LATEST = {
"\x01\x2d Handbetrieb\0"
"\x01\x2e STB-Test\0"
"\x01\x2f Schornsteinfegerfkt\0"
"\x01\x35 Simulation Außentemp\0"
"\x01\x36 Alternativenerg"
};

// Sonderbetriebs-Codes
const char ENUM_WEEKDAY[] PROGMEM_LATEST = {
"\x01 Montag\0"
"\x02 Dienstag\0"
"\x03 Mittwoch\0"
"\x04 Donnerstag\0"
"\x05 Freitag\0"
"\x06 Samstag\0"
"\x07 Sonntag"
};

/*
 * Bei der Änderung des Komfortsollwertes durch einfaches Drehen des Rades
 * werden anscheinend die Grenzwerte abgefragt:
HEIZ->DISP ANS  710 11 - Heizkreis 1 - Komfortsollwert 20.00 &deg;C
HEIZ->DISP ANS      2D3D05A5 00 08 C0 (35.0°C)
DC 80 0A 0E 07 2D 3D 05 A5 00 08 C0 3F 7B
HEIZ->DISP ANS  712 11 - Heizkreis 1 - Reduziertsollwert 15.00 &deg;C
*/

/* **********************/
/* global command table */
/* **********************/

PROGMEM_LATE const cmd_t cmdtbl1[]={
// Uhrzeit und Datum
{0x0500006C,  CAT_DATUMZEIT,        VT_DATETIME,      0,     STR0,     0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ ] - Uhrzeit und Datum
{0x053D000B,  CAT_DATUMZEIT,        VT_DATETIME,      0,     STR0,     0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ ] - Uhrzeit und Datum   // gleiche Funktion mit anderer CommandID
{0x053D006C,  CAT_DATUMZEIT,        VT_DATETIME,      0,     STR0,     0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ ] - Uhrzeit und Datum   // gleiche Funktion mit anderer CommandID
{0x0505000B,  CAT_DATUMZEIT,        VT_DATETIME,      0,     STR0,     0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [ ] - Uhrzeit und Datum
{0x0505000B,  CAT_DATUMZEIT,        VT_DATETIME,      0,     STR0,     0,                    NULL,         DEFAULT_FLAG, DEV_090_ALL}, // [ ] - Uhrzeit und Datum
{0x0505000B,  CAT_DATUMZEIT,        VT_DATETIME,      0,     STR0,     0,                    NULL,         DEFAULT_FLAG, DEV_097_ALL}, // [ ] - Uhrzeit und Datum
{0x0505000B,  CAT_DATUMZEIT,        VT_DATETIME,      0,     STR0,     0,                    NULL,         DEFAULT_FLAG, DEV_107_ALL}, // [ ] - Uhrzeit und Datum
{CMD_UNKNOWN, CAT_DATUMZEIT,        VT_UNKNOWN,       1,     STR1,     0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Uhrzeit und Datum - Stunden/Minuten
{CMD_UNKNOWN, CAT_DATUMZEIT,        VT_UNKNOWN,       2,     STR2,     0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt:MM ] - Uhrzeit und Datum - Tag/Monat
{CMD_UNKNOWN, CAT_DATUMZEIT,        VT_UNKNOWN,       3,     STR3,     0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [jjjj ] - Uhrzeit und Datum - Jahr

// Sommerzeit scheint im DISP gehandelt zu werden
// Bei Anzeige werden keine Werte abgefragt. Bei Änderung wird ein INF geschickt.
// Sommerzeit Beginn 25.3. DISP->ALL  INF      0500009E 00 FF 03 19 FF FF FF FF 16
// Sommerzeit Ende 25.11. DISP->ALL  INF      0500009D 00 FF 0B 19 FF FF FF FF 16
{0x0500009E,  CAT_DATUMZEIT,        VT_SUMMERPERIOD,  5,     STR5,     0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt:MM ] - Uhrzeit und Datum - Sommerzeitbeginn Tag/Monat
{0x050504B3,  CAT_DATUMZEIT,        VT_SUMMERPERIOD,  5,     STR5,     0,                    NULL,         DEFAULT_FLAG, DEV_090_ALL}, // [tt:MM ] - Uhrzeit und Datum - Sommerzeitbeginn Tag/Monat
{0x050504B3,  CAT_DATUMZEIT,        VT_SUMMERPERIOD,  5,     STR5,     0,                    NULL,         DEFAULT_FLAG, DEV_076_ALL}, // [tt:MM ] - Uhrzeit und Datum - Sommerzeitbeginn Tag/Monat
{0x0500009D,  CAT_DATUMZEIT,        VT_SUMMERPERIOD,  6,     STR6,     0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Uhrzeit und Datum - Sommerzeitende Tag/Monat
{0x050504B2,  CAT_DATUMZEIT,        VT_SUMMERPERIOD,  6,     STR6,     0,                    NULL,         DEFAULT_FLAG, DEV_090_ALL}, // [tt.MM ] - Uhrzeit und Datum - Sommerzeitende Tag/Monat
{0x050504B2,  CAT_DATUMZEIT,        VT_SUMMERPERIOD,  6,     STR6,     0,                    NULL,         DEFAULT_FLAG, DEV_076_ALL}, // [tt.MM ] - Uhrzeit und Datum - Sommerzeitende Tag/Monat


// nur Bedienteil -> keine Kommunikation über BSB
{0x053D0BC3,  CAT_BEDIENEINHEIT,    VT_ENUM,          20,    STR20,    sizeof(ENUM20),       ENUM20,       DEFAULT_FLAG, DEV_ALL}, // [0] - Bedieneinheit - Sprachauswahl
{CMD_UNKNOWN, CAT_BEDIENEINHEIT,    VT_ONOFF,         21,    STR21,    0,                    NULL,         FL_RONLY, DEV_ALL}, // [0] - Bedieneinheit - Anzeige Sonderbetrieb
{0x053D0BCA,  CAT_BEDIENEINHEIT,    VT_ENUM,          22,    STR22,    sizeof(ENUM22),       ENUM22,       DEFAULT_FLAG, DEV_ALL}, // [0] - Bedieneinheit - Info
{0x053D0BC9,  CAT_BEDIENEINHEIT,    VT_ENUM,          23,    STR23,    sizeof(ENUM23),       ENUM23,       DEFAULT_FLAG, DEV_ALL}, // Fehleranzeige Code | Code und Text
{0x053D081E,  CAT_BEDIENEINHEIT,    VT_BYTE,          25,    STR25,    0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Anzeigekontrast
{0x053D0BB9,  CAT_BEDIENEINHEIT,    VT_ONOFF,         26,    STR26,    0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Bedieneinheit - Sperre Bedienung
{0x053D0BC8,  CAT_BEDIENEINHEIT,    VT_ONOFF,         27,    STR27,    0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Bedieneinheit - Sperre Programmierung
{0x053D0BC8,  CAT_BEDIENEINHEIT,    VT_ENUM,          28,    STR28,    sizeof(ENUM28),       ENUM28,       DEFAULT_FLAG, DEV_ALL}, // [0] - Bedieneinheit - Bedieneinheit Direktverstellung
{CMD_UNKNOWN, CAT_BEDIENEINHEIT,    VT_ENUM,          29,    STR29,    sizeof(ENUM29),       ENUM29,       DEFAULT_FLAG, DEV_ALL}, // [0] - Einheiten °C,bar oder °F,PSI
{CMD_UNKNOWN, CAT_BEDIENEINHEIT,    VT_YESNO,         30,    STR30,    0,                    NULL,         FL_RONLY, DEV_ALL}, // Bedieneinheit Grundeinstellung sichern
{0x053D08C3,  CAT_BEDIENEINHEIT,    VT_YESNO,         31,    STR31,    0,                    NULL,         FL_RONLY, DEV_ALL}, // Bedieneinheit Grundeinstellung aktivieren
{CMD_UNKNOWN, CAT_BEDIENEINHEIT,    VT_ENUM,          40,    STR40,    sizeof(ENUM40),       ENUM40,       DEFAULT_FLAG, DEV_ALL}, // Einsatz als
{CMD_UNKNOWN, CAT_BEDIENEINHEIT,    VT_ENUM,          42,    STR42,    sizeof(ENUM42),       ENUM42,       DEFAULT_FLAG, DEV_ALL}, // Zuordnung Raumgerät 1
{0x053D0BC5,  CAT_BEDIENEINHEIT,    VT_ENUM,          44,    STR44,    sizeof(ENUM44),       ENUM44,       DEFAULT_FLAG, DEV_ALL}, // [0] - Bedieneinheit - Bedienung HK 2
{0x05050BC6,  CAT_BEDIENEINHEIT,    VT_ENUM,          46,    STR46,    sizeof(ENUM46),       ENUM46,       DEFAULT_FLAG, DEV_ALL}, // [0] - Bedieneinheit - Bedienung HK P
{CMD_UNKNOWN, CAT_BEDIENEINHEIT,    VT_ENUM,          48,    STR48,    sizeof(ENUM48),       ENUM48,       DEFAULT_FLAG, DEV_ALL}, // Wirkung Präsenztaste
{CMD_UNKNOWN, CAT_BEDIENEINHEIT,    VT_UNKNOWN,       54,    STR54,    0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Korrektur Raumfühler
{0x053D000E,  CAT_BEDIENEINHEIT,    VT_FP1,           70,    STR70,    0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Bedieneinheit - Geraete-Version Bedienteil

// Funk
{CMD_UNKNOWN, CAT_FUNK,             VT_YESNO,         120,   STR120,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Binding
{CMD_UNKNOWN, CAT_FUNK,             VT_ONOFF,         121,   STR121,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Testmode
{0x053D0966,  CAT_FUNK,             VT_ENUM,          130,   STR130,   sizeof(ENUM130),      ENUM130,      DEFAULT_FLAG, DEV_ALL}, // Raumgerät 1 Status
{0x053D0967,  CAT_FUNK,             VT_ENUM,          131,   STR131,   sizeof(ENUM131),      ENUM131,      DEFAULT_FLAG, DEV_ALL}, // Raumgerät 2 Status
{0x053D0968,  CAT_FUNK,             VT_ENUM,          132,   STR132,   sizeof(ENUM132),      ENUM132,      DEFAULT_FLAG, DEV_ALL}, // Raumgerät P Status
{0x053D096E,  CAT_FUNK,             VT_ENUM,          133,   STR133,   sizeof(ENUM133),      ENUM133,      DEFAULT_FLAG, DEV_ALL}, // Außenfühler P Status
{0x053D0993,  CAT_FUNK,             VT_ENUM,          134,   STR134,   sizeof(ENUM134),      ENUM134,      DEFAULT_FLAG, DEV_ALL}, // Repeater P Status
{0x053D096A,  CAT_FUNK,             VT_ENUM,          135,   STR135,   sizeof(ENUM135),      ENUM135,      DEFAULT_FLAG, DEV_ALL}, // Bediengerät 1 Status
{0x053D096C,  CAT_FUNK,             VT_ENUM,          136,   STR136,   sizeof(ENUM136),      ENUM136,      DEFAULT_FLAG, DEV_ALL}, // Bediengerät 1 Status
{0x053D096D,  CAT_FUNK,             VT_ENUM,          137,   STR137,   sizeof(ENUM137),      ENUM137,      DEFAULT_FLAG, DEV_ALL}, // Bediengerät P Status
{0x053D096B,  CAT_FUNK,             VT_ENUM,          138,   STR138,   sizeof(ENUM138),      ENUM138,      DEFAULT_FLAG, DEV_ALL}, // Servicegerät Status
{0x053D05E4,  CAT_FUNK,             VT_YESNO,         140,   STR140,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Alle Geräte löschen


// Zeitprogramm Heizkreis 1
// HEIZ->DISP ANS 500 Vorwahl  05 00 15 00 98 00 18 00 98 00 18 00
// set Mo 1. Heizphase 05:10  -> DISP->HEIZ SET 3D050A8C 05 0A 15 00 80 00 00 00 80 00 00 00
// set Mo 1. Heizphase 05:00  -> DISP->HEIZ SET 3D050A8C 05 00 15 00 80 00 00 00 80 00 00 00
// Für jeden Wochentag können 3 Phasen gesetzt werden. Die Kombinationen Mo-Fr, Mo-So, Sa - So werden nur auf dem Bedienteil angezeigt.
// 8C = Mo .. 92 = So
// virtuelle Zeilen
{0x053D0A8C,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      500,   STR500,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Zeitprogramm Heizkreis 1 - Vorwahl
{0x213D0A8C,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      500,   STR500,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - Zeitprogramm Heizkreis 1 - Vorwahl - logged on OCI700 via LPB
{0x053D0A8D,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      501,   STR501,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 1 - Mo-So: 1. Phase Ein
{0x213D0A8D,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      501,   STR501,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 1 - Mo-So: 1. Phase Ein - logged on OCI700 via LPB
{0x053D0A8E,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      502,   STR502,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 1 - Mo-So: 1. Phase Aus
{0x213D0A8E,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      502,   STR502,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 1 - Mo-So: 1. Phase Aus - logged on OCI700 via LPB
{0x053D0A8F,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      503,   STR503,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 1 - Mo-So: 2. Phase Ein
{0x213D0A8F,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      503,   STR503,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 1 - Mo-So: 2. Phase Ein - logged on OCI700 via LPB
{0x053D0A90,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      504,   STR504,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 1 - Mo-So: 2. Phase Aus
{0x213D0A90,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      504,   STR504,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 1 - Mo-So: 2. Phase Aus - logged on OCI700 via LPB
{0x053D0A91,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      505,   STR505,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 1 - Mo-So: 3. Phase Ein
{0x213D0A91,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      505,   STR505,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 1 - Mo-So: 3. Phase Ein - logged on OCI700 via LPB
{0x053D0A92,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      506,   STR506,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 1 - Mo-So: 3. Phase Aus
{0x213D0A92,  CAT_ZEITPROG_HK1,     VT_TIMEPROG,      506,   STR506,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 1 - Mo-So: 3. Phase Aus - logged on OCI700 via LPB
{0x053D05B2,  CAT_ZEITPROG_HK1,     VT_YESNO,         516,   STR516,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Zeitprogramm Heizkreis 1 - Standardwerte
{0x213D05B2,  CAT_ZEITPROG_HK1,     VT_YESNO,         516,   STR516,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - Zeitprogramm Heizkreis 1 - Standardwerte - logged on OCI700 via LPB
// Zeitprogramm Heizkreis 2
// virtuelle Zeilen
{0x063D0A8C,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      520,   STR520,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Zeitprogramm Heizkreis 2 - Vorwahl
{0x223D0A8C,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      520,   STR520,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - Zeitprogramm Heizkreis 2 - Vorwahl - logged on OCI700 via LPB
{0x063D0A8D,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      521,   STR521,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 2 - Mo-So: 1. Phase Ein
{0x223D0A8D,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      521,   STR521,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 2 - Mo-So: 1. Phase Ein - logged on OCI700 via LPB
{0x063D0A8E,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      522,   STR522,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 2 - Mo-So: 1. Phase Aus
{0x223D0A8E,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      522,   STR522,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 2 - Mo-So: 1. Phase Aus - logged on OCI700 via LPB
{0x063D0A8F,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      523,   STR523,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 2 - Mo-So: 2. Phase Ein
{0x223D0A8F,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      523,   STR523,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 2 - Mo-So: 2. Phase Ein - logged on OCI700 via LPB
{0x063D0A90,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      524,   STR524,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 2 - Mo-So: 2. Phase Aus
{0x223D0A90,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      524,   STR524,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 2 - Mo-So: 2. Phase Aus - logged on OCI700 via LPB
{0x063D0A91,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      525,   STR525,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 2 - Mo-So: 3. Phase Ein
{0x223D0A91,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      525,   STR525,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 2 - Mo-So: 3. Phase Ein - logged on OCI700 via LPB
{0x063D0A92,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      526,   STR526,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 2 - Mo-So: 3. Phase Aus
{0x223D0A92,  CAT_ZEITPROG_HK2,     VT_TIMEPROG,      526,   STR526,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm Heizkreis 2 - Mo-So: 3. Phase Aus - logged on OCI700 via LPB
// Thision 535 Tag kopieren auf
{0x063D05B2,  CAT_ZEITPROG_HK2,     VT_YESNO,         536,   STR536,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Zeitprogramm Heizkreis 2 - Standardwerte
{0x223D05B2,  CAT_ZEITPROG_HK2,     VT_YESNO,         536,   STR536,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - Zeitprogramm Heizkreis 2 - Standardwerte - logged on OCI700 via LPB

// Zeitprogramm 3/HKP
// virtuelle Zeilen
{0x073D0A8C,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      540,   STR540,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Zeitprogramm 3 HKP - Vorwahl
{0x053D0A8C,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      540,   STR540,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - Zeitprogramm 3 HKP - Vorwahl - logged on OCI700 via LPB
{0x073D0A8D,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      541,   STR541,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 3 HKP - Mo-So: 1. Phase Ein
{0x053D0A8D,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      541,   STR541,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm 3 HKP - Mo-So: 1. Phase Ein - logged on OCI700 via LPB
{0x073D0A8E,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      542,   STR542,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 3 HKP - Mo-So: 1. Phase Aus
{0x053D0A8E,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      542,   STR542,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm 3 HKP - Mo-So: 1. Phase Aus - logged on OCI700 via LPB
{0x073D0A8F,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      543,   STR543,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 3 HKP - Mo-So: 2. Phase Ein
{0x053D0A8F,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      543,   STR543,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm 3 HKP - Mo-So: 2. Phase Ein - logged on OCI700 via LPB
{0x073D0A90,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      544,   STR544,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 3 HKP - Mo-So: 2. Phase Aus
{0x053D0A90,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      544,   STR544,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm 3 HKP - Mo-So: 2. Phase Aus - logged on OCI700 via LPB
{0x073D0A91,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      545,   STR545,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 3 HKP - Mo-So: 3. Phase Ein
{0x053D0A91,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      545,   STR545,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm 3 HKP - Mo-So: 3. Phase Ein - logged on OCI700 via LPB
{0x073D0A92,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      546,   STR546,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 3 HKP - Mo-So: 3. Phase Aus
{0x053D0A92,  CAT_ZEITPROG_HKP,     VT_TIMEPROG,      546,   STR546,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm 3 HKP - Mo-So: 3. Phase Aus - logged on OCI700 via LPB
// Thision 555 Tag kopieren auf
{0x073D05B2,  CAT_ZEITPROG_HKP,     VT_YESNO,         556,   STR556,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Zeitprogramm 3 HKP - Standardwerte
{0x053D05B2,  CAT_ZEITPROG_HKP,     VT_YESNO,         556,   STR556,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - Zeitprogramm 3 HKP - Standardwerte - logged on OCI700 via LPB

// Zeitprogramm 4/TWW
{0x053D0AA0,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      560,   STR560,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Zeitprogramm 4 TWW - Vorwahl
{0x253D0AA0,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      560,   STR560,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - Zeitprogramm 4 TWW - Vorwahl - logged on OCI700 via LPB
{0x053D0AA1,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      561,   STR561,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 4 TWW - Mo-So: 1. Phase Ein
{0x253D0AA1,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      561,   STR561,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm 4 TWW - Mo-So: 1. Phase Ein - logged on OCI700 via LPB
{0x053D0AA2,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      562,   STR562,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 4 TWW - Mo-So: 1. Phase Aus
{0x253D0AA2,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      562,   STR562,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm 4 TWW - Mo-So: 1. Phase Aus - logged on OCI700 via LPB
{0x053D0AA3,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      563,   STR563,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 4 TWW - Mo-So: 2. Phase Ein
{0x253D0AA3,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      563,   STR563,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm 4 TWW - Mo-So: 2. Phase Ein - logged on OCI700 via LPB
{0x053D0AA4,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      564,   STR564,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 4 TWW - Mo-So: 2. Phase Aus
{0x253D0AA4,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      564,   STR564,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm 4 TWW - Mo-So: 2. Phase Aus - logged on OCI700 via LPB
{0x053D0AA5,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      565,   STR565,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 4 TWW - Mo-So: 3. Phase Ein
{0x253D0AA5,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      565,   STR565,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm 4 TWW - Mo-So: 3. Phase Ein - logged on OCI700 via LPB
{0x053D0AA6,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      566,   STR566,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 4 TWW - Mo-So: 3. Phase Aus
{0x253D0AA6,  CAT_ZEITPROG_TWW,     VT_TIMEPROG,      566,   STR566,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [hh:mm ] - Zeitprogramm 4 TWW - Mo-So: 3. Phase Aus - logged on OCI700 via LPB
// Thision 575 Tag kopieren auf
{0x053D05B3,  CAT_ZEITPROG_TWW,     VT_YESNO,         576,   STR576,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Zeitprogramm 4 TWW - Standardwerte
{0x253D05B3,  CAT_ZEITPROG_TWW,     VT_YESNO,         576,   STR576,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - Zeitprogramm 4 TWW - Standardwerte

// Zeitprogramm 5
// {0x053D0AB3,  CAT_ZEITPROG_5,       VT_TIMEPROG,      600,   STR600,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Zeitprogramm 5 - Vorwahl / TODO: check hypothetical CommandID
{0x053D0AB4,  CAT_ZEITPROG_5,       VT_TIMEPROG,      600,   STR600,   0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // [hh:mm ] - Zeitprogramm 5 - Vorwahl
{0x053D0AB4,  CAT_ZEITPROG_5,       VT_TIMEPROG,      601,   STR601,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 5 - Mo-So: 1. Phase Ein
{0x053D0AB5,  CAT_ZEITPROG_5,       VT_TIMEPROG,      602,   STR602,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 5 - Mo-So: 1. Phase Aus
{0x053D0AB6,  CAT_ZEITPROG_5,       VT_TIMEPROG,      603,   STR603,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 5 - Mo-So: 2. Phase Ein
{0x053D0AB7,  CAT_ZEITPROG_5,       VT_TIMEPROG,      604,   STR604,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 5 - Mo-So: 2. Phase Aus
{0x053D0AB8,  CAT_ZEITPROG_5,       VT_TIMEPROG,      605,   STR605,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 5 - Mo-So: 3. Phase Ein
{0x053D0AB9,  CAT_ZEITPROG_5,       VT_TIMEPROG,      606,   STR606,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Zeitprogramm 5 - Mo-So: 3. Phase Aus
{0x053D0ABA,  CAT_ZEITPROG_5,       VT_YESNO,         616,   STR616,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Zeitprogramm 5 - Standardwerte
{0x053D082B,  CAT_ZEITPROG_5,       VT_YESNO,         616,   STR616,   0,                    NULL,         DEFAULT_FLAG, DEV_119_ALL}, // [0] - Zeitprogramm 5 - Standardwerte
{0x053D082B,  CAT_ZEITPROG_5,       VT_YESNO,         616,   STR616,   0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // [0] - Zeitprogramm 5 - Standardwerte


// Es gibt 8 Perioden c4..d3 (jeweils Beginn/Ende).
// Zeile 641 dient nur zur Vorwahl der Perioden auf dem Bedienteil.
// Die Parameter scheinen VT_DATETIME ähnlich zu sein.
// 1. Byte:
// Bei RX 00=enabled 01=disabled
// Bei TX 06=enable 05=disable
// byte 3 Monat
// byte 4 Tag
// byte 17=0x17
// alle anderen Bytes sind 0
// z.B.:
// DISP->HEIZ SET      3D0509C6 06 00 02 0A 00 00 00 00 17
// Periode 2 Ende: DC 80 0A 14 07 05 3D 09 C6 01 00 01 01 00 00 00 00 17 0C 38

// Ferien Heizkreis 1
// virtuelle Zeilen
{0x053D09C4,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  632,   STR632,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 1 Beginn Tag/Monat
{0x053D09C5,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  633,   STR633,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 1 Ende Tag/Monat
{0x053D09C6,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  634,   STR634,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 2 Beginn Tag/Monat
{0x053D09C7,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  635,   STR635,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 2 Ende Tag/Monat
{0x053D09C8,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  636,   STR636,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 3 Beginn Tag/Monat
{0x053D09C9,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  637,   STR637,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 3 Ende Tag/Monat
{0x053D09CA,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  638,   STR638,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 4 Beginn Tag/Monat
{0x053D09CB,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  639,   STR639,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 4 Ende Tag/Monat
{0x053D09CC,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  640,   STR640,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 5 Beginn Tag/Monat
{0x053D09CD,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  641,   STR641,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 5 Ende Tag/Monat
{0x053D09CE,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  642,   STR642,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 6 Beginn Tag/Monat
{0x213D09C4,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  642,   STR642,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 6 Beginn Tag/Monat - logged on OCI700 via LPB
{0x053D09CF,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  643,   STR643,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 6 Ende Tag/Monat
{0x213D09C5,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  643,   STR643,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 6 Ende Tag/Monat - logged on OCI700 via LPB
{0x053D09D0,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  644,   STR644,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 7 Beginn Tag/Monat
{0x053D09D1,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  645,   STR645,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 7 Ende Tag/Monat
{0x053D09D2,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  646,   STR646,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 8 Beginn Tag/Monat
{0x053D09D3,  CAT_FERIEN_HK1,       VT_VACATIONPROG,  647,   STR647,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 1 - Periode 8 Ende Tag/Monat
{0x2D3D04C2,  CAT_FERIEN_HK1,       VT_ENUM,          648,   STR648,   sizeof(ENUM648),      ENUM648,      DEFAULT_FLAG, DEV_ALL}, // [0] - Ferienheizkreis 1 - Betriebsniveau
// Ferien Heizkreis 2
// virtuelle Zeilen
{0x063D09C4,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  649,   STR649,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 1 Beginn Tag/Monat
{0x063D09C5,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  650,   STR650,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 1 Ende Tag/Monat
{0x063D09C6,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  651,   STR651,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 2 Beginn Tag/Monat
{0x063D09C7,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  652,   STR652,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 2 Ende Tag/Monat
{0x220509C4,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  652,   STR652,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 2 Ende Tag/Monat - logged on OCI700 via LPB
{0x063D09C8,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  653,   STR653,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 3 Beginn Tag/Monat
{0x220509C5,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  653,   STR653,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 3 Beginn Tag/Monat - logged on OCI700 via LPB
{0x063D09C9,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  654,   STR654,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 3 Ende Tag/Monat
{0x063D09CA,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  655,   STR655,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 4 Beginn Tag/Monat
{0x063D09CB,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  656,   STR656,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 4 Ende Tag/Monat
{0x063D09CC,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  657,   STR657,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 5 Beginn Tag/Monat
{0x063D09CD,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  658,   STR658,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 5 Ende Tag/Monat
{0x063D09CE,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  659,   STR659,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 6 Beginn Tag/Monat
{0x063D09CF,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  660,   STR660,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 6 Ende Tag/Monat
{0x063D09D0,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  661,   STR661,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 7 Beginn Tag/Monat
{0x063D09D1,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  662,   STR662,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 7 Ende Tag/Monat
{0x063D09D2,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  663,   STR663,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 8 Beginn Tag/Monat
{0x063D09D3,  CAT_FERIEN_HK2,       VT_VACATIONPROG,  664,   STR664,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis 2 - Periode 8 Ende Tag/Monat
{0x2E3D04C2,  CAT_FERIEN_HK2,       VT_ENUM,          665,   STR665,   sizeof(ENUM665),      ENUM665,      DEFAULT_FLAG, DEV_ALL}, // [0] - Ferienheizkreis 2 - Betriebsniveau
// Ferien Heizkreis P
// virtuelle Zeilen
{0x073D09C4,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  666,   STR666,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 1 Beginn Tag/Monat
{0x073D09C5,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  667,   STR667,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 1 Ende Tag/Monat
{0x073D09C6,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  668,   STR668,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 2 Beginn Tag/Monat
{0x073D09C7,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  669,   STR669,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 2 Ende Tag/Monat
{0x073D09C8,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  670,   STR670,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 3 Beginn Tag/Monat
{0x073D09C9,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  671,   STR671,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 3 Ende Tag/Monat
{0x073D09CA,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  672,   STR672,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 4 Beginn Tag/Monat
{0x073D09CB,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  673,   STR673,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 4 Ende Tag/Monat
{0x073D09CC,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  674,   STR674,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 5 Beginn Tag/Monat
{0x073D09CD,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  675,   STR675,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 5 Ende Tag/Monat
{0x073D09CE,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  676,   STR676,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 6 Beginn Tag/Monat
{0x073D09CF,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  677,   STR677,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 6 Ende Tag/Monat
{0x073D09D0,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  678,   STR678,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 7 Beginn Tag/Monat
{0x073D09D1,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  679,   STR679,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 7 Ende Tag/Monat
{0x073D09D2,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  680,   STR680,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 8 Beginn Tag/Monat
{0x073D09D3,  CAT_FERIEN_HKP,       VT_VACATIONPROG,  681,   STR681,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [tt.MM ] - Ferienheizkreis P - Periode 8 Ende Tag/Monat
{0x2F3D04C2,  CAT_FERIEN_HKP,       VT_ENUM,          682,   STR682,   sizeof(ENUM682),      ENUM682,      DEFAULT_FLAG, DEV_ALL}, // [0] - Ferienheizkreis P - Betriebsniveau



// Einstellungen Heizkreis 1
{0x2D3D0574,  CAT_HK1,              VT_ENUM,          700,   STR700,   sizeof(ENUM700),      ENUM700,      DEFAULT_FLAG, DEV_ALL}, // [-] - Heizkreis 1 - Betriebsart ***(virtuelle Zeile)***
{0x2D3D0572,  CAT_HK1,              VT_ONOFF,         701,   STR701,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [-] - Heizkreis 1 - Präsenztaste (Absenkmodus bis zum nächsten BA-Wechsel laut Zeitplan) ***(virtuelle Zeile)***
{0x2D3D058E,  CAT_HK1,              VT_TEMP,          710,   STR710,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Komfortsollwert
//HEIZ->DISP ANS      2D3D05A5 00 08 C0 (35.0°C)
// line not in menue!
// virtuelle Zeile

{0x2D3D05A5,  CAT_HK1,              VT_TEMP,          711,   STR711,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Komfortsollwert Max
{0x2D3D0590,  CAT_HK1,              VT_TEMP,          712,   STR712,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Reduziertsollwert
{0x2D3D0592,  CAT_HK1,              VT_TEMP,          714,   STR714,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Frostschutzsollwert
{0x2D3D05A5,  CAT_HK1,              VT_TEMP,          716,   STR711,   0,                    NULL,         DEFAULT_FLAG, DEV_170_ALL}, // [°C ] - Heizkreis 1 - Komfortsollwert Max //FUJITSU
{0x2D3D05A5,  CAT_HK1,              VT_TEMP,          716,   STR711,   0,                    NULL,         DEFAULT_FLAG, DEV_119_ALL}, // [°C ] - Heizkreis 1 - Komfortsollwert Max //FUJITSU
{0x2D3D05F6,  CAT_HK1,              VT_FP02,          720,   STR720,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 1 - Kennlinie Steilheit
{0x2D3D0610,  CAT_HK1,              VT_TEMP,          721,   STR721,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Kennlinie Verschiebung
{0x2D3D060B,  CAT_HK1,              VT_ONOFF,         726,   STR726,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [] - Heizkreis 1 - Kennlinie Adaption
{0x2D3D05FD,  CAT_HK1,              VT_TEMP,          730,   STR730,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Sommer-/ Winterheizgrenze
{0x393D05FD,  CAT_HK1,              VT_TEMP,          730,   STR730,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [°C ] - Heizkreis 1 - Sommer-/ Winterheizgrenze
{0x2D3D0640,  CAT_HK1,              VT_TEMP,          732,   STR732,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Tagesheizgrenze
{0x213D0663,  CAT_HK1,              VT_TEMP,          740,   STR740,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Vorlaufsollwert Minimum
{0x213D0662,  CAT_HK1,              VT_TEMP,          741,   STR741,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Vorlaufsollwert Maximum
{0x213D0A88,  CAT_HK1,              VT_TEMP,          742,   STR742,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Vorlaufsollwert Raumthermostat HK1
{0x2D3D0D85,  CAT_HK1,              VT_PERCENT,       744,   STR744,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [% ] - Heizkreis 1 - Soll Einschaltverh R'stat
{0x2D3D0603,  CAT_HK1,              VT_PERCENT,       750,   STR750,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [% ] - Heizkreis 1 - Raumeinfluss
{0x2D3D0614,  CAT_HK1,              VT_TEMP,          760,   STR760,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Raumtemperaturbegrenzung
{0x053D0C9D,  CAT_HK1,              VT_PERCENT,       761,   STR761,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [% ] - Heizkreis 1 - Heizgrenze Raumregler
{0x2D3D0602,  CAT_HK1,              VT_TEMP,          770,   STR770,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Schnellaufheizung
{0x2D3D05E8,  CAT_HK1,              VT_ENUM,          780,   STR780,   sizeof(ENUM780),      ENUM780,      DEFAULT_FLAG, DEV_ALL}, // [-] - Heizkreis 1 - Schnellabsenkung
{0x2D3D0607,  CAT_HK1,              VT_MINUTES,       790,   STR790,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [Min ] - Heizkreis 1 - Einschalt-Optimierung Max.
{0x2D3D0609,  CAT_HK1,              VT_MINUTES,       791,   STR791,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [Min ] - Heizkreis 1 - Ausschalt-Optimierung Max.
{0x2D3D059E,  CAT_HK1,              VT_TEMP,          800,   STR800,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Reduziert-Anhebung Begin
{0x2D3D059D,  CAT_HK1,              VT_TEMP,          801,   STR801,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Reduziert-Anhebung Ende
{CMD_UNKNOWN, CAT_HK1,              VT_YESNO,         809,   STR809,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Pumpendauerlauf HK1
{0x213D0674,  CAT_HK1,              VT_ONOFF,         820,   STR820,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ - ] - Heizkreis 1 - Überhitzschutz Pumpenkreis
{0x213D065D,  CAT_HK1,              VT_TEMP,          830,   STR830,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Mischerüberhöhung
{0x213D0654,  CAT_HK1,              VT_ENUM,          832,   STR832,   sizeof(ENUM832),      ENUM832,      FL_RONLY, DEV_ALL}, // - Antrieb Typ
{0x213D065C,  CAT_HK1,              VT_TEMP,          833,   STR833,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // - Schaltdifferenz 2-Punkt
{0x213D065A,  CAT_HK1,              VT_SECONDS_WORD,  834,   STR834,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ s ] - Antrieb Laufzeit
{0x213D0658,  CAT_HK1,              VT_TEMP,          835,   STR835,   0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Heizkreis 1 - Mischer P-Band Xp
{0x213D0659,  CAT_HK1,              VT_SECONDS_WORD,  836,   STR836,   0,                    NULL,         FL_OEM, DEV_ALL}, // [ s ] - Mischer Nachstellzeit Tn
{0x2D3D067B,  CAT_HK1,              VT_ENUM,          850,   STR850,   sizeof(ENUM850),      ENUM850,      DEFAULT_FLAG, DEV_ALL}, // [-] - Heizkreis 1 - Estrichfunktion
{0x2D3D068A,  CAT_HK1,              VT_TEMP,          851,   STR851,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Estrich Sollwert manuell
{0x2D3D067D,  CAT_HK1,              VT_TEMP,       	  855,   STR855,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Vorlauf-Sollwert Estrich Austrocknung
{0x2D3D067C,  CAT_HK1,              VT_DAYS,          856,   STR856,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Estrich-Austrocknung Tag
{0x2D3D0DF2,  CAT_HK1,              VT_BYTE,          856,   STR856,   0,                    NULL,         DEFAULT_FLAG, DEV_170_ALL}, // [°C ] - Heizkreis 1 - Estrich Tag aktuell //FUJITSU
{0x2D3D0DF2,  CAT_HK1,              VT_DAYS,          857,   STR857,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 1 - Estrich Tage erfüllt
{0x213D0B43,  CAT_HK1,              VT_BYTE,          857,   STR857,   0,                    NULL,         DEFAULT_FLAG, DEV_170_ALL}, // [°C ] - Heizkreis 1 - Estrich Tage erfüllt //FUJITSU
{0x213D08C9,  CAT_HK1,              VT_ENUM,          861,   STR861,   sizeof(ENUM861),      ENUM861,      DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 1 - Übertemperaturabnahme
{0x213D065E,  CAT_HK1,              VT_PERCENT,       864,   STR864,   0,                    NULL,         FL_RONLY, DEV_ALL}, // Sperrsignalverstärkung
{0x2D3D07C4,  CAT_HK1,              VT_YESNO,         870,   STR870,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 1 - Mit Pufferspeicher
{0x2D3D07C5,  CAT_HK1,              VT_YESNO,         872,   STR872,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 1 - Mit Vorregler/Zubring`pumpe
{0x213D04AD,  CAT_HK1,              VT_ENUM,          880,   STR880,   sizeof(ENUM880),      ENUM880,      DEFAULT_FLAG, DEV_ALL}, // HK1 Pumpe Drehzahlreduktion
{0x213D04AB,  CAT_HK1,              VT_PERCENT,       882,   STR882,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendrehzahl Minimum // todo die ID gibt es, aber sie gehoert nicht zu diesem Parameter
{0x053D115E,  CAT_HK1,              VT_PERCENT,       882,   STR882,   0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // [%] - Heizkreis 1 - Pumpendrehzahl Minimum
{0x213D04AA,  CAT_HK1,              VT_PERCENT,       883,   STR883,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendrehzahl Maximum
{0x053D115F,  CAT_HK1,              VT_PERCENT,       883,   STR883,   0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // [%] - Heizkreis 1 - Pumpendrehzahl Maximum
{0x113D2F95,  CAT_HK1,              VT_BYTE,          884,   STR884,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 884 Drehzahlstufe Ausleg'punkt [1-50 9-13kW=16 17-25kW=19 35-50kW=24]
{0x113D304F,  CAT_HK1,              VT_PERCENT5,      885,   STR885,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 885 Pumpe-PWM Minimum [%]
{0x113D04AB,  CAT_HK1,              VT_PERCENT,       885,   STR885,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Thision 885 Pumpe-PWM Minimum [%] - logged on OCI700 via LPB
{0x193D2F88,  CAT_HK1,              VT_TEMP_SHORT,    886,   STR886,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 886 Norm Aussentemperatur [°C]
{0x053D3050,  CAT_HK1,              VT_TEMP_SHORT5_US,887,   STR887,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 887 Vorlaufsoll NormAussentemp [°C]
{0x393D2F82,  CAT_HK1,              VT_TEMP_WORD5_US, 887,   STR887,   0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Thision 887 Vorlaufsoll NormAussentemp [°C] - logged on OCI700 via LPB
{0x253D2FE5,  CAT_HK1,              VT_PERCENT_WORD1, 888,   STR888,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 888 dt Überhöhungsfaktor [%]
{0x213D0E38,  CAT_HK1,              VT_PERCENT,       888,   STR888_2, 0,                    NULL,         DEFAULT_FLAG, DEV_108_ALL}, // dt Überhöhungsfaktor [%]
{0x213D0E38,  CAT_HK1,              VT_PERCENT,       888,   STR888_2, 0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // dt Überhöhungsfaktor [%]
{0x213D0E38,  CAT_HK1,              VT_PERCENT,       888,   STR888_2, 0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // dt Überhöhungsfaktor [%]
{0x213D0E38,  CAT_HK1,              VT_PERCENT,       888,   STR888_2, 0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // dt Überhöhungsfaktor [%]
{0x213D0E38,  CAT_HK1,              VT_PERCENT,       888,   STR888_2, 0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // dt Überhöhungsfaktor [%]
{0x213D0E38,  CAT_HK1,              VT_PERCENT,       888,   STR888_2, 0,                    NULL,         DEFAULT_FLAG, DEV_205_ALL}, // dt Überhöhungsfaktor [%]
{0x213D0E38,  CAT_HK1,              VT_PERCENT,       888,   STR888_2, 0,                    NULL,         DEFAULT_FLAG, DEV_211_ALL}, // dt Überhöhungsfaktor [%]
{0x213D10C2,  CAT_HK1,              VT_YESNO,         890,   STR890,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // WOB20C/WOB25C Vorl'sollwertkorr Drehz'reg HK1
{0x193D2F8A,  CAT_HK1,              VT_TEMP_SHORT5,   894,   STR894,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 894 dt Spreizung Norm Aussent. [°C]
{0x193D2F8B,  CAT_HK1,              VT_TEMP_SHORT5,   895,   STR895,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 895 dt Spreizung Maximum [°C]
{0x053D0DD4,  CAT_HK1,              VT_ENUM,          898,   STR898,   sizeof(ENUM898),      ENUM898,      DEFAULT_FLAG, DEV_ALL}, // Betriebsniveauumschaltung
{0x053D07BE,  CAT_HK1,              VT_ENUM,          900,   STR900,   sizeof(ENUM900),      ENUM900,      DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 1 - Betriebsartumschaltung
{0x053D07BE,  CAT_HK1,              VT_ENUM,          900,   STR900,   sizeof(ENUM900_2),    ENUM900_2,    DEFAULT_FLAG, DEV_096_ALL}, // [0] - Heizkreis 1 - Betriebsartumschaltung

// Kühlkreis 1
{0x653D0A26,  CAT_KUEHL1,           VT_UNKNOWN,       901,   STR901,   sizeof(ENUM700),      ENUM700,      DEFAULT_FLAG, DEV_ALL}, // Betriebsart
{0x653D0A1A,  CAT_KUEHL1,           VT_TEMP,          902,   STR902,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Komfortsollwert
{0x653D0A80,  CAT_KUEHL1,           VT_TEMP,          904,   STR904,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Raumtemperatur Schutzsollwert Kühlkreis 1
{CMD_UNKNOWN, CAT_KUEHL1,           VT_UNKNOWN,       907,   STR907,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Freigabe
{0x653D0A20,  CAT_KUEHL1,           VT_TEMP,          908,   STR908,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Vorlaufsollwert bei TA 25 °C
{0x653D0A21,  CAT_KUEHL1,           VT_TEMP,          909,   STR909,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Vorlaufsollwert bei TA 35 °C
{0x653D0A22,  CAT_KUEHL1,           VT_TEMP,          912,   STR912,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Kühlgrenze bei TA
{0x693D0A75,  CAT_KUEHL1,           VT_HOURS_SHORT,   913,   STR913,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sperrdauer nach Heizende
{0x653D0A25,  CAT_KUEHL1,           VT_TEMP,          918,   STR918,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sommerkomp Beginn bei TA
{0x653D0A24,  CAT_KUEHL1,           VT_TEMP,          919,   STR919,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sommerkomp Ende bei TA
{0x653D0A1B,  CAT_KUEHL1,           VT_TEMP,          920,   STR920,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sommerkomp Sollw’anhebung
{CMD_UNKNOWN, CAT_KUEHL1,           VT_TEMP,          923,   STR923,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Vorlaufsollwert Min bei TA 25 °C
{0x653D0A1F,  CAT_KUEHL1,           VT_TEMP,          924,   STR924,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Vorlaufsollwert Min bei TA 35 °C
{0x653D0A27,  CAT_KUEHL1,           VT_PERCENT,       928,   STR928,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Raumeinfluss
{0x653D0A23,  CAT_KUEHL1,           VT_TEMP,          932,   STR932,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Raumtemperaturbegrenzung
{0x693D0B65,  CAT_KUEHL1,           VT_TEMP,          938,   STR938,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Mischerunterkühlung
{CMD_UNKNOWN, CAT_KUEHL1,           VT_UNKNOWN,       939,   STR939,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Antrieb Typ
{CMD_UNKNOWN, CAT_KUEHL1,           VT_UNKNOWN,       940,   STR940,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Schaltdifferenz 2-Punkt
{0x693D0A7D,  CAT_KUEHL1,           VT_SECONDS_WORD,  941,   STR941,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Antrieb Laufzeit
{CMD_UNKNOWN, CAT_KUEHL1,           VT_UNKNOWN,       942,   STR942,   0,                    NULL,         FL_OEM, DEV_ALL}, // Mischer P-Band Xp
{CMD_UNKNOWN, CAT_KUEHL1,           VT_UNKNOWN,       943,   STR943,   0,                    NULL,         FL_OEM, DEV_ALL}, // Mischer Nachstellzeit Tn
{0x053D0D15,  CAT_KUEHL1,           VT_UNKNOWN,       945,   STR945,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Mischventil im Heizbetrieb
{0x053D0D15,  CAT_KUEHL1,           VT_UNKNOWN,       946,   STR946,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sperrdauer Taupunktwächt
{CMD_UNKNOWN, CAT_KUEHL1,           VT_UNKNOWN,       947,   STR947,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Vorlaufsollw’anhebung Hygro
{CMD_UNKNOWN, CAT_KUEHL1,           VT_UNKNOWN,       948,   STR948,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Vorl'anhebung Beginn bei r. F.
{CMD_UNKNOWN, CAT_KUEHL1,           VT_UNKNOWN,       950,   STR950,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Vorlauftemp'diff Taupunkt
{CMD_UNKNOWN, CAT_KUEHL1,           VT_UNKNOWN,       962,   STR962,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Mit Pufferspeicher
{0x653D0B69,  CAT_KUEHL1,           VT_ONOFF,         963,   STR963,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Mit Vorregler/Zubring'pumpe
{0x053D0B7A,  CAT_KUEHL1,           VT_ONOFF,         969,   STR969,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Betriebsartumschaltung

// Heizkreis 2
{0x2E3D0574,  CAT_HK2,              VT_ENUM,          1000,  STR1000,  sizeof(ENUM1000),     ENUM1000,     DEFAULT_FLAG, DEV_ALL}, // [-] - Heizkreis 2 - Betriebsart ***(virtuelle Zeile)***
{0x050507BE,  CAT_HK2,              VT_ENUM,          1000,  STR1000,  sizeof(ENUM1000),     ENUM1000,     DEFAULT_FLAG, DEV_090_ALL}, // [-] - Heizkreis 2 - Betriebsart ***(virtuelle Zeile)***
{0x2E3E0572,  CAT_HK2,              VT_ONOFF,         1001,  STR1001,  0,                    0,            DEFAULT_FLAG, DEV_ALL}, // [-] - Heizkreis 2 - Präsenztaste (Absenkmodus bis zum nächsten BA-Wechsel laut Zeitplan) ***(virtuelle Zeile)***
{0x2E3D0572,  CAT_HK2,              VT_ONOFF,         1001,  STR1001,  0,                    0,            DEFAULT_FLAG, DEV_ALL}, // [-] - Heizkreis 2 - Präsenztaste (Absenkmodus bis zum nächsten BA-Wechsel laut Zeitplan) ***(virtuelle Zeile)***
{0x2E3D058E,  CAT_HK2,              VT_TEMP,          1010,  STR1010,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Komfortsollwert
// line not in menue!
// virtuelle Zeile
{0x2E3D05A5,  CAT_HK2,              VT_TEMP,          1011,  STR1011,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 - Komfortsollwert Max
{0x2E3D0590,  CAT_HK2,              VT_TEMP,          1012,  STR1012,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Reduziertsollwert
{0x2E3D0592,  CAT_HK2,              VT_TEMP,          1014,  STR1014,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Frostschutzsollwert
{0x2E3D05F6,  CAT_HK2,              VT_FP02,          1020,  STR1020,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 2 (nur wenn aktiviert) - Kennlinie Steilheit
{0x2E3D0610,  CAT_HK2,              VT_TEMP,          1021,  STR1021,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Kennlinie Verschiebung
{0x2E3D060B,  CAT_HK2,              VT_ONOFF,         1026,  STR1026,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [] - Heizkreis 2 (nur wenn aktiviert) - Kennlinie Adaption
{0x2E3D05FD,  CAT_HK2,              VT_TEMP,          1030,  STR1030,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Sommer-/ Winterheizgrenze
{0x2E3D0640,  CAT_HK2,              VT_TEMP,          1032,  STR1032,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Tagesheizgrenze
{0x223D0663,  CAT_HK2,              VT_TEMP,          1040,  STR1040,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Vorlaufsollwert Minimum
{0x223D0662,  CAT_HK2,              VT_TEMP,          1041,  STR1041,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Vorlaufsollwert Maximum
{0x223D0A88,  CAT_HK2,              VT_TEMP,          1042,  STR1042,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Vorlaufsollwert Raumthermostat // Command ID tbc
{0x2E3D0603,  CAT_HK2,              VT_PERCENT,       1050,  STR1050,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [% ] - Heizkreis 2 (nur wenn aktiviert) - Raumeinfluss
{0x2E3D0614,  CAT_HK2,              VT_TEMP,          1060,  STR1060,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Raumtemperaturbegrenzung
{0x2E3D0602,  CAT_HK2,              VT_TEMP,          1070,  STR1070,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Schnellaufheizung
{0x2E3D05E8,  CAT_HK2,              VT_ENUM,          1080,  STR1080,  sizeof(ENUM1080),     ENUM1080,     DEFAULT_FLAG, DEV_ALL}, // [-] - Heizkreis 2 (nur wenn aktiviert) - Schnellabsenkung
{0x2E3D0607,  CAT_HK2,              VT_MINUTES,       1090,  STR1090,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [min] - Heizkreis 2 (nur wenn aktiviert) - Einschalt-Optimierung Max.
{0x2E3D0609,  CAT_HK2,              VT_MINUTES,       1091,  STR1091,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [min] - Heizkreis 2 (nur wenn aktiviert) - Ausschalt-Optimierung Max.
{0x2E3D059E,  CAT_HK2,              VT_TEMP,          1100,  STR1100,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Reduziert-Anhebung Begin
{0x2E3D059D,  CAT_HK2,              VT_TEMP,          1101,  STR1101,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Reduziert-Anhebung Ende
{CMD_UNKNOWN, CAT_HK2,              VT_YESNO,         1109,  STR1109,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 - Pumpendauerlauf HK2
{0x223D0674,  CAT_HK2,              VT_ONOFF,         1120,  STR1120,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ - ] - Heizkreis 2 (nur wenn aktiviert) - Überhitzschutz Pumpenkreis
{0x223D065D,  CAT_HK2,              VT_TEMP,          1130,  STR1130,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Mischerüberhöhung
{0x223D065D,  CAT_HK2,              VT_TEMP_WORD5_US, 1130,  STR1130,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Mischerüberhöhung - logged on OCI700 via LPB
{0x223D0654,  CAT_HK2,              VT_ENUM,          1132,  STR1132,  sizeof(ENUM1132),     ENUM1132,     DEFAULT_FLAG, DEV_ALL}, // Antrieb Typ
{0x223D065C,  CAT_HK2,              VT_TEMP,          1133,  STR1133,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Schaltdiffernez 2-Punkt
{0x223D065A,  CAT_HK2,              VT_SECONDS_WORD,  1134,  STR1134,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 1134 Antrieb Laufzeit [s]
{0x2E3D065A,  CAT_HK2,              VT_SECONDS_WORD,  1134,  STR1134,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Thision 1134 Antrieb Laufzeit [s] - logged on OCI700 via LPB
{0x223D0658,  CAT_HK2,              VT_TEMP,          1135,  STR1135,  0,                    NULL,         FL_OEM, DEV_ALL}, // TODO Thision 1135 Mischer P-Band XP [K]
{0x223D0659,  CAT_HK2,              VT_SECONDS_WORD,  1136,  STR1136,  0,                    NULL,         FL_OEM, DEV_ALL}, // Mischer Nachstellzeit Tn
{0x2E3D067B,  CAT_HK2,              VT_ENUM,          1150,  STR1150,  sizeof(ENUM1150),     ENUM1150,     DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 2 (nur wenn aktiviert) - Estrichfunktion
{0x2E3D068A,  CAT_HK2,              VT_TEMP,          1151,  STR1151,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 2 (nur wenn aktiviert) - Estrich sollwert manuell
{0x2E3D067D,  CAT_HK2,              VT_TEMP,          1155,  STR1155,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 1155 Estrich Sollwert aktuell [Tage]
{0x2E3D067C,  CAT_HK2,              VT_DAYS,          1156,  STR1156,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Estrich Tag aktuell
{0x2E3D0DF2,  CAT_HK2,              VT_DAYS,          1157,  STR1157,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Estrich Tag erfüllt
{0x223D0B43,  CAT_HK2,              VT_DAYS,          1157,  STR1157,  0,                    NULL,         FL_RONLY, DEV_107_ALL}, // Estrich Tag erfüllt? logged from ACS700 diagnosis software

{0x223D08C9,  CAT_HK2,              VT_ENUM,          1161,  STR1161,  sizeof(ENUM1161),     ENUM1161,     DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 2 (nur wenn aktiviert) - Übertemperaturabnahme
{0x2E3D07C4,  CAT_HK2,              VT_YESNO,         1170,  STR1170,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 2 (nur wenn aktiviert) - Mit Pufferspeicher
{0x2E3D07C5,  CAT_HK2,              VT_YESNO,         1172,  STR1172,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 2 (nur wenn aktiviert) - Mit Vorregler/Zubring`pumpe
{0x223D04AD,  CAT_HK2,              VT_ENUM,          1180,  STR1180,  sizeof(ENUM1180),     ENUM1180,     DEFAULT_FLAG, DEV_ALL}, // HK2 Pumpe Drehzahlreduktion
{0x223D04AB,  CAT_HK2,              VT_PERCENT,       1182,  STR1182,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendrehzahl Minimum
{0x223D04AA,  CAT_HK2,              VT_PERCENT,       1183,  STR1183,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendrehzahl Maximum
{0x063D07BE,  CAT_HK2,              VT_ENUM,          1200,  STR1200,  sizeof(ENUM1200),     ENUM1200,     DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 2 (nur wenn aktiviert) - Betriebsartumschaltung
{0x063D07BE,  CAT_HK2,              VT_ENUM,          1200,  STR1200,  sizeof(ENUM1200_2),   ENUM1200_2,   DEFAULT_FLAG, DEV_096_ALL}, // [0] - Heizkreis 2 (nur wenn aktiviert) - Betriebsartumschaltung

// Einstellungen Heizkreis P/3, only visible when Heizkreis P exists
{0x2F3D0574,  CAT_HKP,              VT_ENUM,          1300,  STR1300,  sizeof(ENUM1300),     ENUM1300,     DEFAULT_FLAG, DEV_ALL}, // Betriebsart
{0x2F3D0572,  CAT_HKP,              VT_ONOFF,         1301,  STR1301,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [-] - Heizkreis 3/P - Präsenztaste (Absenkmodus bis zum nächsten BA-Wechsel laut Zeitplan) ***(virtuelle Zeile)***
{0x2F3D058E,  CAT_HKP,              VT_TEMP,          1310,  STR1310,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Komfortsollwert
{0x2F3D05A5,  CAT_HKP,              VT_TEMP,          1311,  STR1311,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P - Komfortsollwert Max
{0x2F3D0590,  CAT_HKP,              VT_TEMP,          1312,  STR1312,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Reduziertsollwert
{0x2F3D0592,  CAT_HKP,              VT_TEMP,          1314,  STR1314,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Frostschutzsollwert
{0x2F3D05F6,  CAT_HKP,              VT_FP02,          1320,  STR1320,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 3/P (nur wenn aktiviert) - Kennlinie Steilheit
{0x2F3D0610,  CAT_HKP,              VT_TEMP,          1321,  STR1321,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Kennlinie Verschiebung
{0x2F3D060B,  CAT_HKP,              VT_ONOFF,         1326,  STR1326,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Kennlinie Adaption
{0x2F3D05FD,  CAT_HKP,              VT_TEMP,          1330,  STR1330,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Sommer-/ Winterheizgrenze
{0x2F3D0640,  CAT_HKP,              VT_TEMP,          1332,  STR1332,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Tagesheizgrenze
{0x233D0663,  CAT_HKP,              VT_TEMP,          1340,  STR1340,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Vorlaufsollwert Minimum
{0x233D0662,  CAT_HKP,              VT_TEMP,          1341,  STR1341,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Vorlaufsollwert Maximum
{0x233D0A88,  CAT_HKP,              VT_PERCENT,       1350,  STR1350,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [% ] - Heizkreis 3/P (nur wenn aktiviert) - Raumeinfluss
{0x2F3D0614,  CAT_HKP,              VT_TEMP   ,       1360,  STR1360,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Raumtemperaturbegrenzung
{0x2F3D0602,  CAT_HKP,              VT_TEMP,          1370,  STR1370,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Schnellaufheizung
{0x2F3D05E8,  CAT_HKP,              VT_ENUM,          1380,  STR1380,  sizeof(ENUM1380),     ENUM1380,     DEFAULT_FLAG, DEV_ALL}, // [-] - Heizkreis 3/P (nur wenn aktiviert) - Schnellabsenkung
{0x2F3D0607,  CAT_HKP,              VT_MINUTES,       1390,  STR1390,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [min] - Heizkreis 3/P (nur wenn aktiviert) - Einschalt-Optimierung Max.
{0x2F3D0609,  CAT_HKP,              VT_MINUTES,       1391,  STR1391,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [min] - Heizkreis 3/P (nur wenn aktiviert) - Ausschalt-Optimierung Max.
{0x2F3D059E,  CAT_HKP,              VT_TEMP,          1400,  STR1400,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Reduziert-Anhebung Begin
{0x2F3D059D,  CAT_HKP,              VT_TEMP,          1401,  STR1401,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Reduziert-Anhebung Ende
{0x233D0674,  CAT_HKP,              VT_ONOFF,         1420,  STR1420,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ - ] - Heizkreis 3/P (nur wenn aktiviert) - Überhitzschutz Pumpenkreis
{0x233D065D,  CAT_HKP,              VT_TEMP,          1430,  STR1430,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Mischerüberhöhung
{0x233D065A,  CAT_HKP,              VT_SECONDS_WORD,  1434,  STR1434,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Antrieb Laufzeit HKP
{0x2F3D067B,  CAT_HKP,              VT_ENUM,          1450,  STR1450,  sizeof(ENUM1450),     ENUM1450,     DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 3/P (nur wenn aktiviert) - Estrichfunktion
{0x2F3D068A,  CAT_HKP,              VT_TEMP,          1451,  STR1451,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Heizkreis 3/P (nur wenn aktiviert) - Estrich sollwert manuell
{0x2F3D067D,  CAT_HKP,              VT_TEMP,          1455,  STR1455,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Estrich Sollwert aktuell
{0x2F3D067C,  CAT_HKP,              VT_DAYS,          1456,  STR1456,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Estrich Tag aktuell
{0x233D0DF2,  CAT_HKP,              VT_BYTE,          1457,  STR1457,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Estrich Tag erfüllt
{0x233D08C9,  CAT_HKP,              VT_ENUM,          1461,  STR1461,  sizeof(ENUM1461),     ENUM1461,     DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 3/P (nur wenn aktiviert) - Übertemperaturabnahme
{0x2F3D07C4,  CAT_HKP,              VT_YESNO,         1470,  STR1470,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 3/P (nur wenn aktiviert) - Mit Pufferspeicher
{0x2F3D07C5,  CAT_HKP,              VT_YESNO,         1472,  STR1472,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 3/P (nur wenn aktiviert) - Mit Vorregler/Zubring`pumpe
{0x233D04AB,  CAT_HKP,              VT_PERCENT,       1482,  STR1482,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendrehzahl Minimum
{0x233D04AA,  CAT_HKP,              VT_PERCENT,       1483,  STR1483,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendrehzahl Maximum
{0x073D07BE,  CAT_HKP,              VT_ENUM,          1500,  STR1500,  sizeof(ENUM1500),     ENUM1500,     DEFAULT_FLAG, DEV_ALL}, // [0] - Heizkreis 3/P (nur wenn aktiviert) - Betriebsartumschaltung
{0x073D07BE,  CAT_HKP,              VT_ENUM,          1500,  STR1500,  sizeof(ENUM1500_2),   ENUM1500_2,   DEFAULT_FLAG, DEV_096_ALL}, // [0] - Heizkreis 3/P (nur wenn aktiviert) - Betriebsartumschaltung

// Einstellungen Trinkwasser
{0x313D0571,  CAT_TW,               VT_ENUM,          1600,  STR1600,  sizeof(ENUM1600),     ENUM1600,     DEFAULT_FLAG, DEV_ALL}, // [-] - Trinkwasser - Trinkwasserbetrieb Ein/Aus ***(virtuelle Zeile)***
{0x313D0573,  CAT_TW,               VT_ONOFF,         1601,  STR1601,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [-] - Trinkwasser - Manueller Push Ein/Aus ***(virtuelle Zeile)***
{0x313D0212,  CAT_TW,               VT_BIT,           1602,  STR1602,  sizeof(ENUM1602),     ENUM1602,     DEFAULT_FLAG, DEV_ALL}, // Status Trinkwasserbereitung
{0x31000212,  CAT_TW,               VT_BIT,           1602,  STR1602,  sizeof(ENUM1602),     ENUM1602,     DEFAULT_FLAG, DEV_ALL}, // Status Trinkwasserbereitung
{0x313D06B9,  CAT_TW,               VT_TEMP,          1610,  STR1610,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Trinkwasser - Nennsollwert
{0x313D06BA,  CAT_TW,               VT_TEMP,          1612,  STR1612,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Trinkwasser - Reduziertsollwert
{0x313D06B8,  CAT_TW,               VT_TEMP,          1614,  STR1614,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Trinkwasser - Nennsollwert Maximum
{0x253D0722,  CAT_TW,               VT_ENUM,          1620,  STR1620,  sizeof(ENUM1620),     ENUM1620,     DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser - Freigabe
{0x253D0722,  CAT_TW,               VT_ENUM,          1620,  STR1620,  sizeof(ENUM1620_2),   ENUM1620_2,   DEFAULT_FLAG, DEV_108_ALL}, // [0] - Trinkwasser - Freigabe
{0x313D0721,  CAT_TW,               VT_ENUM,          1630,  STR1630,  sizeof(ENUM1630),     ENUM1630,     DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser - Ladevorgang
{0x313D0759,  CAT_TW,               VT_ENUM,          1640,  STR1640,  sizeof(ENUM1640),     ENUM1640,     DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser - Legionellenfunktion
{0x313D0738,  CAT_TW,               VT_DAYS,          1641,  STR1641,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [Tage ] - Trinkwasser - Legionellenfkt. Periodisch
{0x313D075E,  CAT_TW,               VT_ENUM,          1642,  STR1642,  sizeof(ENUM_WEEKDAY), ENUM_WEEKDAY, DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser - Legionellenfkt. Wochentag
{0x313D075A,  CAT_TW,               VT_HOUR_MINUTES,  1644,  STR1644,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [hh:mm ] - Trinkwasser - Legionellenfkt. Zeitpunkt
{0x313D06BC,  CAT_TW,               VT_TEMP,          1645,  STR1645,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Trinkwasser - Legionellenfkt. Sollwert
{0x113D06BC,  CAT_TW,               VT_TEMP,          1645,  STR1645,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [°C ] - Trinkwasser - Legionellenfkt. Sollwert - logged on OCI700 via LPB
{0x313D0496,  CAT_TW,               VT_MINUTES_WORD,  1646,  STR1646,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [min] - Trinkwasser - Legionellenfkt. Verweildauer
{0x313D08AB,  CAT_TW,               VT_ONOFF,         1647,  STR1647,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser - Legionellenfkt. Zirk`pumpe
{0x253D072E,  CAT_TW,               VT_ENUM,          1660,  STR1660,  sizeof(ENUM1660),     ENUM1660,     DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser - Zirkulationspumpe Freigabe
{0x253D0689,  CAT_TW,               VT_ONOFF,         1661,  STR1661,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser - Zirk`pumpe Taktbetrieb
{0x253D077E,  CAT_TW,               VT_TEMP,          1663,  STR1663,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Trinkwasser - Zirkulations Sollwert
{0x053D0E84,  CAT_TW,               VT_ENUM,          1680,  STR1680,  sizeof(ENUM1680),     ENUM1680,     DEFAULT_FLAG, DEV_ALL}, // Betriebsartumschaltung

// Hx-Pumpe
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_YESNO,         2008,  STR2008,  0,                    NULL,         FL_OEM, DEV_ALL}, // H1 TWW-Ladevorrang
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_ONOFF,         2010,  STR2010,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ - ] - H1/H3-Pumpe (nur wenn aktiviert) - H1 Übertemperaturabnahme
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_YESNO,         2012,  STR2012,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [-] - H1/H3-Pumpe (nur wenn aktiviert) - H1 mit Pufferspeicher
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_YESNO,         2014,  STR2014,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ - ] - H1/H3-Pumpe (nur wenn aktiviert) - H1 Vorregler/Zubring`pumpe
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_UNKNOWN,       2015,  STR2015,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // H1 Kälteanforderung
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_YESNO,         2033,  STR2033,  0,                    NULL,         FL_OEM, DEV_ALL}, // H2 TWW-Ladevorrang
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_ONOFF,         2035,  STR2035,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // H2 Übertemperaturabnahme
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_YESNO,         2037,  STR2037,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // H2 mit Pufferspeicher
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_YESNO,         2039,  STR2039,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // H2 Vorregler / Zubring'pumpe
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_UNKNOWN,       2040,  STR2040,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // H2 Kälteanforderung
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_YESNO,         2044,  STR2044,  0,                    NULL,         FL_OEM, DEV_ALL}, // H3 TWW-Ladevorrang
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_ONOFF,         2046,  STR2046,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ - ] - H1/H3-Pumpe (nur wenn aktiviert) - H3 Übertemperaturabnahme
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_YESNO,         2048,  STR2048,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [-] - H1/H3-Pumpe (nur wenn aktiviert) - H3 mit Pufferspeicher
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_YESNO,         2050,  STR2050,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ - ] - H1/H3-Pumpe (nur wenn aktiviert) - H3 Vorregler/Zubring`pumpe
{CMD_UNKNOWN, CAT_HXPUMPE,          VT_UNKNOWN,       2051,  STR2051,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // H3 Kälteanforderung

// Schwimmbad
{0x493D0555,  CAT_SCHWIMMBAD,       VT_TEMP,          2055,  STR2055,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sollwert Solarbeheizung
{CMD_UNKNOWN, CAT_SCHWIMMBAD,       VT_UNKNOWN,       2056,  STR2056,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sollwert Erzeugerbeheizung
{CMD_UNKNOWN, CAT_SCHWIMMBAD,       VT_YESNO,         2065,  STR2065,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Ladevorrang Solar
{CMD_UNKNOWN, CAT_SCHWIMMBAD,       VT_UNKNOWN,       2070,  STR2070,  0,                    NULL,         FL_OEM, DEV_ALL}, // Schwimmbadtemp Maximum
{CMD_UNKNOWN, CAT_SCHWIMMBAD,       VT_YESNO,         2080,  STR2080,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Mit Solareinbindung

// Vorregler/Zubringerpumpe
{0x1D3D079D,  CAT_VORREGLERPUMPE,   VT_TEMP,          2110,  STR2110,  0,                    NULL,         FL_OEM, DEV_ALL}, // Vorlaufsollwert Minimum
{0x1D3D07BC,  CAT_VORREGLERPUMPE,   VT_TEMP,          2111,  STR2111,  0,                    NULL,         FL_OEM, DEV_ALL}, // Vorlaufsollwert Maximum
{CMD_UNKNOWN, CAT_VORREGLERPUMPE,   VT_UNKNOWN,       2112,  STR2112,  0,                    NULL,         FL_OEM, DEV_ALL}, // Vorlaufsollwert Kühlen Min
{CMD_UNKNOWN, CAT_VORREGLERPUMPE,   VT_UNKNOWN,       2130,  STR2130,  0,                    NULL,         FL_OEM, DEV_ALL}, // Mischerüberhöhung
{CMD_UNKNOWN, CAT_VORREGLERPUMPE,   VT_UNKNOWN,       2131,  STR2131,  0,                    NULL,         FL_OEM, DEV_ALL}, // Mischerunterkühlung
{CMD_UNKNOWN, CAT_VORREGLERPUMPE,   VT_ENUM,          2132,  STR2132,  sizeof(ENUM2132),     ENUM2132,     FL_OEM, DEV_ALL}, // Antrieb Typ
{CMD_UNKNOWN, CAT_VORREGLERPUMPE,   VT_UNKNOWN,       2133,  STR2133,  0,                    NULL,         FL_OEM, DEV_ALL}, // Schaltdifferenz 2-Punkt
{CMD_UNKNOWN, CAT_VORREGLERPUMPE,   VT_UNKNOWN,       2134,  STR2134,  0,                    NULL,         FL_OEM, DEV_ALL}, // Antrieb Laufzeit
{CMD_UNKNOWN, CAT_VORREGLERPUMPE,   VT_UNKNOWN,       2135,  STR2135,  0,                    NULL,         FL_OEM, DEV_ALL}, // Mischer P-Band Xp
{CMD_UNKNOWN, CAT_VORREGLERPUMPE,   VT_UNKNOWN,       2136,  STR2136,  0,                    NULL,         FL_OEM, DEV_ALL}, // Mischer Nachstellzeit Tn
{CMD_UNKNOWN, CAT_VORREGLERPUMPE,   VT_ENUM,          2150,  STR2150,  sizeof(ENUM2150),     ENUM2150,     DEFAULT_FLAG, DEV_ALL}, // Vorregler/Zubringerpumpe

// Kessel
{0x0D3D0949,  CAT_KESSEL,           VT_ENUM,          2200,  STR2200,  sizeof(ENUM2200),     ENUM2200,     FL_OEM, DEV_ALL}, // Kessel - Betriebsart
{0x0D3D08D3,  CAT_KESSEL,           VT_ONOFF,         2201,  STR2201,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 2201 Erzeugersperre [Ein/Aus]
{0x113D04D3,  CAT_KESSEL,           VT_TEMP,          2203,  STR2203,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Freigabe unter Außentemp
{0x113D11F3,  CAT_KESSEL,           VT_TEMP,          2204,  STR2204,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Freigabe über Außentemp
{0x053D0D16,  CAT_KESSEL,           VT_ENUM,          2205,  STR2205,  sizeof(ENUM2205),     ENUM2205,     DEFAULT_FLAG, DEV_ALL}, // Bei Ökobetrieb
{0x053D0236,  CAT_KESSEL,           VT_ENUM,          2206,  STR2206,  sizeof(ENUM2206),     ENUM2206,     DEFAULT_FLAG, DEV_ALL}, // Kessel - Standby/Betrieb
{0x113D0B50,  CAT_KESSEL,           VT_ONOFF,         2208,  STR2208,  0,                    NULL,         FL_OEM, DEV_ALL}, // Durchladung Pufferspeicher (EIN/AUS)
{0x0D3D092C,  CAT_KESSEL,           VT_TEMP,          2210,  STR2210,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Kessel - Sollwert Minimum
{0x2D3D092C,  CAT_KESSEL,           VT_TEMP_WORD5_US, 2210,  STR2210,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [°C ] - Kessel - Sollwert Minimum - logged on OCI700 via LPB
{0x0D3D092D,  CAT_KESSEL,           VT_TEMP,          2211,  STR2211,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Kessel - Sollwert Minimum OEM
{0x0D3D092B,  CAT_KESSEL,           VT_TEMP,          2212,  STR2212,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Kessel - Sollwert maximum
{0x093D0952,  CAT_KESSEL,           VT_TEMP_WORD5_US, 2212,  STR2212,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [°C ] - Kessel - Sollwert maximum - logged on OCI700 via LPB
{0x053D08F3,  CAT_KESSEL,           VT_TEMP,          2213,  STR2213,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Kessel - Sollwert Maximum OEM
// command with same command id as line 2270
{0x0D3D08EB,  CAT_KESSEL,           VT_TEMP,          2214,  STR2214,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 2214 Sollwert Handbetrieb [°C]
//{CMD_UNKNOWN, CAT_KESSEL,           VT_TEMP,          2214,  STR2214,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 2214 Sollwert Handbetrieb [°C]
{0x0D3D0932,  CAT_KESSEL,           VT_UINT,          2220,  STR2220,  0,                    NULL,         FL_OEM, DEV_ALL}, // Freigabeintegral Stufe 2 °Cmin[0-500]
{0x0D3D0933,  CAT_KESSEL,           VT_UINT,          2221,  STR2221,  0,                    NULL,         FL_OEM, DEV_ALL}, // Rückstellintegral Stufe 2 °Cmin[0-500]
{0x0D3D08BE,  CAT_KESSEL,           VT_SECONDS_SHORT, 2222,  STR2222,  0,                    NULL,         FL_OEM, DEV_ALL}, // Zwangseinschaltung Stufe 2
{0x113D08F6,  CAT_KESSEL,           VT_SECONDS_WORD5, 2232,  STR2232,  0,                    NULL,         FL_OEM, DEV_ALL}, // Klappenantrieb Laufzeit
{0x113D08F5,  CAT_KESSEL,           VT_TEMP,          2233,  STR2233,  0,                    NULL,         FL_OEM, DEV_ALL}, // Klappenantrieb P-Band Xp
{0x113D08F7,  CAT_KESSEL,           VT_SECONDS_WORD,  2234,  STR2234,  0,                    NULL,         FL_OEM, DEV_ALL}, // Klappenantrieb Nach'zeit Tn
{0x113D08F8,  CAT_KESSEL,           VT_SECONDS_SHORT4,2235,  STR2235,  0,                    NULL,         FL_OEM, DEV_ALL}, // Klappenantrieb Vorh'zeit Tv
{0x0D3D0928,  CAT_KESSEL,           VT_TEMP,          2240,  STR2240,  0,                    NULL,         FL_OEM, DEV_ALL}, // Schaltdifferenz Kessel
{0x0D3D0939,  CAT_KESSEL,           VT_MINUTES_SHORT, 2241,  STR2241,  0,                    NULL,         FL_OEM, DEV_ALL}, // Kessel Brennerlaufzeit Minimum
{0x053D0C02,  CAT_KESSEL,           VT_MINUTES_WORD,  2243,  STR2243,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Brennpausenzeit Minimum
{0x053D2F87,  CAT_KESSEL,           VT_TEMP,          2245,  STR2245,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // SD Brennerpause
{0x113D0BCC,  CAT_KESSEL,           VT_MINUTES_SHORT, 2250,  STR2250,  0,                    NULL,         FL_OEM, DEV_ALL}, // Pumpennachlaufzeit
{0x113D11A4,  CAT_KESSEL,           VT_MINUTES_SHORT, 2250,  STR2250,  0,                    NULL,         FL_OEM, DEV_123_ALL}, // [ min] Kessel - Pumpennachlaufzeit
{0x113D11A4,  CAT_KESSEL,           VT_MINUTES_SHORT, 2250,  STR2250,  0,                    NULL,         FL_OEM, DEV_162_ALL}, // [ min] Kessel - Pumpennachlaufzeit
{0x113D0F85,  CAT_KESSEL,           VT_MINUTES_SHORT, 2253,  STR2253,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpennachlaufzeit n. TWW-Betrieb
{0x053D08FE,  CAT_KESSEL,           VT_ONOFF,         2260,  STR2260,  0,                    NULL,         FL_OEM, DEV_ALL}, // Anfahrentlast Verbraucher
{0x113D093A,  CAT_KESSEL,           VT_ONOFF,         2261,  STR2261,  0,                    NULL,         FL_OEM, DEV_ALL}, // Anfahrentlast Kesselpumpe
{0x053D0437,  CAT_KESSEL,           VT_ONOFF,         2262,  STR2262,  0,                    NULL,         FL_OEM, DEV_ALL}, // Einschaltoptimierung
// command not present for THISION
{CMD_UNKNOWN, CAT_KESSEL,           VT_TEMP,          2270,  STR2270,  0,                    NULL,         DEFAULT_FLAG, DEV_097_ALL}, // [°C ] - Kessel - Rücklaufsollwert Minimum
{0x053D0908,  CAT_KESSEL,           VT_TEMP,          2270,  STR2270,  0,                    NULL,         DEFAULT_FLAG, DEV_096_ALL}, // [°C ] - Kessel - Rücklaufsollwert Minimum
{0x0D3D08EB,  CAT_KESSEL,           VT_TEMP,          2270,  STR2270,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Kessel - Rücklaufsollwert Minimum
{0x053D0549,  CAT_KESSEL,           VT_TEMP,          2271,  STR2271,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Kessel - Rücklaufsollwert Min OEM
{0x053D08FD,  CAT_KESSEL,           VT_ONOFF,         2272,  STR2272,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Kessel - Rückl'einfluss Verbraucher
{0x053D090C,  CAT_KESSEL,           VT_SECONDS_WORD,  2282,  STR2282,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Kessel - Antrieb Laufzeit
{0x053D090A,  CAT_KESSEL,           VT_TEMP,          2283,  STR2283,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Kessel - Mischer P-Band Xp
{CMD_UNKNOWN, CAT_KESSEL,           VT_UNKNOWN,       2284,  STR2284,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Kessel - Mischer Nachstellzeit
{CMD_UNKNOWN, CAT_KESSEL,           VT_UNKNOWN,       2285,  STR2285,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Kessel - Mischer Vorhaltezeit Tv
{0x113D0946,  CAT_KESSEL,           VT_TEMP,          2290,  STR2290,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Kessel - Schaltdiff Bypasspumpe
{0x113D0947,  CAT_KESSEL,           VT_ENUM,          2291,  STR2291,  sizeof(ENUM2291),     ENUM2291,     FL_OEM, DEV_ALL}, // Schaltdiff Bypasspumpe
{0x113D063C,  CAT_KESSEL,           VT_ONOFF,         2300,  STR2300,  0,                    NULL,         FL_OEM, DEV_ALL}, // Kessel - Anl'frostschutz Kess'pumpe (an/aus)
{0x053D1182,  CAT_KESSEL,           VT_ONOFF,         2301,  STR2301,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Kesselpumpe bei Erzeugersperre
{0x053D1258,  CAT_KESSEL,           VT_ENUM,          2305,  STR2305,  sizeof(ENUM2305),     ENUM2305,     DEFAULT_FLAG, DEV_ALL}, // Wirkung Erzeugersperre
{0x053D1258,  CAT_KESSEL,           VT_ENUM,          2305,  STR2305,  sizeof(ENUM2305_2),   ENUM2305_2,   DEFAULT_FLAG, DEV_123_ALL}, // [] Kessel - Wirkung Erzeugersperre
{CMD_UNKNOWN, CAT_KESSEL,           VT_ONOFF,         2310,  STR2310,  0,                    NULL,         FL_OEM, DEV_ALL}, // TR-Funktion
{CMD_UNKNOWN, CAT_KESSEL,           VT_UNKNOWN,       2315,  STR2315,  0,                    NULL,         FL_OEM, DEV_ALL}, // Temperaturhub Minimum
{0x113D0B60,  CAT_KESSEL,           VT_TEMP,          2316,  STR2316,  0,                    NULL,         FL_OEM, DEV_ALL}, // Temperaturhub maximum
{0x053D0F84,  CAT_KESSEL,           VT_TEMP,          2317,  STR2317,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Temperaturhub nenn
{0x053D10F7,  CAT_KESSEL,           VT_ENUM,          2320,  STR2320,  sizeof(ENUM2320),     ENUM2320,     FL_RONLY, DEV_ALL}, // Pumpenmodulation
{0x113D0AEF,  CAT_KESSEL,           VT_PERCENT,       2322,  STR2322,  0,                    NULL,         FL_OEM, DEV_ALL}, // Pumpendrehzahl minimum (%)
{0x053D1160,  CAT_KESSEL,           VT_PERCENT,       2322,  STR2322,  0,                    NULL,         FL_OEM, DEV_123_ALL}, // [%] Kessel - Pumpendrehzahl Minimum
{0x113D0AF0,  CAT_KESSEL,           VT_PERCENT,       2323,  STR2323,  0,                    NULL,         FL_OEM, DEV_ALL}, // Pumpendrehzahl maximum (%)
{0x053D1161,  CAT_KESSEL,           VT_PERCENT,       2323,  STR2323,  0,                    NULL,         FL_OEM, DEV_123_ALL}, // [%] Kessel - Pumpendrehzahl maximum
{CMD_UNKNOWN, CAT_KESSEL,           VT_UNKNOWN,       2324,  STR2324,  0,                    NULL,         FL_OEM, DEV_ALL}, // Drehzahl P-Band Xp
{CMD_UNKNOWN, CAT_KESSEL,           VT_UNKNOWN,       2325,  STR2325,  0,                    NULL,         FL_OEM, DEV_ALL}, // Drehzahl Nachstellzeit Tn
{CMD_UNKNOWN, CAT_KESSEL,           VT_UNKNOWN,       2326,  STR2326,  0,                    NULL,         FL_OEM, DEV_ALL}, // Drehzahl Vorhaltezeit Tv
{0x053D2EF0,  CAT_KESSEL,           VT_POWER_WORD,    2330,  STR2330,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Leistung Nenn
{0x053D2F70,  CAT_KESSEL,           VT_POWER_WORD,    2331,  STR2331,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Leistung Grundstufe
{0x053D10F4,  CAT_KESSEL,           VT_PERCENT_100,   2334,  STR2334,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Leistung bei Pumpendrehz. min
{0x053D10F5,  CAT_KESSEL,           VT_PERCENT_100,   2335,  STR2335,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Leistung bei Pumpendrehz. max
{CMD_UNKNOWN, CAT_KESSEL,           VT_UNKNOWN,       2340,  STR2340,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Auto Erz’folge 2 x 1 Kaskade

{0x093D2F98,  CAT_KESSEL,           VT_PERCENT,       2440,  STR2440,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 2440 Gebläse-PWM Hz Maximum [%]
{0x0D3D2F94,  CAT_KESSEL,           VT_SPEED,         2441,  STR2441,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Brötje 2441 Gebläsedrehzahl Hz Maximum
{0x093D120F,  CAT_KESSEL,           VT_POWER_WORD,    2441,  STR2441_2,0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Gebläseleistung Heizen Max
{0x093D120F,  CAT_KESSEL,           VT_POWER_WORD,    2441,  STR2441_2,0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Gebläseleistung Heizen Max
{0x093D120F,  CAT_KESSEL,           VT_POWER_WORD,    2441,  STR2441_2,0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Gebläseleistung Heizen Max
{0x093D120F,  CAT_KESSEL,           VT_POWER_WORD,    2441,  STR2441_2,0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Gebläseleistung Heizen Max
{0x193D2FBF,  CAT_KESSEL,           VT_PERCENT,       2442,  STR2442,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 2442 Gebläse-PWM Reglerverzögerung [%]
{0x093D1211,  CAT_KESSEL,           VT_POWER_WORD,    2442,  STR2442_2,0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Gebl'leistung Durchladen Max
{0x093D1211,  CAT_KESSEL,           VT_POWER_WORD,    2442,  STR2442_2,0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Gebl'leistung Durchladen Max
{0x093D1211,  CAT_KESSEL,           VT_POWER_WORD,    2442,  STR2442_2,0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Gebl'leistung Durchladen Max
{0x093D1211,  CAT_KESSEL,           VT_POWER_WORD,    2442,  STR2442_2,0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Gebl'leistung Durchladen Max
{0x2D3D2FD4,  CAT_KESSEL,           VT_PERCENT,       2443,  STR2443,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Brötje 2443 Gebläse-PWM Startwert DLH
{0x2E3D2FD4,  CAT_KESSEL,           VT_PERCENT,       2443,  STR2443,  0,                    NULL,         FL_RONLY, DEV_064_ALL}, // Brötje 2443 Gebläse-PWM Startwert DLH - logged on OCI700 via LPB
{0x093D1213,  CAT_KESSEL,           VT_POWER_WORD,    2443,  STR2443_2,0,                    NULL,         FL_RONLY, DEV_123_ALL}, // Gebl'leistung Startwert DLH
{0x093D1213,  CAT_KESSEL,           VT_POWER_WORD,    2443,  STR2443_2,0,                    NULL,         FL_RONLY, DEV_162_ALL}, // Gebl'leistung Startwert DLH
{0x093D1213,  CAT_KESSEL,           VT_POWER_WORD,    2443,  STR2443_2,0,                    NULL,         FL_RONLY, DEV_163_ALL}, // Gebl'leistung Startwert DLH
{0x093D1213,  CAT_KESSEL,           VT_POWER_WORD,    2443,  STR2443_2,0,                    NULL,         FL_RONLY, DEV_195_ALL}, // Gebl'leistung Startwert DLH
{0x093D2F99,  CAT_KESSEL,           VT_POWER_WORD,    2444,  STR2444,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 2444 Leistung Minimum [kW]
{0x093D1212,  CAT_KESSEL,           VT_POWER_WORD,    2444,  STR2444_2,0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Gebläseleistung TWW Max
{0x093D1212,  CAT_KESSEL,           VT_POWER_WORD,    2444,  STR2444_2,0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Gebläseleistung TWW Max
{0x093D1212,  CAT_KESSEL,           VT_POWER_WORD,    2444,  STR2444_2,0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Gebläseleistung TWW Max
{0x093D1212,  CAT_KESSEL,           VT_POWER_WORD,    2444,  STR2444_2,0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Gebläseleistung TWW Max
{0x093D3066,  CAT_KESSEL,           VT_POWER,         2445,  STR2445,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 2445 Leistung Nenn [kW]
{0x053D1123,  CAT_KESSEL,           VT_ONOFF,         2445,  STR2445_2,0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Gebl'abschaltung Heizbetrieb
{0x053D1123,  CAT_KESSEL,           VT_ONOFF,         2445,  STR2445_2,0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Gebl'abschaltung Heizbetrieb
{0x053D1123,  CAT_KESSEL,           VT_ONOFF,         2445,  STR2445_2,0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Gebl'abschaltung Heizbetrieb
{0x053D1123,  CAT_KESSEL,           VT_ONOFF,         2445,  STR2445_2,0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Gebl'abschaltung Heizbetrieb
{0x053D3076,  CAT_KESSEL,           VT_SECONDS_SHORT, 2446,  STR2446,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Brötje 2446 Gebläseabschaltverzögerung
{0x053D0F7E,  CAT_KESSEL,           VT_ENUM,          2450,  STR2450,  sizeof(ENUM2450),     ENUM2450,     DEFAULT_FLAG, DEV_ALL}, // Reglerverzögerung
{0x093D2F9A,  CAT_KESSEL,           VT_SECONDS_WORD,  2451,  STR2451,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 2451 Brennerpausenzeit Minimum [s]
{0x113D2F87,  CAT_KESSEL,           VT_TEMP_WORD,     2452,  STR2452,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Brötje 2452 SD Brennerpause
{0x113D2F87,  CAT_KESSEL,           VT_TEMP_WORD5_US, 2452,  STR2452,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Brötje 2452 SD Brennerpause - logged on OCI700 via LPB
{0x093D1210,  CAT_KESSEL,           VT_POWER_WORD,    2452,  STR2452_2,0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Reglerverzög' Gebl'leistung
{0x093D1210,  CAT_KESSEL,           VT_POWER_WORD,    2452,  STR2452_2,0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Reglerverzög' Gebl'leistung
{0x093D1210,  CAT_KESSEL,           VT_POWER_WORD,    2452,  STR2452_2,0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Reglerverzög' Gebl'leistung
{0x093D1210,  CAT_KESSEL,           VT_POWER_WORD,    2452,  STR2452_2,0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Reglerverzög' Gebl'leistung
{0x2D3D2F9B,  CAT_KESSEL,           VT_SECONDS_WORD,  2453,  STR2453,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Brötje 2453 Reglerverzögerung Dauer
{0x053D2F9B,  CAT_KESSEL,           VT_SECONDS_WORD,  2453,  STR2453,  0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Brötje 2453 Reglerverzögerung Dauer
{0x053D2F9B,  CAT_KESSEL,           VT_SECONDS_WORD,  2453,  STR2453,  0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Brötje 2453 Reglerverzögerung Dauer
{0x053D2F9B,  CAT_KESSEL,           VT_SECONDS_WORD,  2453,  STR2453,  0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Brötje 2453 Reglerverzögerung Dauer
{0x053D2F9B,  CAT_KESSEL,           VT_SECONDS_WORD,  2453,  STR2453,  0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Brötje 2453 Reglerverzögerung Dauer
{0x213D2F8C,  CAT_KESSEL,           VT_TEMP_SHORT5_US,2454,  STR2454,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Brötje 2454 Schaltdifferenz Kessel
{0x223D2F8C,  CAT_KESSEL,           VT_TEMP_SHORT5_US,2454,  STR2454,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Brötje 2454 Schaltdifferenz Kessel - logged on OCI700 via LPB
{0x113D0E08,  CAT_KESSEL,           VT_TEMP,          2454,  STR2454,  0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Brötje 2454 Schaltdifferenz Kessel
{0x113D0E08,  CAT_KESSEL,           VT_TEMP,          2454,  STR2454,  0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Brötje 2454 Schaltdifferenz Kessel
{0x113D0E08,  CAT_KESSEL,           VT_TEMP,          2454,  STR2454,  0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Brötje 2454 Schaltdifferenz Kessel
{0x113D0E08,  CAT_KESSEL,           VT_TEMP,          2454,  STR2454,  0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Brötje 2454 Schaltdifferenz Kessel
{0x213D2F8D,  CAT_KESSEL,           VT_TEMP_SHORT5_US,2455,  STR2455,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Brötje 2455 Schaltdiff Kessel Aus Min
{0x223D2F8D,  CAT_KESSEL,           VT_TEMP_SHORT5_US,2455,  STR2455,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Brötje 2455 Schaltdiff Kessel Aus Min - logged on OCI700 via LPB
{0x113D0E09,  CAT_KESSEL,           VT_TEMP,          2455,  STR2455,  0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Brötje 2455 Schaltdiff Kessel Aus Min
{0x113D0E09,  CAT_KESSEL,           VT_TEMP,          2455,  STR2455,  0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Brötje 2455 Schaltdiff Kessel Aus Min
{0x113D0E09,  CAT_KESSEL,           VT_TEMP,          2455,  STR2455,  0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Brötje 2455 Schaltdiff Kessel Aus Min
{0x113D0E09,  CAT_KESSEL,           VT_TEMP,          2455,  STR2455,  0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Brötje 2455 Schaltdiff Kessel Aus Min
{0x213D2F8E,  CAT_KESSEL,           VT_TEMP_SHORT5_US,2456,  STR2456,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Brötje 2456 Schaltdiff Kessel Aus Max
{0x223D2F8E,  CAT_KESSEL,           VT_TEMP_SHORT5_US,2456,  STR2456,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Brötje 2456 Schaltdiff Kessel Aus Max - logged on OCI700 via LPB
{0x113D0E0A,  CAT_KESSEL,           VT_TEMP,          2456,  STR2456,  0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Brötje 2456 Schaltdiff Kessel Aus Max
{0x113D0E0A,  CAT_KESSEL,           VT_TEMP,          2456,  STR2456,  0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Brötje 2456 Schaltdiff Kessel Aus Max
{0x113D0E0A,  CAT_KESSEL,           VT_TEMP,          2456,  STR2456,  0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Brötje 2456 Schaltdiff Kessel Aus Max
{0x113D0E0A,  CAT_KESSEL,           VT_TEMP,          2456,  STR2456,  0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Brötje 2456 Schaltdiff Kessel Aus Max
{0x0D3D2FBA,  CAT_KESSEL,           VT_SECONDS_SHORT, 2459,  STR2459,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 2459 Sperrzeit dynam Schaltdiff [s]
{0x113D0E05,  CAT_KESSEL,           VT_TEMP,          2460,  STR2460,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Schaltdiff Ein TWW
{0x113D0E06,  CAT_KESSEL,           VT_TEMP,          2461,  STR2461,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Schaltdiff Aus Min TWW
{0x113D0E07,  CAT_KESSEL,           VT_TEMP,          2462,  STR2462,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Schaltdiff Aus Max TWW
{0x053D17BC,  CAT_KESSEL,           VT_SECONDS_WORD,  2470,  STR2470,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [s] Kessel - Verz' Wärmeanfo Sonderbet
{0x113D3051,  CAT_KESSEL,           VT_MINUTES_SHORT, 2471,  STR2471,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 2471 Pumpennachlaufzeit HK's [min]
{0x113D0BCC,  CAT_KESSEL,           VT_MINUTES_WORD,  2471,  STR2471,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Thision 2471 Pumpennachlaufzeit HK's [min] - logged on OCI700 via LPB
{0x113D2F86,  CAT_KESSEL,           VT_TEMP,          2472,  STR2472,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Brötje 2472 Pumpennachlauftemp TWW
{0x113D2F86,  CAT_KESSEL,           VT_TEMP_WORD5_US, 2472,  STR2472,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Brötje 2472 Pumpennachlauftemp TWW - logged on OCI700 via LPB
{0x053D0FEB,  CAT_KESSEL,           VT_ENUM,          2480,  STR2480,  sizeof(ENUM2480),     ENUM2480,     DEFAULT_FLAG, DEV_ALL}, // [enum] Kessel - Statisch' Drucküberw Absch'
{0x053D0FE9,  CAT_KESSEL,           VT_ENUM,          2500,  STR2500,  sizeof(ENUM2500),     ENUM2500,     DEFAULT_FLAG, DEV_ALL}, // Druckschalter Abschaltung
{0x093D2F84,  CAT_KESSEL,           VT_TEMP_SHORT5_US,2521,  STR2521,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Brötje 2521 Frostschutz Einschalttemp
{0x093D2F85,  CAT_KESSEL,           VT_TEMP_SHORT5_US,2522,  STR2522,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Brötje 2522 Frostschutz Ausschalttemp
{0x113D2FA9,  CAT_KESSEL,           VT_PROPVAL,       2540,  STR2540,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 2540 Proportionalbeiwert Kp TWW [0..9.9375]
{0x113D2FAA,  CAT_KESSEL,           VT_PROPVAL,       2543,  STR2543,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 2543 Proportionalbeiwert Kp HK's [0..9.9375]
{0x053D1A79,  CAT_KESSEL,           VT_ONOFF,         2550,  STR2550,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [] - Kessel - Gasenergiezählung
{0x053D1A82,  CAT_KESSEL,           VT_SINT1000,      2551,  STR2551,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [] - Kessel - Gasenergiezähl Korrektur

//Sitherm Pro
{0x093D303A,  CAT_SITHERM,           VT_UINT,         2700,  STR2700,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Ergebnis letzter Drifttest
{0x093D0F31,  CAT_SITHERM,           VT_CURRENT,      2700,  STR2700_2,0,                    NULL,         FL_RONLY, DEV_123_ALL}, // Ion'strom gefiltert
{0x093D0F31,  CAT_SITHERM,           VT_CURRENT,      2700,  STR2700_2,0,                    NULL,         FL_RONLY, DEV_162_ALL}, // Ion'strom gefiltert
{0x093D301E,  CAT_SITHERM,           VT_YESNO,        2702,  STR2702,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Auslösen neuer Drifttest Ja/Nein
{0x053D3042,  CAT_SITHERM,           VT_SINT,         2702,  STR2702_2,0,                    NULL,         FL_RONLY, DEV_123_ALL}, // Position Schrittmotor // todo VT_SINT verifizieren
{0x053D3042,  CAT_SITHERM,           VT_SINT,         2702,  STR2702_2,0,                    NULL,         FL_RONLY, DEV_162_ALL}, // Position Schrittmotor // todo VT_SINT verifizieren
{0x093D301F,  CAT_SITHERM,           VT_YESNO,        2703,  STR2703,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Reset Drifttest Ja/Nein
{0x053D3043,  CAT_SITHERM,           VT_SINT,         2703,  STR2703_2,0,                    NULL,         FL_RONLY, DEV_123_ALL}, // Lernwert Gasqualität  // todo VT_SINT verifizieren
{0x053D3043,  CAT_SITHERM,           VT_SINT,         2703,  STR2703_2,0,                    NULL,         FL_RONLY, DEV_162_ALL}, // Lernwert Gasqualität  // todo VT_SINT verifizieren
{0x093D303B,  CAT_SITHERM,           VT_SINT,         2704,  STR2704,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Untergrenze Drifttest Störung
{0x093D303C,  CAT_SITHERM,           VT_SINT,         2705,  STR2705,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Obergrenze Drifttest Störung
{0x093D0F26,  CAT_SITHERM,           VT_SINT,         2705,  STR2705_2,0,                    NULL,         FL_RONLY, DEV_123_ALL}, // R-Wert
{0x093D0F26,  CAT_SITHERM,           VT_SINT,         2705,  STR2705_2,0,                    NULL,         FL_RONLY, DEV_162_ALL}, // R-Wert
{0x093D0F62,  CAT_SITHERM,           VT_ENUM,         2706,  STR2706,  sizeof(ENUM2706),     ENUM2706,     FL_RONLY, DEV_ALL},     // Betriebsphase
{0x053D3020,  CAT_SITHERM,           VT_ONOFF,        2720,  STR2720,  0,                    NULL,         FL_RONLY, DEV_ALL},     // Freigabe Einstellung Gasart
{0x053D3041,  CAT_SITHERM,           VT_ENUM,         2721,  STR2721,  sizeof(ENUM2721),     ENUM2721,     FL_RONLY, DEV_ALL},     // Gasart
{0x093D3077,  CAT_SITHERM,           VT_ENUM,         2727,  STR2727,  sizeof(ENUM2727),     ENUM2727,     DEFAULT_FLAG, DEV_ALL}, // Zünd und Überwach'bereich
{0x153D2FF0,  CAT_SITHERM,           VT_CURRENT,      2730,  STR2730,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Ionisationsstrom uA -> Gleiche ID wie STR8329
{0x153D2FF0,  CAT_SITHERM,           VT_CURRENT,      2730,  STR2730,  0,                    NULL,         FL_NO_CMD, DEV_097_ALL}, // No command
{0x153D2FF0,  CAT_SITHERM,           VT_CURRENT,      2730,  STR2730,  0,                    NULL,         FL_NO_CMD, DEV_123_ALL}, //No command
{0x093D3042,  CAT_SITHERM,           VT_UINT,         2731,  STR2731,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Position Schrittmotor
{0x093D3043,  CAT_SITHERM,           VT_SINT,         2732,  STR2732,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Lernwert Gasqualität
{0x093D1A10,  CAT_SITHERM,           VT_ENUM,         2740,  STR2702,  sizeof(ENUM2740),     ENUM2740,     DEFAULT_FLAG, DEV_ALL}, // Auslösen Drifttest
{0x093D1A11,  CAT_SITHERM,           VT_BYTE,         2741,  STR2741,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // ADA Punkt Nr
{0x093D1A13,  CAT_SITHERM,           VT_CURRENT,      2742,  STR2742,  0,                    NULL,         FL_RONLY, DEV_ALL}, // ADA Filterwert
{0x093D1A14,  CAT_SITHERM,           VT_CURRENT,      2743,  STR2743,  0,                    NULL,         FL_RONLY, DEV_ALL}, // ADA Korrektur
{0x093D1A15,  CAT_SITHERM,           VT_UINT100,      2744,  STR2744,  0,                    NULL,         FL_RONLY, DEV_ALL}, // ADA vergangene Zeit
{0x093D1A12,  CAT_SITHERM,           VT_CURRENT,      2745,  STR2745,  0,                    NULL,         FL_RONLY, DEV_ALL}, // ADA Ergebnis // todo dies ist eigentlich Teil 2 von Parameter 2741. 2741 legt den ADA Punkt fest (1...7), dessen Wert dann unter dieser 0xID abgefragt werden kann.
{0x093D1A16,  CAT_SITHERM,           VT_ENUM,         2749,  STR2749,  sizeof(ENUM2749),     ENUM2749,     DEFAULT_FLAG, DEV_ALL}, // Reset Drifttest
{0x093D0F63,  CAT_SITHERM,           VT_BYTE,         2750,  STR2750,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Anstehende Drifttests
{0x093D1A17,  CAT_SITHERM,           VT_HOURS_WORD,   2751,  STR2751,  0,                    NULL,         FL_RONLY, DEV_ALL}, // ADA Zeitintervall 1
{0x093D1A18,  CAT_SITHERM,           VT_HOURS_WORD,   2752,  STR2752,  0,                    NULL,         FL_RONLY, DEV_ALL}, // ADA Zeitintervall 2
{0x093D1A19,  CAT_SITHERM,           VT_HOURS_WORD,   2753,  STR2753,  0,                    NULL,         FL_RONLY, DEV_ALL}, // ADA Zeitintervall 3

// Wärmepumpe
//OEM
{0x593D186C,  CAT_WAERMEPUMPE,      VT_TEMP,          2785,  STR2785,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Max Kondensationstemp
{0x593D186E,  CAT_WAERMEPUMPE,      VT_TEMP,          2786,  STR2786,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Max Kondensationstemp SD
{0x593D186D,  CAT_WAERMEPUMPE,      VT_TEMP,          2787,  STR2787,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Max Kondens'temp Reduktion
//end OEM
{0x593D1788,  CAT_WAERMEPUMPE,      VT_ONOFF,         2789,  STR2789,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Kondensatorpumpe bei TWW
{0x593D1676,  CAT_WAERMEPUMPE,      VT_TEMP_SHORT,    2790,  STR2790,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Modulation Kondensatorpumpe // Temp'Spreizung Kondensator
{0x593D1675,  CAT_WAERMEPUMPE,      VT_PERCENT,       2792,  STR2792,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendrehzahl Minimum
{0x593D1674,  CAT_WAERMEPUMPE,      VT_PERCENT,       2793,  STR2793,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendrehzahl Maximum
//OEM
{0x593D166C,  CAT_WAERMEPUMPE,      VT_TEMP,          2794,  STR2794,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Drehzahl P-Band Xp
{0x593D166B,  CAT_WAERMEPUMPE,      VT_SECONDS_WORD,  2795,  STR2795,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Drehzahl Nachstellzeit Tn
//end OEM
{0x593D05CC,  CAT_WAERMEPUMPE,      VT_ONOFF,         2800,  STR2800,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Frostschutz Kondens’pumpe
{0x593D05CD,  CAT_WAERMEPUMPE,      VT_DWORD,         2801,  STR2801,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Steuerung Kondens’pumpe // Temperaturanforderung
{0x593D18A0,  CAT_WAERMEPUMPE,      VT_SECONDS_WORD,  2802,  STR2802,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Vorlaufzeit Kondens’pumpe
{0x593D18A1,  CAT_WAERMEPUMPE,      VT_SECONDS_WORD,  2803,  STR2803,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Nachlaufzeit Kondens’pumpe
{0x593D05CB,  CAT_WAERMEPUMPE,      VT_SECONDS_SHORT, 2803,  STR2803,  0,                    NULL,         DEFAULT_FLAG, DEV_119_ALL}, // Nachlaufzeit Kondens’pumpe //FUJITSU
{0x593D05CB,  CAT_WAERMEPUMPE,      VT_SECONDS_SHORT, 2803,  STR2803,  0,                    NULL,         DEFAULT_FLAG, DEV_170_ALL}, // Nachlaufzeit Kondens’pumpe //FUJITSU
{0x593D05BD,  CAT_WAERMEPUMPE,      VT_TEMP,          2805,  STR2805,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Soll Temp’Spreizung Kondens
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2806,  STR2806,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Max Abweich Spreiz Kondens
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_TEMP,          2815,  STR2815,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Quellentemp Min Wasser
{0x593D05AE,  CAT_WAERMEPUMPE,      VT_TEMP,          2816,  STR2816,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Quellentemp Min Sole
{0x593D05BC,  CAT_WAERMEPUMPE,      VT_TEMP,          2817,  STR2817,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Schaltdiff Quellenschutz
{0x593D05AF,  CAT_WAERMEPUMPE,      VT_TEMP,          2818,  STR2818,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Erhöhung Quellenschutztemp Min Estrich
{0x593D18A2,  CAT_WAERMEPUMPE,      VT_SECONDS_WORD,  2819,  STR2819,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Vorlaufzeit Quelle
{0x593D18A3,  CAT_WAERMEPUMPE,      VT_SECONDS_WORD,  2820,  STR2820,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Nachlaufzeit Quelle
{0x593D05B4,  CAT_WAERMEPUMPE,      VT_MINUTES_WORD,  2821,  STR2821,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Quellen-Anlaufzeit Maximum
{0x593D05B5,  CAT_WAERMEPUMPE,      VT_HOURS_WORD,    2822,  STR2822,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeit Begr Quelletemp Min Sole
{0x593D17B6,  CAT_WAERMEPUMPE,      VT_MINUTES_WORD,  2827,  STR2827,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeit Begr Quelletemp
{0x593D178C,  CAT_WAERMEPUMPE,      VT_SECONDS_WORD,  2839,  STR2839,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeit Begr Quelletemp
{0x593D05C1,  CAT_WAERMEPUMPE,      VT_TEMP,          2840,  STR2840,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Schaltdiff Rücklauftemp
{0x593D0B8B,  CAT_WAERMEPUMPE,      VT_YESNO,         2841,  STR2841,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Verd'laufzeit min einhalten
{0x593D04F1,  CAT_WAERMEPUMPE,      VT_MINUTES_SHORT, 2842,  STR2842,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Verdichterlaufzeit Minimum
{0x593D04F2,  CAT_WAERMEPUMPE,      VT_MINUTES_SHORT, 2843,  STR2843,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Verdichtersillstandszeit Min //FUJITSU
{0x593D05CF,  CAT_WAERMEPUMPE,      VT_TEMP,          2844,  STR2844,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Ausschalttemp. max //FUJITSU
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2845,  STR2845,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Reduktion Ausschaltemp Max
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2846,  STR2846,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Heissgastemp Max
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2852,  STR2852,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // ND-Verzögerung beim Start
{0x593D0495,  CAT_WAERMEPUMPE,      VT_MINUTES_SHORT, 2862,  STR2862,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sperrzeit Stufe/Mod //FUJITSU
{0x593D0BA2,  CAT_WAERMEPUMPE,      VT_PERCENT,       2870,  STR2870,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Verdichtungsmodulation Max.
{0x593D0BA3,  CAT_WAERMEPUMPE,      VT_PERCENT,       2871,  STR2871,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Verdichtungsmodulation Min.
{0x593D14B4,  CAT_WAERMEPUMPE,      VT_SECONDS_WORD,  2873,  STR2873,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Verdichtermod Laufzeit //FUJITSU
{0x593D0BB5,  CAT_WAERMEPUMPE,      VT_SECONDS_SHORT, 2873,  STR2873,  0,                    NULL,         DEFAULT_FLAG, DEV_119_ALL}, // Verdichtermod Laufzeit
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2880,  STR2880,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Verwendung Elektro-Vorlauf
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2881,  STR2881,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sperrzeit Elektro-Vorlauf
{0x053D0D02,  CAT_WAERMEPUMPE,      VT_UINT,          2882,  STR2882,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Freigabeintegr. Elektro-Vorl °Cmin[0-500] //FUJITSU
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2883,  STR2883,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Rückstellintegr. Elektro-Vorl
{0x593D0D2E,  CAT_WAERMEPUMPE,      VT_TEMP,          2884,  STR2884,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Freig Elektro-Vorl unter TA //FUJITSU
{0x593D0436,  CAT_WAERMEPUMPE,      VT_ONOFF,         2886,  STR2886,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Kompensation Wärmedefizit //FUJITSU
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2893,  STR2893,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Anzahl TWW-Ladeversuche
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2894,  STR2894,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Verzögerung Drehstr'fehler
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2895,  STR2895,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Verzögerung Ström'wächter
{0x593D0CEA,  CAT_WAERMEPUMPE,      VT_TEMP,          2910,  STR2910,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Freigabe oberhalb TA
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2911,  STR2911,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Für Pufferzwangsladung
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2912,  STR2912,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Durchladung Pufferspeicher
{0x593D12F3,  CAT_WAERMEPUMPE,      VT_TEMP,          2916,  STR2916,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sollwert WP Max TWW //FUJITSU
{0x593D0DF3,  CAT_WAERMEPUMPE,      VT_ENUM,          2920,  STR2920,  sizeof(ENUM2920),     ENUM2920,     DEFAULT_FLAG, DEV_ALL}, // Bei EW Sperre //FUJITSU
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2951,  STR2951,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abtaufreigabe unterhalb TA
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2952,  STR2952,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Schaltdifferenz Abtauen
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2954,  STR2954,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Verdampfertemp Abtau-Ende
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2963,  STR2963,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Dauer bis Zwangsabtauen
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2964,  STR2964,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abtaudauer Maximal
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2965,  STR2965,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abtropfdauer Verdampfer
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       2966,  STR2966,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abkühldauer Verdampfer
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       3002,  STR3002,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Quellentemp min Kühlbetrieb
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       3006,  STR3006,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Während Verdichterbetrieb
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       3007,  STR3007,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Im passiven Kühlbetrieb
{CMD_UNKNOWN, CAT_WAERMEPUMPE,      VT_UNKNOWN,       3010,  STR3010,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Drehz max V'lator/Q'Pump

// Energiezähler (Fujitsu Waterstage)
{0x053D12B7,  CAT_ENERGIEZAEHLER,   VT_ENUM,          3095,  STR3095,  sizeof(ENUM3095),     ENUM3095,     DEFAULT_FLAG, DEV_ALL}, // Durchflussmessung Wärme
{0x053D108C,  CAT_ENERGIEZAEHLER,   VT_LITERPERHOUR,  3097,  STR3097,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Durchfluss Heizen
{0x053D108D,  CAT_ENERGIEZAEHLER,   VT_LITERPERHOUR,  3098,  STR3098,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Durchfluss Trinkwasser
{0x053D108E,  CAT_ENERGIEZAEHLER,   VT_ENUM,          3100,  STR3100,  sizeof(ENUM3100),     ENUM3100,     DEFAULT_FLAG, DEV_ALL}, // Impulszählung Energie
{0x053D108F,  CAT_ENERGIEZAEHLER,   VT_ENUM,          3102,  STR3102,  sizeof(ENUM3102),     ENUM3102,     DEFAULT_FLAG, DEV_ALL}, // Impulseinheit Energie
{0x053D1090,  CAT_ENERGIEZAEHLER,   VT_UINT,          3103,  STR3103,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Impulswert Energie Zähler
{0x053D1091,  CAT_ENERGIEZAEHLER,   VT_UINT,          3104,  STR3104,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Impulswert Energie Nenner
{0x053D12B8,  CAT_ENERGIEZAEHLER,   VT_ENUM,          3109,  STR3109,  sizeof(ENUM3109),     ENUM3109,     DEFAULT_FLAG, DEV_ALL}, // Zählung Intern Elektro Vorl’
{0x053D10B3,  CAT_ENERGIEZAEHLER,   VT_STRING,        3110,  STR3110,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegebene Wärme
{0x053D10B4,  CAT_ENERGIEZAEHLER,   VT_STRING,        3113,  STR3113,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Eingesetzte Energie
{0x053D1721,  CAT_ENERGIEZAEHLER,   VT_STRING,        3121,  STR3121,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme Heizen 1
{0x053D172B,  CAT_ENERGIEZAEHLER,   VT_STRING,        3122,  STR3122,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme TWW 1
{0x053D1983,  CAT_ENERGIEZAEHLER,   VT_STRING,        3123,  STR3123,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Kälte 1
{0x053D1735,  CAT_ENERGIEZAEHLER,   VT_STRING,        3124,  STR3124,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Heizen 1
{0x053D173F,  CAT_ENERGIEZAEHLER,   VT_STRING,        3125,  STR3125,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie TWW 1
{0x053D198D,  CAT_ENERGIEZAEHLER,   VT_STRING,        3126,  STR3126,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Kühlen 1
{0x053D1722,  CAT_ENERGIEZAEHLER,   VT_STRING,        3128,  STR3128,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme Heizen 2
{0x053D172C,  CAT_ENERGIEZAEHLER,   VT_STRING,        3129,  STR3129,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme TWW 2
{0x053D1984,  CAT_ENERGIEZAEHLER,   VT_STRING,        3130,  STR3130,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Kälte 2
{0x053D1736,  CAT_ENERGIEZAEHLER,   VT_STRING,        3131,  STR3131,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Heizen 2
{0x053D1740,  CAT_ENERGIEZAEHLER,   VT_STRING,        3132,  STR3132,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie TWW 2
{0x053D198E,  CAT_ENERGIEZAEHLER,   VT_STRING,        3133,  STR3133,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Kühlen 2
{0x053D1723,  CAT_ENERGIEZAEHLER,   VT_STRING,        3135,  STR3135,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme Heizen 3
{0x053D172D,  CAT_ENERGIEZAEHLER,   VT_STRING,        3136,  STR3136,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme TWW 3
{0x053D1985,  CAT_ENERGIEZAEHLER,   VT_STRING,        3137,  STR3137,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Kälte 3
{0x053D1737,  CAT_ENERGIEZAEHLER,   VT_STRING,        3138,  STR3138,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Heizen 3
{0x053D1741,  CAT_ENERGIEZAEHLER,   VT_STRING,        3139,  STR3139,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie TWW 3
{0x053D198F,  CAT_ENERGIEZAEHLER,   VT_STRING,        3140,  STR3140,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Kühlen 3
{0x053D1724,  CAT_ENERGIEZAEHLER,   VT_STRING,        3142,  STR3142,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme Heizen 4
{0x053D172E,  CAT_ENERGIEZAEHLER,   VT_STRING,        3143,  STR3143,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme TWW 4
{0x053D1986,  CAT_ENERGIEZAEHLER,   VT_STRING,        3144,  STR3144,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Kälte 4
{0x053D1738,  CAT_ENERGIEZAEHLER,   VT_STRING,        3145,  STR3145,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Heizen 4
{0x053D1742,  CAT_ENERGIEZAEHLER,   VT_STRING,        3146,  STR3146,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie TWW 4
{0x053D1990,  CAT_ENERGIEZAEHLER,   VT_STRING,        3147,  STR3147,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Kühlen 4
{0x053D1725,  CAT_ENERGIEZAEHLER,   VT_STRING,        3149,  STR3149,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme Heizen 5
{0x053D172F,  CAT_ENERGIEZAEHLER,   VT_STRING,        3150,  STR3150,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme TWW 5
{0x053D1987,  CAT_ENERGIEZAEHLER,   VT_STRING,        3151,  STR3151,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Kälte 5
{0x053D1739,  CAT_ENERGIEZAEHLER,   VT_STRING,        3152,  STR3152,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Heizen 5
{0x053D1743,  CAT_ENERGIEZAEHLER,   VT_STRING,        3153,  STR3153,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie TWW 5
{0x053D1991,  CAT_ENERGIEZAEHLER,   VT_STRING,        3154,  STR3154,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Kühlen 5
{0x053D1726,  CAT_ENERGIEZAEHLER,   VT_STRING,        3156,  STR3156,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme Heizen 6
{0x053D1730,  CAT_ENERGIEZAEHLER,   VT_STRING,        3157,  STR3157,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme TWW 6
{0x053D1988,  CAT_ENERGIEZAEHLER,   VT_STRING,        3158,  STR3158,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Kälte 6
{0x053D173A,  CAT_ENERGIEZAEHLER,   VT_STRING,        3159,  STR3159,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Heizen 6
{0x053D1744,  CAT_ENERGIEZAEHLER,   VT_STRING,        3160,  STR3160,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie TWW 6
{0x053D1992,  CAT_ENERGIEZAEHLER,   VT_STRING,        3161,  STR3161,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Kühlen 6
{0x053D1727,  CAT_ENERGIEZAEHLER,   VT_STRING,        3163,  STR3163,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme Heizen 7
{0x053D1731,  CAT_ENERGIEZAEHLER,   VT_STRING,        3164,  STR3164,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme TWW 7
{0x053D1989,  CAT_ENERGIEZAEHLER,   VT_STRING,        3165,  STR3165,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Kälte 7
{0x053D173B,  CAT_ENERGIEZAEHLER,   VT_STRING,        3166,  STR3166,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Heizen 7
{0x053D1745,  CAT_ENERGIEZAEHLER,   VT_STRING,        3167,  STR3167,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie TWW 7
{0x053D1993,  CAT_ENERGIEZAEHLER,   VT_STRING,        3168,  STR3168,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Kühlen 7
{0x053D1728,  CAT_ENERGIEZAEHLER,   VT_STRING,        3170,  STR3170,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme Heizen 8
{0x053D1732,  CAT_ENERGIEZAEHLER,   VT_STRING,        3171,  STR3171,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme TWW 8
{0x053D198A,  CAT_ENERGIEZAEHLER,   VT_STRING,        3172,  STR3172,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Kälte 8
{0x053D173C,  CAT_ENERGIEZAEHLER,   VT_STRING,        3173,  STR3173,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Heizen 8
{0x053D1746,  CAT_ENERGIEZAEHLER,   VT_STRING,        3174,  STR3174,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie TWW 8
{0x053D1994,  CAT_ENERGIEZAEHLER,   VT_STRING,        3175,  STR3175,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Kühlen 8
{0x053D1729,  CAT_ENERGIEZAEHLER,   VT_STRING,        3177,  STR3177,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme Heizen 9
{0x053D1733,  CAT_ENERGIEZAEHLER,   VT_STRING,        3178,  STR3178,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme TWW 9
{0x053D198B,  CAT_ENERGIEZAEHLER,   VT_STRING,        3179,  STR3179,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Kälte 9
{0x053D173D,  CAT_ENERGIEZAEHLER,   VT_STRING,        3180,  STR3180,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Heizen 9
{0x053D1747,  CAT_ENERGIEZAEHLER,   VT_STRING,        3181,  STR3181,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie TWW 9
{0x053D1995,  CAT_ENERGIEZAEHLER,   VT_STRING,        3182,  STR3182,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Kühlen 9
{0x053D172A,  CAT_ENERGIEZAEHLER,   VT_STRING,        3184,  STR3184,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme Heizen 10
{0x053D1734,  CAT_ENERGIEZAEHLER,   VT_STRING,        3185,  STR3185,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Wärme TWW 10
{0x053D198C,  CAT_ENERGIEZAEHLER,   VT_STRING,        3186,  STR3186,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgegeb’ Kälte 10
{0x053D173E,  CAT_ENERGIEZAEHLER,   VT_STRING,        3187,  STR3187,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Heizen 10
{0x053D1748,  CAT_ENERGIEZAEHLER,   VT_STRING,        3188,  STR3188,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie TWW 10
{0x053D1996,  CAT_ENERGIEZAEHLER,   VT_STRING,        3189,  STR3189,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einges’ Energie Kühlen 10
{0x053D1087,  CAT_ENERGIEZAEHLER,   VT_YESNO,         3190,  STR3190,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Reset Stichtagspeicher
{0x053D19BA,  CAT_ENERGIEZAEHLER,   VT_UNKNOWN,       3264,  STR3264,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Energiepreis HT
{0x053D19BB,  CAT_ENERGIEZAEHLER,   VT_UNKNOWN,       3265,  STR3265,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Energiepreis NT/SG-Wunsch
{0x053D19BC,  CAT_ENERGIEZAEHLER,   VT_UNKNOWN,       3266,  STR3266,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Energiepreis SG-Zwang
{0x053D19BD,  CAT_ENERGIEZAEHLER,   VT_UNKNOWN,       3267,  STR3267,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Energiepreis Alternativ Erz";

// Kaskade
{CMD_UNKNOWN, CAT_KASKADE,          VT_ENUM,          3510,  STR3510,  sizeof(ENUM3510),     ENUM3510,     FL_OEM, DEV_ALL}, // Führungsstrategie
{0x153D0843,  CAT_KASKADE,          VT_PERCENT,       3511,  STR3511,  0,                    NULL,         FL_OEM, DEV_ALL}, // Leistungsband Minimum
{0x153D0844,  CAT_KASKADE,          VT_PERCENT,       3512,  STR3512,  0,                    NULL,         FL_OEM, DEV_ALL}, // Leistungsband Maximum
{CMD_UNKNOWN, CAT_KASKADE,          VT_UNKNOWN,       3530,  STR3530,  0,                    NULL,         FL_OEM, DEV_ALL}, // Freigabeintegral Erz’folge
{CMD_UNKNOWN, CAT_KASKADE,          VT_UNKNOWN,       3531,  STR3531,  0,                    NULL,         FL_OEM, DEV_ALL}, // Rückstellintegral Erz’folge
{CMD_UNKNOWN, CAT_KASKADE,          VT_UNKNOWN,       3532,  STR3532,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Wiedereinschaltsperre
{CMD_UNKNOWN, CAT_KASKADE,          VT_UNKNOWN,       3533,  STR3533,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Zuschaltverzögerung
{CMD_UNKNOWN, CAT_KASKADE,          VT_UNKNOWN,       3534,  STR3534,  0,                    NULL,         FL_OEM, DEV_ALL}, // Zwangszeit Grundstufe
{CMD_UNKNOWN, CAT_KASKADE,          VT_UNKNOWN,       3540,  STR3540,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Auto Erz’folge Umschaltung
{CMD_UNKNOWN, CAT_KASKADE,          VT_ENUM,          3541,  STR3541,  sizeof(ENUM3541),     ENUM3541,     DEFAULT_FLAG, DEV_ALL}, // Auto Erz’folge Ausgrenzung
{CMD_UNKNOWN, CAT_KASKADE,          VT_ENUM,          3544,  STR3544,  sizeof(ENUM3544),     ENUM3544,     DEFAULT_FLAG, DEV_ALL}, // Führender Erzeuger
{CMD_UNKNOWN, CAT_KASKADE,          VT_ONOFF,         3550,  STR3550,  0,                    NULL,         FL_OEM, DEV_ALL}, // Anfahrentlast Kaskad'pumpe
{0x153D0B3A,  CAT_KASKADE,          VT_TEMP,          3560,  STR3560,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Rücklaufsollwert Minimum
{0x153D0B3B,  CAT_KASKADE,          VT_TEMP,          3561,  STR3561,  0,                    NULL,         FL_OEM, DEV_ALL}, // Rücklaufsollwert Min OEM
{CMD_UNKNOWN, CAT_KASKADE,          VT_UNKNOWN,       3562,  STR3562,  0,                    NULL,         FL_OEM, DEV_ALL}, // Rückl'einfluss Verbraucher
{CMD_UNKNOWN, CAT_KASKADE,          VT_UNKNOWN,       3570,  STR3570,  0,                    NULL,         FL_OEM, DEV_ALL}, // Antrieb Laufzeit
{CMD_UNKNOWN, CAT_KASKADE,          VT_UNKNOWN,       3571,  STR3571,  0,                    NULL,         FL_OEM, DEV_ALL}, // Mischer P-Band Xp
{CMD_UNKNOWN, CAT_KASKADE,          VT_UNKNOWN,       3572,  STR3572,  0,                    NULL,         FL_OEM, DEV_ALL}, // Mischer Nachstellzeit Tn
{CMD_UNKNOWN, CAT_KASKADE,          VT_UNKNOWN,       3590,  STR3590,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Temp’spreizung Minimum

// Zusatzerzeuger
{CMD_UNKNOWN, CAT_ZUSATZERZEUGER,   VT_UNKNOWN,       3700,  STR3700,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Freigabe unter Außentemp
{CMD_UNKNOWN, CAT_ZUSATZERZEUGER,   VT_UNKNOWN,       3701,  STR3701,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Freigabe über Außentemp
{CMD_UNKNOWN, CAT_ZUSATZERZEUGER,   VT_UNKNOWN,       3705,  STR3705,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Nachlaufzeit
{CMD_UNKNOWN, CAT_ZUSATZERZEUGER,   VT_UNKNOWN,       3720,  STR3720,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Schaltintegral
{CMD_UNKNOWN, CAT_ZUSATZERZEUGER,   VT_UNKNOWN,       3722,  STR3722,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Schaltdifferenz Aus
{CMD_UNKNOWN, CAT_ZUSATZERZEUGER,   VT_UNKNOWN,       3723,  STR3723,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sperrzeit

// Solar
{0x493D085D,  CAT_SOLAR,            VT_TEMP,          3810,  STR3810,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Solar (nur wenn aktiviert) - Temperaturdifferenz Ein
{0x193D085D,  CAT_SOLAR,            VT_TEMP_SHORT5_US,3810,  STR3810,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [°C ] - Solar (nur wenn aktiviert) - Temperaturdifferenz Ein - logged on OCI700 via LPB
{0x493D085C,  CAT_SOLAR,            VT_TEMP,          3811,  STR3811,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Solar (nur wenn aktiviert) - Temperaturdifferenz Aus
{0x313D085C,  CAT_SOLAR,            VT_TEMP_SHORT5_US,3811,  STR3811,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [°C ] - Solar (nur wenn aktiviert) - Temperaturdifferenz Aus - logged on OCI700 via LPB
{0x493D085A,  CAT_SOLAR,            VT_TEMP,          3812,  STR3812,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Solar (nur wenn aktiviert) - Ladetemp Min TWW-Speicher
{0x253D085A,  CAT_SOLAR,            VT_TEMP,          3812,  STR3812,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [°C ] - Solar (nur wenn aktiviert) - Ladetemp Min TWW-Speicher - logged on OCI700 via LPB
{0x493D0ADC,  CAT_SOLAR,            VT_TEMP,          3813,  STR3813,  0,                    NULL,         FL_OEM, DEV_ALL}, // Temp’diff EIN Puffer
{0x493D0ADD,  CAT_SOLAR,            VT_TEMP,          3814,  STR3814,  0,                    NULL,         FL_OEM, DEV_ALL}, // Temp’diff AUS Puffer
{0x493D0A07,  CAT_SOLAR,            VT_TEMP,          3815,  STR3815,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Solar (nur wenn aktiviert) - Ladetemp Min Puffer
{0x493D0ADE,  CAT_SOLAR,            VT_TEMP,          3816,  STR3816,  0,                    NULL,         FL_OEM, DEV_ALL}, // Temp'differenz EIN Sch'bad
{0x493D0ADF,  CAT_SOLAR,            VT_TEMP,          3817,  STR3817,  0,                    NULL,         FL_OEM, DEV_ALL}, // Temp'differenz AUS Sch'bad
{0x493D0AE7,  CAT_SOLAR,            VT_TEMP,          3818,  STR3818,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Ladetemp Min Schwimmbad
{0x493D0AE3,  CAT_SOLAR,            VT_ENUM,          3822,  STR3822,  sizeof(ENUM3822),     ENUM3822,     DEFAULT_FLAG, DEV_ALL}, // Ladevorrang Speicher
{0x493D0AE0,  CAT_SOLAR,            VT_MINUTES_SHORT, 3825,  STR3825,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Ladezeit relativer Vorrang
{0x493D0AE1,  CAT_SOLAR,            VT_MINUTES_SHORT, 3826,  STR3826,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Wartezeit relativer Vorrang
{0x493D0AE2,  CAT_SOLAR,            VT_MINUTES_SHORT, 3827,  STR3827,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Wartezeit Parallelbetrieb
{0x493D0AEE,  CAT_SOLAR,            VT_SECONDS_WORD,  3828,  STR3828,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Verzögerung Sekundärpumpe
{0x493D0716,  CAT_SOLAR,            VT_MINUTES_SHORT, 3830,  STR3830,  0,                    NULL,         FL_OEM, DEV_ALL}, // [min ] - Solar (nur wenn aktiviert) - Kollektorstartfunktion
{0x493D0719,  CAT_SOLAR,            VT_SECONDS_SHORT, 3831,  STR3831,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ sec ] - Solar (nur wenn aktiviert) - Mindestlaufzeit Kollek`pumpe
{0x22053015,  CAT_SOLAR,            VT_SECONDS_SHORT, 3831,  STR3831,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [ sec ] - Solar (nur wenn aktiviert) - Mindestlaufzeit Kollek`pumpe - logged on OCI700 via LPB
{0x493D0AE4,  CAT_SOLAR,            VT_HOUR_MINUTES,  3832,  STR3832,  0,                    NULL,         FL_OEM, DEV_ALL}, // Kollektorstartfunktion Ein
{0x493D0AE5,  CAT_SOLAR,            VT_HOUR_MINUTES,  3833,  STR3833,  0,                    NULL,         FL_OEM, DEV_ALL}, // Kollektorstartfunktion Aus
{0x493D0B12,  CAT_SOLAR,            VT_GRADIENT_SHORT,3834,  STR3834,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Kollektorstartfkt Gradient
{0x493D0860,  CAT_SOLAR,            VT_TEMP,          3840,  STR3840,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Solar (nur wenn aktiviert) - Kollektor Frostschutz
{0x0D3D0860,  CAT_SOLAR,            VT_TEMP,          3840,  STR3840,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [°C ] - Solar (nur wenn aktiviert) - Kollektor Frostschutz - logged on OCI700 via LPB
{0x493D0865,  CAT_SOLAR,            VT_TEMP,          3850,  STR3850,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Solar (nur wenn aktiviert) - Kollektorüberhitzschutz
{0x113D0865,  CAT_SOLAR,            VT_TEMP,          3850,  STR3850,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [°C ] - Solar (nur wenn aktiviert) - Kollektorüberhitzschutz - logged on OCI700 via LPB
{0x493D0551,  CAT_SOLAR,            VT_TEMP,          3860,  STR3860,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Solar (nur wenn aktiviert) - Verdampfung Waermetaeger
{0x113D0551,  CAT_SOLAR,            VT_TEMP,          3860,  STR3860,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [°C ] - Solar (nur wenn aktiviert) - Verdampfung Waermetaeger - logged on OCI700 via LPB
{0x493D04B1,  CAT_SOLAR,            VT_PERCENT,       3870,  STR3870,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendrehzahl Minimum
{0x493D04B0,  CAT_SOLAR,            VT_PERCENT,       3871,  STR3871,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendrehzahl Maximum
{CMD_UNKNOWN, CAT_SOLAR,            VT_UNKNOWN,       3872,  STR3872,  0,                    NULL,         FL_OEM, DEV_ALL}, // Drehzahl P-Band Xp
{CMD_UNKNOWN, CAT_SOLAR,            VT_UNKNOWN,       3873,  STR3873,  0,                    NULL,         FL_OEM, DEV_ALL}, // Drehzahl Nachstellzeit Tn
{0x493D0509,  CAT_SOLAR,            VT_ENUM,          3880,  STR3880,  sizeof(ENUM3880),     ENUM3880,     DEFAULT_FLAG, DEV_ALL}, // Frostschutzmittel
{0x493D050A,  CAT_SOLAR,            VT_PERCENT,       3881,  STR3881,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Frost'mittel Konzentration
{0x493D050C,  CAT_SOLAR,            VT_UINT,          3884,  STR3884,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendurchfluss
{0x053D0F93,  CAT_SOLAR,            VT_ENUM,          3887,  STR3887,  sizeof(ENUM3887),     ENUM3887,     DEFAULT_FLAG, DEV_ALL}, // Impulseinheit Ertrag

// Feststoffkessel
{0x513D088A,  CAT_FESTSTOFFKESSEL,  VT_ONOFF,         4102,  STR4102,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Feststoffkessel (nur wenn aktiviert) - Sperrt andere Erzeuger
{0x513D0885,  CAT_FESTSTOFFKESSEL,  VT_TEMP,          4110,  STR4110,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Feststoffkessel (nur wenn aktiviert) - Sollwert Minimum
{0x513D0B0C,  CAT_FESTSTOFFKESSEL,  VT_TEMP,          4112,  STR4112,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Maximaler Feststoffkessel-Sollwert
{0x513D0887,  CAT_FESTSTOFFKESSEL,  VT_TEMP,          4130,  STR4130,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Feststoffkessel (nur wenn aktiviert) - Temperaturdifferenz Ein
{0x513D0A04,  CAT_FESTSTOFFKESSEL,  VT_TEMP,          4131,  STR4131,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Feststoffkessel (nur wenn aktiviert) - Temperaturdifferenz Aus
{0x513D0A06,  CAT_FESTSTOFFKESSEL,  VT_ENUM,          4133,  STR4133,  sizeof(ENUM4133),     ENUM4133,     DEFAULT_FLAG, DEV_ALL}, // [°C ] - Feststoffkessel (nur wenn aktiviert) - Vergleichstempertatur
{0x513D089D,  CAT_FESTSTOFFKESSEL,  VT_MINUTES_SHORT, 4140,  STR4140,  0,                    NULL,         FL_OEM, DEV_ALL}, // Pumpennachlaufzeit
{CMD_UNKNOWN, CAT_FESTSTOFFKESSEL,  VT_UNKNOWN,       4141,  STR4141,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Feststoffkessel (nur wenn aktiviert) - Übertemperaturableitung
{CMD_UNKNOWN, CAT_FESTSTOFFKESSEL,  VT_UNKNOWN,       4170,  STR4170,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Feststoffkessel (nur wenn aktiviert) - Anl'frostschutz Kess'pumpe

// 4170 Anlagenfrostschutz Kesselpumpe An/Aus

// Pufferspeicher
{CMD_UNKNOWN, CAT_PUFFERSPEICHER,   VT_UNKNOWN,       4708,  STR4708,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zwangsladungsollwert Kühlen
{0x053D0B2F,  CAT_PUFFERSPEICHER,   VT_TEMP,          4709,  STR4709,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zwangsladungsoll Heizen Min
{0x053D0B2E,  CAT_PUFFERSPEICHER,   VT_TEMP,          4710,  STR4710,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zwangsladungsoll Heizen Max
{CMD_UNKNOWN, CAT_PUFFERSPEICHER,   VT_UNKNOWN,       4711,  STR4711,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zwangsladung Zeitpunkt
{CMD_UNKNOWN, CAT_PUFFERSPEICHER,   VT_UNKNOWN,       4712,  STR4712,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zwangsladung Dauer Max
{0x053D0455,  CAT_PUFFERSPEICHER,   VT_ENUM,          4720,  STR4720,  sizeof(ENUM4720),     ENUM4720,     DEFAULT_FLAG, DEV_ALL}, // [0] - Pufferspeicher (nur wenn aktiviert) - Auto Erzeugersperre
{0x053D0858,  CAT_PUFFERSPEICHER,   VT_TEMP,          4721,  STR4721,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Pufferspeicher (nur wenn aktiviert) - Auto Erzeugersperre SD
{0x053D0857,  CAT_PUFFERSPEICHER,   VT_TEMP,          4722,  STR4722,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Pufferspeicher (nur wenn aktiviert) - Temp`diff Puffer/Heizkreis
{0x053D0A10,  CAT_PUFFERSPEICHER,   VT_TEMP,          4724,  STR4724,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Pufferspeicher (nur wenn aktiviert) - Min Speichertemp Heizbetrieb
{CMD_UNKNOWN, CAT_PUFFERSPEICHER,   VT_UNKNOWN,       4739,  STR4739,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Schichtschutz
{CMD_UNKNOWN, CAT_PUFFERSPEICHER,   VT_UNKNOWN,       4740,  STR4740,  0,                    NULL,         FL_OEM, DEV_ALL}, // Schichtschutz Tempdiff Max
{CMD_UNKNOWN, CAT_PUFFERSPEICHER,   VT_UNKNOWN,       4743,  STR4743,  0,                    NULL,         FL_OEM, DEV_ALL}, // Schichtschutz Vor’schauzeit
{CMD_UNKNOWN, CAT_PUFFERSPEICHER,   VT_UNKNOWN,       4744,  STR4744,  0,                    NULL,         FL_OEM, DEV_ALL}, // Schichtschutz Nachstellzeit
{CMD_UNKNOWN, CAT_PUFFERSPEICHER,   VT_UNKNOWN,       4746,  STR4746,  0,                    NULL,         FL_OEM, DEV_ALL}, // Trinkwasserschutz Kombi
{0x053D08A9,  CAT_PUFFERSPEICHER,   VT_TEMP,          4750,  STR4750,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Pufferspeicher (nur wenn aktiviert) - Ladetemperatur
{0x053D08A8,  CAT_PUFFERSPEICHER,   VT_TEMP,          4751,  STR4751,  0,                    NULL,         FL_OEM, DEV_ALL}, // [°C ] - Pufferspeicher (nur wenn aktiviert) - Speichertemperatur Maximum
{0x053D0A0D,  CAT_PUFFERSPEICHER,   VT_TEMP,          4755,  STR4755,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Pufferspeicher (nur wenn aktiviert) - Rückkühltemperatur
{0x053D0A0A,  CAT_PUFFERSPEICHER,   VT_ONOFF,         4756,  STR4756,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [-] - Pufferspeicher (nur wenn aktiviert) - Rückkühlung TWW/HK`s
{0x053D0A0B,  CAT_PUFFERSPEICHER,   VT_ENUM,          4757,  STR4757,  sizeof(ENUM4757),     ENUM4757,     DEFAULT_FLAG, DEV_ALL}, // [0] - Pufferspeicher (nur wenn aktiviert) - Rückkühlung Kollektor
{CMD_UNKNOWN, CAT_PUFFERSPEICHER,   VT_UNKNOWN,       4760,  STR4760,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Ladefühler Elektroeinsatz
{CMD_UNKNOWN, CAT_PUFFERSPEICHER,   VT_UNKNOWN,       4761,  STR4761,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zwangsladung mit Elektro
{0x053D0A12,  CAT_PUFFERSPEICHER,   VT_YESNO,         4783,  STR4783,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Pufferspeicher (nur wenn aktiviert) - Mit Solareinbindung
{0x053D08AD,  CAT_PUFFERSPEICHER,   VT_TEMP,          4790,  STR4790,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Temp'diff EIN Rückl'umlenk
{0x053D08AE,  CAT_PUFFERSPEICHER,   VT_TEMP,          4791,  STR4791,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Temp'diff AUS Rückl'umlenk
{0x053D0638,  CAT_PUFFERSPEICHER,   VT_ENUM,          4795,  STR4795,  sizeof(ENUM4795),     ENUM4795,     DEFAULT_FLAG, DEV_ALL}, // Vergleichstemp Rückl'umlenk
{0x053D085F,  CAT_PUFFERSPEICHER,   VT_ENUM,          4796,  STR4796,  sizeof(ENUM4796),     ENUM4796,     DEFAULT_FLAG, DEV_ALL}, // Wirksinn Rücklaufumlenkung
{0x193D0B87,  CAT_PUFFERSPEICHER,   VT_ENUM,          4810,  STR4810,  sizeof(ENUM4810),     ENUM4810,     FL_OEM, DEV_ALL}, // Durchladung
{CMD_UNKNOWN, CAT_PUFFERSPEICHER,   VT_UNKNOWN,       4811,  STR4811,  0,                    NULL,         FL_OEM, DEV_ALL}, // Durchladetemperatur Minimum
{0x193D0B88,  CAT_PUFFERSPEICHER,   VT_ENUM,          4813,  STR4813,  sizeof(ENUM4813),     ENUM4813,     FL_OEM, DEV_ALL}, // Durchladefühler

// Trinkwasserspeicher
{0x253D0737,  CAT_TWSPEICHER,       VT_ENUM,          5010,  STR5010,  sizeof(ENUM5010),     ENUM5010,     FL_OEM, DEV_ALL}, // Ladung
{0x053D0F7C,  CAT_TWSPEICHER,       VT_HOUR_MINUTES,  5011,  STR5011,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Trinkwasser-Speicher Ladevorlegungszeit
{0x313D3009,  CAT_TWSPEICHER,       VT_TEMP_SHORT5_US,5019,  STR5019,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TW Nachlad'Überhöh Schichtensp
{0x253D0720,  CAT_TWSPEICHER,       VT_TEMP,          5020,  STR5020,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Trinkwasser-Speicher - Vorlaufsollwertüberhöhung
{0x253D07C1,  CAT_TWSPEICHER,       VT_TEMP,          5021,  STR5021,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Trinkwasser-Speicher - Umladeüberhöhung
{0x253D087B,  CAT_TWSPEICHER,       VT_ENUM,          5022,  STR5022,  sizeof(ENUM5022),     ENUM5022,     DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser-Speicher - Ladeart
{0x253D087B,  CAT_TWSPEICHER,       VT_ENUM,          5022,  STR5022_2,sizeof(ENUM5022_2),   ENUM5022_2,   DEFAULT_FLAG, DEV_123_ALL}, // [0] - Trinkwasser-Speicher - Ladeart
{0x253D087B,  CAT_TWSPEICHER,       VT_ENUM,          5022,  STR5022_2,sizeof(ENUM5022_2),   ENUM5022_2,   DEFAULT_FLAG, DEV_162_ALL}, // [0] - Trinkwasser-Speicher - Ladeart
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_090_ALL}, // TW Schaltdifferenz 1 ein
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_096_ALL}, // TW Schaltdifferenz 1 ein
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_103_ALL}, // TW Schaltdifferenz 1 ein
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_107_ALL}, // TW Schaltdifferenz 1 ein
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_108_ALL}, // TW Schaltdifferenz 1 ein
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_116_ALL}, // TW Schaltdifferenz 1 ein
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_119_ALL}, // TW Schaltdifferenz 1 ein
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_123_ALL}, // TW Schaltdifferenz 1 ein
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_162_ALL}, // TW Schaltdifferenz 1 ein
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_163_ALL}, // TW Schaltdifferenz 1 ein
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_170_ALL}, // TW Schaltdifferenz 1 ein
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_195_ALL}, // TW Schaltdifferenz 1 ein
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_205_ALL}, // TW Schaltdifferenz 1 ein
{0x313D071D,  CAT_TWSPEICHER,       VT_TEMP,          5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_211_ALL}, // TW Schaltdifferenz 1 ein
{0x213D2F8F,  CAT_TWSPEICHER,       VT_TEMP_SHORT5_US,5024,  STR5024,  0,                    NULL,         FL_OEM, DEV_ALL}, // Trinkwasser-Speicher Schaltdifferenz
{0x213D2F90,  CAT_TWSPEICHER,       VT_TEMP_SHORT5_US,5025,  STR5025,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TW Schaltdifferenz 1 Aus min
{0x213D2F91,  CAT_TWSPEICHER,       VT_TEMP_SHORT5_US,5026,  STR5026,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TW Schaltdifferenz 1 Aus max
{0x213D2F92,  CAT_TWSPEICHER,       VT_TEMP_SHORT5_US,5027,  STR5027,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TW Schaltdifferenz 2 Ein
{0x213D2FD5,  CAT_TWSPEICHER,       VT_TEMP_SHORT5_US,5028,  STR5028,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TW Schaltdifferenz 2 Aus min
{0x213D2F93,  CAT_TWSPEICHER,       VT_TEMP_SHORT5_US,5029,  STR5029,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TW Schaltdifferenz 2 Aus max
{0x253D0731,  CAT_TWSPEICHER,       VT_MINUTES_WORD,  5030,  STR5030,  0,                    NULL,         FL_OEM, DEV_ALL}, // TW Ladezeitbegrenzung //FUJITSU
{0x253D0754,  CAT_TWSPEICHER,       VT_ENUM,          5040,  STR5040,  sizeof(ENUM5040),     ENUM5040,     FL_OEM, DEV_ALL}, // TW Entladeschutz
{0x253D08A3,  CAT_TWSPEICHER,       VT_TEMP,          5050,  STR5050,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Ladetemperatur Maximum
{0x153D08A3,  CAT_TWSPEICHER,       VT_TEMP,          5050,  STR5050,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Ladetemperatur Maximum - logged on OCI700 via LPB
{0x253D08A7,  CAT_TWSPEICHER,       VT_TEMP,          5051,  STR5051,  0,                    NULL,         FL_OEM, DEV_ALL}, // Speichertemperatur Maximum
{0x253D08BD,  CAT_TWSPEICHER,       VT_TEMP,          5055,  STR5055,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Rückkühltemperatur
{0x393D08BD,  CAT_TWSPEICHER,       VT_TEMP,          5055,  STR5055,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Rückkühltemperatur - logged on OCI700 via LPB
{0x313D0713,  CAT_TWSPEICHER,       VT_ONOFF,         5056,  STR5056,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser-Speicher - Rückkühlung Kessel/HK
{0x313D0714,  CAT_TWSPEICHER,       VT_ENUM,          5057,  STR5057,  sizeof(ENUM5057),     ENUM5057,     DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser-Speicher - Rückkühlung Kollektor
{0x253D0728,  CAT_TWSPEICHER,       VT_ENUM,          5060,  STR5060,  sizeof(ENUM5060),     ENUM5060,     DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser-Speicher - Elektroeinsatz Betriebsart
{0x253D0688,  CAT_TWSPEICHER,       VT_ENUM,          5061,  STR5061,  sizeof(ENUM5061),     ENUM5061,     DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser-Speicher - Elektroeinsatz Freigabe
{0x253D0687,  CAT_TWSPEICHER,       VT_ENUM,          5062,  STR5062,  sizeof(ENUM5062),     ENUM5062,     DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser-Speicher - Elektroeinsatz Regelung
{0x313D08AA,  CAT_TWSPEICHER,       VT_ONOFF,         5070,  STR5070,  0,                    NULL,         FL_OEM, DEV_ALL}, // Automatischer Push
{CMD_UNKNOWN, CAT_TWSPEICHER,       VT_UNKNOWN,       5071,  STR5071,  0,                    NULL,         FL_OEM, DEV_ALL}, // Ladevorrangzeit Push
{0x253D08CB,  CAT_TWSPEICHER,       VT_ONOFF,         5085,  STR5085,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser-Speicher - Übertemperaturabnahme
{0x313D07C2,  CAT_TWSPEICHER,       VT_YESNO,         5090,  STR5090,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Trinkwasser-Speicher - Mit Pufferspeicher
{0x313D07C3,  CAT_TWSPEICHER,       VT_YESNO,         5092,  STR5092,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ - ] - Trinkwasser-Speicher - Mit Vorregler/Zubring`pumpe
{0x253D0A11,  CAT_TWSPEICHER,       VT_YESNO,         5093,  STR5093,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [-] - Trinkwasser-Speicher - Mit Solareinbindung
{0x113D2F96,  CAT_TWSPEICHER,       VT_PERCENT,       5100,  STR5100,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TW Pumpe-PWM Durchladung
{0x253D08A1,  CAT_TWSPEICHER,       VT_PERCENT,       5101,  STR5101,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendrehzahl Minimum %
{0x053D115C,  CAT_TWSPEICHER,       VT_PERCENT,       5101,  STR5101,  0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Pumpendrehzahl Minimum %
{0x053D115C,  CAT_TWSPEICHER,       VT_PERCENT,       5101,  STR5101,  0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Pumpendrehzahl Minimum %
{0x253D08A2,  CAT_TWSPEICHER,       VT_PERCENT,       5102,  STR5102,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendrehzahl Maximum %
{0x053D115D,  CAT_TWSPEICHER,       VT_PERCENT,       5102,  STR5102,  0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Pumpendrehzahl Maximum %
{0x053D115D,  CAT_TWSPEICHER,       VT_PERCENT,       5102,  STR5102,  0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Pumpendrehzahl Maximum %
{0x253D0B19,  CAT_TWSPEICHER,       VT_UNKNOWN,       5103,  STR5103,  0,                    NULL,         FL_OEM, DEV_ALL}, // Drehzahl P-Band Xp
{0x253D0B1A,  CAT_TWSPEICHER,       VT_UNKNOWN,       5104,  STR5104,  0,                    NULL,         FL_OEM, DEV_ALL}, // Drehzahl Nachstellzeit Tn
{0x253D072C,  CAT_TWSPEICHER,       VT_UNKNOWN,       5120,  STR5120,  0,                    NULL,         FL_OEM, DEV_ALL}, // Mischerüberhöhung
{0x253D072B,  CAT_TWSPEICHER,       VT_UNKNOWN,       5124,  STR5124,  0,                    NULL,         FL_OEM, DEV_ALL}, // Antrieb Laufzeit
{0x253D0729,  CAT_TWSPEICHER,       VT_UNKNOWN,       5125,  STR5125,  0,                    NULL,         FL_OEM, DEV_ALL}, // Mischer-B-Band Xp
{CMD_UNKNOWN, CAT_TWSPEICHER,       VT_UNKNOWN,       5126,  STR5126,  0,                    NULL,         FL_OEM, DEV_ALL}, // Mischer Nachstellzeit Tn
{0x253D0B53,  CAT_TWSPEICHER,       VT_ENUM,          5130,  STR5130,  sizeof(ENUM5130),     ENUM5130,     FL_OEM, DEV_ALL}, // Umladestrategie
{0x253D0879,  CAT_TWSPEICHER,       VT_ENUM,          5131,  STR5131,  sizeof(ENUM5131),     ENUM5131,     FL_OEM, DEV_ALL}, // Vergleichstemp Umladung

// Trinkwasser Durchl'erhitzer
{0x313D2FC5,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT5,   5400,  STR5400,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 5400 Komfortsollwert [°C]
{CMD_UNKNOWN, CAT_DRUCHLERHITZER,   VT_TEMP,          5406,  STR5406,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Min Sollw'diff zu Speich'temp
{CMD_UNKNOWN, CAT_DRUCHLERHITZER,   VT_TEMP,          5420,  STR5420,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 5420 Vorlauf-Sollwertüberhöhung [°C]
{0x22052F8F,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT5,   5430,  STR5430,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einschaltdifferenz im BW-Betrieb (Fühler 1) [°C]
{0x22052F90,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT5,   5431,  STR5431,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Min. Ausschaltdifferenz im BW-Betrieb (Fühler 1) [°C]
{0x22052F91,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT5,   5432,  STR5432,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Max. Ausschaltdifferenz im BW-Betrieb (Fühler 1) [°C]
{0x22052F92,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT5,   5433,  STR5433,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Einschaltdifferenz im BW-Betrieb (Fühler 2) [°C]
{0x22052FD5,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT5,   5434,  STR5434,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Min. Ausschaltdifferenz im BW-Betrieb (Fühler 2) [°C]
{0x22052F93,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT5,   5435,  STR5435,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Max. Ausschaltdifferenz im BW-Betrieb (Fühler 2) [°C]
{0x31052FC0,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT64,  5450,  STR5450,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 5450 Gradient Zapfende [K/s]
{0x31052FC1,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT64,  5451,  STR5451,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 5451 Gradient Beginn Zapf Komf [K/s]
{0x31052FC2,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT64,  5452,  STR5452,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 5452 Gradient Beginn Zapfung Hz [K/s]
{0x31052FB0,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT5,   5453,  STR5453,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sollwertkorrektur bei Komfortregelung mit 40°C
{0x31052FB1,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT5,   5454,  STR5454,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sollwertkorrektur bei Komfortregelung mit 60°C
{0x31052FB2,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT5,   5455,  STR5455,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sollwertkorrektur bei Auslaufregelung mit 40°C
{0x31052FB3,  CAT_DRUCHLERHITZER,   VT_TEMP_SHORT5,   5456,  STR5456,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Sollwertkorrektur bei Auslaufregelung mit 60°C
{0x31052FC3,  CAT_DRUCHLERHITZER,   VT_MINUTES_WORD10,5480,  STR5480,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 5480 Komfortzeit ohne Hz-Anfo [min]
{0x31052FC4,  CAT_DRUCHLERHITZER,   VT_MINUTES_SHORT, 5481,  STR5481,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 5481 Komfortzeit mit Hz-Anfo [min]
{0x153D3010,  CAT_DRUCHLERHITZER,   VT_SECONDS_WORD,  5482,  STR5482,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeit TWW-FlowSwitch geschlossen
{0x193D3011,  CAT_DRUCHLERHITZER,   VT_SECONDS_WORD,  5483,  STR5483,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeit TWW-Komfort FlowSwitch geschlossen
{0x313D300D,  CAT_DRUCHLERHITZER,   VT_SECONDS_SHORT, 5486,  STR5486,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Reglerverzögerung bei Takten in DLH Auslaufbetr.
{0x2E3D2FDB,  CAT_DRUCHLERHITZER,   VT_SECONDS_SHORT, 5487,  STR5487,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 5487 Pump'nachlauf Komf [min]
{0x223D301B,  CAT_DRUCHLERHITZER,   VT_SECONDS_SHORT, 5488,  STR5488,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 5488 Pump'nachlauf Komf [sek]
{CMD_UNKNOWN, CAT_DRUCHLERHITZER,   VT_UNKNOWN,       5530,  STR5530,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpendrehzahl Minimum
{CMD_UNKNOWN, CAT_DRUCHLERHITZER,   VT_UNKNOWN,       5544,  STR5544,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Antrieb Laufzeit
{CMD_UNKNOWN, CAT_DRUCHLERHITZER,   VT_UNKNOWN,       5545,  STR5545,  0,                    NULL,         FL_OEM, DEV_ALL}, // Mischer P-Band Xp
{CMD_UNKNOWN, CAT_DRUCHLERHITZER,   VT_UNKNOWN,       5546,  STR5546,  0,                    NULL,         FL_OEM, DEV_ALL}, // Mischer Nachstellzeit Tn
{CMD_UNKNOWN, CAT_DRUCHLERHITZER,   VT_UNKNOWN,       5547,  STR5547,  0,                    NULL,         FL_OEM, DEV_ALL}, // Mischer Vorhaltezeit Tv
};

PROGMEM_LATE const cmd_t cmdtbl2[]={
// Konfiguration
{0x053D0712,  CAT_KONFIG,           VT_ENUM,          5700,  STR5700,  sizeof(ENUM5700),     ENUM5700,     DEFAULT_FLAG, DEV_ALL}, // Voreinstellung //FUJITSU
{0x2D3D2FEA,  CAT_KONFIG,           VT_BYTE,          5701,  STR5701,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 5701 Hydraulisches Schema [2..85 enum?]
{0x053D04C0,  CAT_KONFIG,           VT_ONOFF,         5710,  STR5710,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Heizkreis 1
{0x2D3D04C0,  CAT_KONFIG,           VT_ONOFF,         5710,  STR5710,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - Konfiguration - Heizkreis 1 - logged on OCI700 via LPB
{0x053D0A73,  CAT_KONFIG,           VT_ENUM,          5711,  STR5711,  sizeof(ENUM5711),     ENUM5711,     DEFAULT_FLAG, DEV_ALL}, // Kühlkreis 1 //FUJITSU
{0x053D0A77,  CAT_KONFIG,           VT_ENUM,          5712,  STR5712,  sizeof(ENUM5712),     ENUM5712,     DEFAULT_FLAG, DEV_ALL}, // Verwendung Mischer 1
{0x063D04C0,  CAT_KONFIG,           VT_ONOFF,         5715,  STR5715,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Heizkreis 2
{0x2E3D04C0,  CAT_KONFIG,           VT_ONOFF,         5715,  STR5715,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - Konfiguration - Heizkreis 2 - logged on OCI700 via LPB
{0x073D04C0,  CAT_KONFIG,           VT_ONOFF,         5721,  STR5721,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Heizkreis 3
{0x313D071E,  CAT_KONFIG,           VT_ENUM,          5730,  STR5730,  sizeof(ENUM5730),     ENUM5730,     DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Trinkwasser-Sensor B3
{0x253D071C,  CAT_KONFIG,           VT_ENUM,          5731,  STR5731,  sizeof(ENUM5731),     ENUM5731,     DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Trinkwasser-Stellglied Q3
{0x113D2FE3,  CAT_KONFIG,           VT_SECONDS_SHORT, 5732,  STR5732,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 5732 TWW Pumpenpause Umsch UV [s]
{0x393D2FE3,  CAT_KONFIG,           VT_SECONDS_SHORT, 5732,  STR5732,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Thision 5732 TWW Pumpenpause Umsch UV [s] - logged on OCI700 via LPB
{0x113D2FE4,  CAT_KONFIG,           VT_SECONDS_SHORT, 5733,  STR5733,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 5733 TWW Pumpenpause Verzögerung [s]
{0x393D2FE4,  CAT_KONFIG,           VT_SECONDS_SHORT, 5733,  STR5733,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Thision 5733 TWW Pumpenpause Verzögerung [s] - logged on OCI700 via LPB
{0x053D0F7B,  CAT_KONFIG,           VT_ENUM,          5734,  STR5734,  sizeof(ENUM5734),     ENUM5734,     FL_RONLY,     DEV_ALL}, // Grundposition TWW Uml'ventil
{0x053D0727,  CAT_KONFIG,           VT_ONOFF,         5736,  STR5736,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Trinkwasser Trennschaltung
// {CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       5737,  STR5737,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Wirksinn TW Umlenkventil
{0x053D079C,  CAT_KONFIG,           VT_ENUM,          5760,  STR5760,  sizeof(ENUM5760),     ENUM5760,     DEFAULT_FLAG, DEV_ALL}, // Vorregler/Zubringerpumpe [Vor Pufferspeicher | Nach Pufferspeicher] (Nach Pufferspeicher)
{0x193D2FDC,  CAT_KONFIG,           VT_BIT,           5761,  STR5761,  sizeof(ENUM5761),     ENUM5761,     DEFAULT_FLAG, DEV_ALL}, // Thision 5761 Zubringerpumpe Q8 Bit 0-3 [?]
{0x053D0851,  CAT_KONFIG,           VT_ENUM,          5770,  STR5770,  sizeof(ENUM5770),     ENUM5770,     DEFAULT_FLAG, DEV_ALL}, // Erzeugertyp
{0x053D07BF,  CAT_KONFIG,           VT_SECONDS_SHORT, 5772,  STR5772,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Brenner Vorlaufzeit
{0x053D0F9A,  CAT_KONFIG,           VT_ENUM,          5774,  STR5774,  sizeof(ENUM5774),     ENUM5774,     DEFAULT_FLAG, DEV_ALL}, // Steuerung Kesselpumpe/TWW Umlenkventil
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       5800,  STR5800,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Wärmequelle
{0x053D1119,  CAT_KONFIG,           VT_ENUM,          5806,  STR5806,  sizeof(ENUM5806),     ENUM5806,     DEFAULT_FLAG, DEV_ALL}, // Typ Elektroeinsatz Vorlauf //FUJITSU
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       5807,  STR5807,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Kälteerzeugung
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       5810,  STR5810,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Spreizung HK bei TA –10 °C
// TODO  Note: There is only one configuration parameter 5840 "Solarstellglied" but
// a)  two diagnostic reports 8501, 8502 for "Solarstellglied Puffer" and "Solarstellglied Schwimmbad",
// b1) two relay configuration options 5890 QX1  "Solarstellglied Puffer" and "Solarstellglied Schwimmbad" OR
// b2) the same two relay configuration options in 5891, 5892, 5894, 5902, 5904, 5908, 6030.
// c)  two error messages "Solarstellglied Puffer fehlt" and "Solarstellglied Schwimmbad fehlt"
{0x053D0827,  CAT_KONFIG,           VT_ENUM,          5840,  STR5840,  sizeof(ENUM5840),     ENUM5840,     DEFAULT_FLAG, DEV_ALL}, // Solarstellglied
{0x053D0829,  CAT_KONFIG,           VT_ENUM,          5841,  STR5841,  sizeof(ENUM5841),     ENUM5841,     DEFAULT_FLAG, DEV_ALL}, // Externer Solartauscher
{0x253D071B,  CAT_KONFIG,           VT_YESNO,         5870,  STR5870,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Kombispeicher
{0x053D0497,  CAT_KONFIG,           VT_ENUM,          5890,  STR5890,  sizeof(ENUM5890),     ENUM5890,     DEFAULT_FLAG, DEV_ALL}, // [-] - Konfiguration - Relaisausgang QX1
{0x053D0497,  CAT_KONFIG,           VT_ENUM,          5890,  STR5890_2,sizeof(ENUM5890_2),   ENUM5890_2,   DEFAULT_FLAG, DEV_076_ALL}, // [-] - Konfiguration - Relaisausgang QX1
{0x053D0498,  CAT_KONFIG,           VT_ENUM,          5891,  STR5891,  sizeof(ENUM5891),     ENUM5891,     DEFAULT_FLAG, DEV_ALL}, // [-] - Konfiguration - Relaisausgang QX2
{0x053D0498,  CAT_KONFIG,           VT_ENUM,          5891,  STR5891_2,  sizeof(ENUM5891),   ENUM5891,     DEFAULT_FLAG, DEV_076_ALL}, // [-] - Konfiguration - Relaisausgang QX2
{0x053D0587,  CAT_KONFIG,           VT_ENUM,          5892,  STR5892,  sizeof(ENUM5892),     ENUM5892,     DEFAULT_FLAG, DEV_ALL}, // [-] - Konfiguration - Relaisausgang QX3
{0x053D0588,  CAT_KONFIG,           VT_ENUM,          5894,  STR5894,  sizeof(ENUM5894),     ENUM5894,     DEFAULT_FLAG, DEV_ALL}, // Relaisausgang QX4
{0x053D0589,  CAT_KONFIG,           VT_UNKNOWN,       5895,  STR5895,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Relaisausgang QX5
{0x053D058A,  CAT_KONFIG,           VT_UNKNOWN,       5896,  STR5896,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Relaisausgang QX6
{0x053D0785,  CAT_KONFIG,           VT_ENUM,          5902,  STR5902,  sizeof(ENUM5902),     ENUM5902,     DEFAULT_FLAG, DEV_ALL}, // Relaisausgang QX21
{0x053D0787,  CAT_KONFIG,           VT_ENUM,          5904,  STR5904,  sizeof(ENUM5904),     ENUM5904,     DEFAULT_FLAG, DEV_ALL}, // Relaisausgang QX23
{0x053D04A0,  CAT_KONFIG,           VT_ENUM,          5908,  STR5908,  sizeof(ENUM5908),     ENUM5908,     DEFAULT_FLAG, DEV_ALL}, // Funktion Ausgang QX3-Mod
// provide 5902-5908 for non-Brötje systems
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       5909,  STR5909,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Funktion Ausgang QX4-Mod
{0x153D2FCC,  CAT_KONFIG,           VT_BIT,           5920,  STR5920,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 5920 Relaisausgang K2 LMU-Basis Bit 0-7 [?]
{0x053D3078,  CAT_KONFIG,           VT_YESNO,         5921,  STR5921,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 5921 Default K2 auf K1 [Ja/Nein]
{0x153D2FCF,  CAT_KONFIG,           VT_ENUM,          5922,  STR5922,  sizeof(ENUM5922),     ENUM5922,     DEFAULT_FLAG, DEV_ALL}, // Thision 5922 Relaisausgang 1 RelCl [enum: ]
{0x153D2FD0,  CAT_KONFIG,           VT_ENUM,          5923,  STR5923,  sizeof(ENUM5923),     ENUM5923,     DEFAULT_FLAG, DEV_ALL}, // Thision 5923 Relaisausgang 2 RelCl [s.o.]
{0x153D2FD1,  CAT_KONFIG,           VT_ENUM,          5924,  STR5924,  sizeof(ENUM5924),     ENUM5924,     DEFAULT_FLAG, DEV_ALL}, // Thision 5924 Relaisausgang 3 RelCl [s.o.]
{0x493D3012,  CAT_KONFIG,           VT_ENUM,          5926,  STR5926,  sizeof(ENUM5926),     ENUM5926,     DEFAULT_FLAG, DEV_ALL}, // Thision 5926 Relaisausgang 1 SolCl [s.o.]
{0x393D3012,  CAT_KONFIG,           VT_ENUM,          5926,  STR5926,  sizeof(ENUM5926),     ENUM5926,     DEFAULT_FLAG, DEV_064_ALL}, // Thision 5926 Relaisausgang 1 SolCl [s.o.] - logged on OCI700 via LPB
{0x093D3013,  CAT_KONFIG,           VT_ENUM,          5927,  STR5927,  sizeof(ENUM5927),     ENUM5927,     DEFAULT_FLAG, DEV_ALL}, // Thision 5927 Relaisausgang 2 SolCl [s.o.]
{0x093D3014,  CAT_KONFIG,           VT_ENUM,          5928,  STR5928,  sizeof(ENUM5928),     ENUM5928,     DEFAULT_FLAG, DEV_ALL}, // Thision 5928 Relaisausgang 3 SolCl [s.o.]
{0x053D0567,  CAT_KONFIG,           VT_ENUM,          5930,  STR5930,  sizeof(ENUM5930),     ENUM5930,     DEFAULT_FLAG, DEV_ALL}, // [-] - Konfiguration - Fühlereingang BX 1
{0x053D0568,  CAT_KONFIG,           VT_ENUM,          5931,  STR5931,  sizeof(ENUM5931),     ENUM5931,     DEFAULT_FLAG, DEV_ALL}, // [-] - Konfiguration - Fühlereingang BX 2
{0x053D07CA,  CAT_KONFIG,           VT_ENUM,          5932,  STR5932,  sizeof(ENUM5932),     ENUM5932,     DEFAULT_FLAG, DEV_ALL}, // [-] - Konfiguration - Fühlereingang BX 3
{0x053D07CB,  CAT_KONFIG,           VT_ENUM,          5933,  STR5933,  sizeof(ENUM5933),     ENUM5933,     DEFAULT_FLAG, DEV_ALL}, // [-] - Konfiguration - Fühlereingang BX 4
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       5934,  STR5934,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Fühlereingang BX5
{0x053D077F,  CAT_KONFIG,           VT_ENUM,          5941,  STR5941,  sizeof(ENUM5941),     ENUM5941,     DEFAULT_FLAG, DEV_ALL}, // [-] - Konfiguration - Fühlereingang BX21
{0x053D0784,  CAT_KONFIG,           VT_ENUM,          5942,  STR5942,  sizeof(ENUM5942),     ENUM5942,     DEFAULT_FLAG, DEV_ALL}, // [-] - Konfiguration - Fühlereingang BX22
{0x053D0807,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950),     ENUM5950,     DEFAULT_FLAG, DEV_ALL}, // [-] - Konfiguration - Funktion Eingang H1 (LOGON B)
{0x39053052,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950),     ENUM5950,     DEFAULT_FLAG, DEV_064_ALL}, // [-] - Konfiguration - Funktion Eingang H1 (LOGON B) - logged on OCI700 via LPB
{0x053D0807,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950),     ENUM5950,     DEFAULT_FLAG, DEV_116_ALL}, // [-] - Konfiguration - Funktion Eingang H1 (LOGON B)
{0x053D0807,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950),     ENUM5950,     DEFAULT_FLAG, DEV_090_ALL}, // [-] - Konfiguration - Funktion Eingang H1 (LOGON B)
{0x053D3052,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950_2),   ENUM5950_2,   DEFAULT_FLAG, DEV_097_ALL}, // [-] - Konfiguration - Funktion Eingang H1
{0x053D3052,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950_2),   ENUM5950_2,   DEFAULT_FLAG, DEV_098_ALL}, // [-] - Konfiguration - Funktion Eingang H1
{0x053D0483,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950_6),   ENUM5950_6,   DEFAULT_FLAG, DEV_076_ALL}, // [-] - Konfiguration - Funktion Eingang H1
{0x053D0483,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950_3),   ENUM5950_3,   DEFAULT_FLAG, DEV_096_ALL}, // [-] - Konfiguration - Funktion Eingang H1
{0x053D0D91,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950_4),   ENUM5950_4,   DEFAULT_FLAG, DEV_108_ALL}, // [-] - Konfiguration - Funktion Eingang H1
{0x053D0D91,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950_4),   ENUM5950_4,   DEFAULT_FLAG, DEV_123_ALL}, // [-] - Konfiguration - Funktion Eingang H1
{0x053D0D91,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950_4),   ENUM5950_4,   DEFAULT_FLAG, DEV_138_ALL}, // [-] - Konfiguration - Funktion Eingang H1
{0x053D0D91,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950_4),   ENUM5950_4,   DEFAULT_FLAG, DEV_162_ALL}, // [-] - Konfiguration - Funktion Eingang H1
{0x053D0D91,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950_4),   ENUM5950_4,   DEFAULT_FLAG, DEV_163_ALL}, // [-] - Konfiguration - Funktion Eingang H1
{0x053D0D91,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950_4),   ENUM5950_4,   DEFAULT_FLAG, DEV_195_ALL}, // [-] - Konfiguration - Funktion Eingang H1
{0x053D0D91,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950_4),   ENUM5950_4,   DEFAULT_FLAG, DEV_205_ALL}, // [-] - Konfiguration - Funktion Eingang H1
{0x053D0D91,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950_4),   ENUM5950_4,   DEFAULT_FLAG, DEV_211_ALL}, // [-] - Konfiguration - Funktion Eingang H1
{0x053D0807,  CAT_KONFIG,           VT_ENUM,          5950,  STR5950,  sizeof(ENUM5950_5),   ENUM5950_5,   DEFAULT_FLAG, DEV_107_ALL}, // [-] - Konfiguration - Funktion Eingang H1
{0x053D0487,  CAT_KONFIG,           VT_ENUM,          5951,  STR5951,  sizeof(ENUM5951),     ENUM5951,     DEFAULT_FLAG, DEV_076_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H1
{0x053D0487,  CAT_KONFIG,           VT_ENUM,          5951,  STR5951,  sizeof(ENUM5951),     ENUM5951,     DEFAULT_FLAG, DEV_096_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H1
{0x053D0808,  CAT_KONFIG,           VT_ENUM,          5951,  STR5951,  sizeof(ENUM5951),     ENUM5951,     DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H1
{0x053D0DC8,  CAT_KONFIG,           VT_ENUM,          5951,  STR5951,  sizeof(ENUM5951),     ENUM5951,     DEFAULT_FLAG, DEV_108_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H1
{0x053D0DC8,  CAT_KONFIG,           VT_ENUM,          5951,  STR5951,  sizeof(ENUM5951),     ENUM5951,     DEFAULT_FLAG, DEV_123_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H1
{0x053D0DC8,  CAT_KONFIG,           VT_ENUM,          5951,  STR5951,  sizeof(ENUM5951),     ENUM5951,     DEFAULT_FLAG, DEV_162_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H1
{0x053D0DC8,  CAT_KONFIG,           VT_ENUM,          5951,  STR5951,  sizeof(ENUM5951),     ENUM5951,     DEFAULT_FLAG, DEV_163_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H1
{0x053D0DC8,  CAT_KONFIG,           VT_ENUM,          5951,  STR5951,  sizeof(ENUM5951),     ENUM5951,     DEFAULT_FLAG, DEV_195_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H1
{0x053D0DC8,  CAT_KONFIG,           VT_ENUM,          5951,  STR5951,  sizeof(ENUM5951),     ENUM5951,     DEFAULT_FLAG, DEV_205_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H1
{0x053D0DC8,  CAT_KONFIG,           VT_ENUM,          5951,  STR5951,  sizeof(ENUM5951),     ENUM5951,     DEFAULT_FLAG, DEV_211_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H1
{0x293D0656,  CAT_KONFIG,           VT_TEMP,          5952,  STR5952,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Konfiguration - Minimaler Vorlaufsollwert H1
{0x053D1128,  CAT_KONFIG,           VT_VOLTAGE,       5953,  STR5953,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Spannungswert 1 H1
{0x053D0B7B,  CAT_KONFIG,           VT_VOLTAGE,       5953,  STR5953,  0,                    NULL,         DEFAULT_FLAG, DEV_103_ALL}, // Spannungswert 1 H1
{0x053D0B7B,  CAT_KONFIG,           VT_VOLTAGE,       5953,  STR5953,  0,                    NULL,         DEFAULT_FLAG, DEV_107_ALL}, // Spannungswert 1 H1
{0x053D0B7B,  CAT_KONFIG,           VT_VOLTAGE,       5953,  STR5953,  0,                    NULL,         DEFAULT_FLAG, DEV_119_ALL}, // Spannungswert 1 H1
{0x053D0B7B,  CAT_KONFIG,           VT_VOLTAGE,       5953,  STR5953,  0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Spannungswert 1 H1
{0x053D0B7B,  CAT_KONFIG,           VT_VOLTAGE,       5953,  STR5953,  0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Spannungswert 1 H1
{0x053D0B7B,  CAT_KONFIG,           VT_VOLTAGE,       5953,  STR5953,  0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Spannungswert 1 H1
{0x053D0B7B,  CAT_KONFIG,           VT_VOLTAGE,       5953,  STR5953,  0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Spannungswert 1 H1
{0x053D079F,  CAT_KONFIG,           VT_TEMP,          5954,  STR5954,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x063D079F,  CAT_KONFIG,           VT_TEMP,          5954,  STR5954,  0,                    NULL,         DEFAULT_FLAG, DEV_076_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B7D,  CAT_KONFIG,           VT_TEMP,          5954,  STR5954_2,0,                    NULL,         DEFAULT_FLAG, DEV_103_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B7D,  CAT_KONFIG,           VT_TEMP,          5954,  STR5954_2,0,                    NULL,         DEFAULT_FLAG, DEV_107_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B7D,  CAT_KONFIG,           VT_TEMP,          5954,  STR5954_2,0,                    NULL,         DEFAULT_FLAG, DEV_108_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B7D,  CAT_KONFIG,           VT_TEMP,          5954,  STR5954_2,0,                    NULL,         DEFAULT_FLAG, DEV_119_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B7D,  CAT_KONFIG,           VT_TEMP,          5954,  STR5954_2,0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B7D,  CAT_KONFIG,           VT_TEMP,          5954,  STR5954_2,0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B7D,  CAT_KONFIG,           VT_TEMP,          5954,  STR5954_2,0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B7D,  CAT_KONFIG,           VT_TEMP,          5954,  STR5954_2,0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B7D,  CAT_KONFIG,           VT_TEMP,          5954,  STR5954_2,0,                    NULL,         DEFAULT_FLAG, DEV_205_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B7D,  CAT_KONFIG,           VT_TEMP,          5954,  STR5954_2,0,                    NULL,         DEFAULT_FLAG, DEV_211_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D1129,  CAT_KONFIG,           VT_VOLTAGE,       5955,  STR5955,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Spannungswert 2 H1
{0x053D0B7C,  CAT_KONFIG,           VT_VOLTAGE,       5955,  STR5955,  0,                    NULL,         DEFAULT_FLAG, DEV_103_ALL}, // Spannungswert 2 H1
{0x053D0B7C,  CAT_KONFIG,           VT_VOLTAGE,       5955,  STR5955,  0,                    NULL,         DEFAULT_FLAG, DEV_107_ALL}, // Spannungswert 2 H1
{0x053D0B7C,  CAT_KONFIG,           VT_VOLTAGE,       5955,  STR5955,  0,                    NULL,         DEFAULT_FLAG, DEV_119_ALL}, // Spannungswert 2 H1
{0x053D0B7C,  CAT_KONFIG,           VT_VOLTAGE,       5955,  STR5955,  0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Spannungswert 2 H1
{0x053D0B7C,  CAT_KONFIG,           VT_VOLTAGE,       5955,  STR5955,  0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Spannungswert 2 H1
{0x053D0B7C,  CAT_KONFIG,           VT_VOLTAGE,       5955,  STR5955,  0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Spannungswert 2 H1
{0x053D0B7C,  CAT_KONFIG,           VT_VOLTAGE,       5955,  STR5955,  0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Spannungswert 2 H1
{0x053D05DC,  CAT_KONFIG,           VT_PRESSURE,      5956,  STR5956,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [bar ] - Konfiguration - Druckwert 3.5V H1
{0x053D0B83,  CAT_KONFIG,           VT_UNKNOWN,       5956,  STR5956_2,0,                    NULL,         DEFAULT_FLAG, DEV_107_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B83,  CAT_KONFIG,           VT_UNKNOWN,       5956,  STR5956_2,0,                    NULL,         DEFAULT_FLAG, DEV_108_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B83,  CAT_KONFIG,           VT_UNKNOWN,       5956,  STR5956_2,0,                    NULL,         DEFAULT_FLAG, DEV_119_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B83,  CAT_KONFIG,           VT_UNKNOWN,       5956,  STR5956_2,0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B83,  CAT_KONFIG,           VT_UNKNOWN,       5956,  STR5956_2,0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B83,  CAT_KONFIG,           VT_UNKNOWN,       5956,  STR5956_2,0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B83,  CAT_KONFIG,           VT_UNKNOWN,       5956,  STR5956_2,0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B83,  CAT_KONFIG,           VT_UNKNOWN,       5956,  STR5956_2,0,                    NULL,         DEFAULT_FLAG, DEV_205_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1
{0x053D0B83,  CAT_KONFIG,           VT_UNKNOWN,       5956,  STR5956_2,0,                    NULL,         DEFAULT_FLAG, DEV_211_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H1

// !FIXME! !AUTOGENERATED! same cmd as 5950
{0x053D0483,  CAT_KONFIG,           VT_ENUM,          5957,  STR5957,  sizeof(ENUM5957),     ENUM5957,     DEFAULT_FLAG, DEV_ALL}, // Thision 5957 Modemfunktion
// Python code defines 0x053D0483 5957 as "BA-Umschaltung HK's+TWW" <- that's one of the selectable parameter options only!
// !FIXME! !AUTOGENERATED! same cmd as 5950
{0x053D0483,  CAT_KONFIG,           VT_ENUM,          5957,  STR5957_3,sizeof(ENUM5957_2),   ENUM5957_2,   DEFAULT_FLAG, DEV_076_ALL}, // BA-Umschaltung HK's+TWW
{0x053D0483,  CAT_KONFIG,           VT_ENUM,          5957,  STR5957_2,sizeof(ENUM5957),     ENUM5957,     DEFAULT_FLAG, DEV_096_ALL}, // BA-Umschaltung HK's+TWW
{0x073D0807,  CAT_KONFIG,           VT_ENUM,          5960,  STR5960,  sizeof(ENUM5960),     ENUM5960,     DEFAULT_FLAG, DEV_ALL}, // [-] - Konfiguration - Funktion Eingang H3
{0x053D0484,  CAT_KONFIG,           VT_ENUM,          5960,  STR5960_2,sizeof(ENUM5960_3),   ENUM5960_3,   DEFAULT_FLAG, DEV_076_ALL}, // [-] - Konfiguration - Funktion Eingang H3
{0x053D0484,  CAT_KONFIG,           VT_ENUM,          5960,  STR5960_2,sizeof(ENUM5960_2),   ENUM5960_2,   DEFAULT_FLAG, DEV_096_ALL}, // [-] - Konfiguration - Funktion Eingang H3
{0x073D0808,  CAT_KONFIG,           VT_ENUM,          5961,  STR5961,  sizeof(ENUM5961),     ENUM5961,     DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H3
{0x053D0575,  CAT_KONFIG,           VT_ENUM,          5961,  STR5961_2,sizeof(ENUM5961_2),   ENUM5961_2,   DEFAULT_FLAG, DEV_096_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H3
// !FIXME! ProgNr 5962 is listed as 0x073d0656 in Python project
{0x2B3D0656,  CAT_KONFIG,           VT_TEMP,          5962,  STR5962,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Konfiguration - Minimaler Vorlaufsollwert H3
{0x2A3D0656,  CAT_KONFIG,           VT_TEMP,          5962,  STR5962_2,0,                    NULL,         DEFAULT_FLAG, DEV_096_ALL}, // [°C ] - Konfiguration - Minimaler Vorlaufsollwert H2
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       5963,  STR5963,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Spannungswert 1 H3
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       5963,  STR5963_2,0,                    NULL,         DEFAULT_FLAG, DEV_096_ALL}, // Spannungswert 1 H3
{0x073D079F,  CAT_KONFIG,           VT_TEMP,          5964,  STR5964,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Konfiguration - Waermeanforderung 10V H3
{0x063D079F,  CAT_KONFIG,           VT_TEMP,          5964,  STR5964_2,0,                    NULL,         DEFAULT_FLAG, DEV_096_ALL}, // [°C ] - Konfiguration - Temperaturwert 10V H2

{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       5965,  STR5965,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Spannungswert 2 H3
{0x073D05DC,  CAT_KONFIG,           VT_PRESSURE,      5966,  STR5966,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [bar ] - Konfiguration - Druckwer 3.5V H3
{0x2D3D3073,  CAT_KONFIG,           VT_ENUM,          5970,  STR5970,  sizeof(ENUM5970),     ENUM5970,     DEFAULT_FLAG, DEV_ALL}, // Thision 5970 Konfig Raumthermostat 1 [enum]
{0x053D0D96,  CAT_KONFIG,           VT_ENUM,          5970,  STR5970_2,sizeof(ENUM5970_2),   ENUM5970_2,   DEFAULT_FLAG, DEV_123_ALL}, // [0] - Konfiguration - Funktion Kontakt H4
{0x053D0D96,  CAT_KONFIG,           VT_ENUM,          5970,  STR5970_2,sizeof(ENUM5970_2),   ENUM5970_2,   DEFAULT_FLAG, DEV_162_ALL}, // [0] - Konfiguration - Funktion Kontakt H4
{0x053D0D96,  CAT_KONFIG,           VT_ENUM,          5970,  STR5970_2,sizeof(ENUM5970_2),   ENUM5970_2,   DEFAULT_FLAG, DEV_163_ALL}, // [0] - Konfiguration - Funktion Kontakt H4
{0x053D0D96,  CAT_KONFIG,           VT_ENUM,          5970,  STR5970_2,sizeof(ENUM5970_2),   ENUM5970_2,   DEFAULT_FLAG, DEV_195_ALL}, // [0] - Konfiguration - Funktion Kontakt H4
{0x2E3D3073,  CAT_KONFIG,           VT_ENUM,          5971,  STR5971,  sizeof(ENUM5971),     ENUM5971,     DEFAULT_FLAG, DEV_ALL}, // Thision 5971 Konfig Raumthermostat 2 [enum: s.o.]
{0x053D0DCD,  CAT_KONFIG,           VT_ENUM,          5971,  STR5971_2,sizeof(ENUM5971_2),   ENUM5971_2,   DEFAULT_FLAG, DEV_123_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H4
{0x053D0DCD,  CAT_KONFIG,           VT_ENUM,          5971,  STR5971_2,sizeof(ENUM5971_2),   ENUM5971_2,   DEFAULT_FLAG, DEV_162_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H4
{0x053D0DCD,  CAT_KONFIG,           VT_ENUM,          5971,  STR5971_2,sizeof(ENUM5971_2),   ENUM5971_2,   DEFAULT_FLAG, DEV_163_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H4
{0x053D0DCD,  CAT_KONFIG,           VT_ENUM,          5971,  STR5971_2,sizeof(ENUM5971_2),   ENUM5971_2,   DEFAULT_FLAG, DEV_195_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H4
{0x053D3046,  CAT_KONFIG,           VT_ENUM,          5973,  STR5973,  sizeof(ENUM5973),     ENUM5973,     DEFAULT_FLAG, DEV_ALL}, // Thision 5973 Funktion Eingang RelCl [enum]
{0x39050484,  CAT_KONFIG,           VT_ENUM,          5973,  STR5973,  sizeof(ENUM5973),     ENUM5973,     DEFAULT_FLAG, DEV_064_ALL}, // Thision 5973 Funktion Eingang RelCl [enum] - logged on OCI700 via LPB
{0x193D2FD2,  CAT_KONFIG,           VT_TEMP_WORD,     5975,  STR5975,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 5975 Ext. Vorlaufsollwert Maximum [°C?]
{0x153D2FD3,  CAT_KONFIG,           VT_PERCENT,       5976,  STR5976,  0,                    NULL,         DEFAULT_FLAG, DEV_098_ALL}, // WGB Pro EVO 15C Ext. Leistungsvorg. Schwelle [%]
{0x153D2FD3,  CAT_KONFIG,           VT_PERCENT,       5976,  STR5976,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // WGB Pro EVO 15C Ext. Leistungsvorg. Schwelle [%]
{0x053D0D97,  CAT_KONFIG,           VT_ENUM,          5977,  STR5977,  sizeof(ENUM5970_2),   ENUM5970_2,   DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Funktion Kontakt H5
{0x093D3054,  CAT_KONFIG,           VT_ENUM,          5978,  STR5978,  sizeof(ENUM5978),     ENUM5978,     DEFAULT_FLAG, DEV_ALL}, // Thision 5978 Funktion Eingang SolCl [enum]
{0x25050480,  CAT_KONFIG,           VT_ENUM,          5978,  STR5978,  sizeof(ENUM5978),     ENUM5978,     DEFAULT_FLAG, DEV_064_ALL}, // Thision 5978 Funktion Eingang SolCl [enum] - logged on OCU700 via LPB
{0x053D0DCE,  CAT_KONFIG,           VT_ENUM,          5978,  STR5978_2,sizeof(ENUM5978_2),   ENUM5978_2,   DEFAULT_FLAG, DEV_123_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H5
{0x053D0DCE,  CAT_KONFIG,           VT_ENUM,          5978,  STR5978_2,sizeof(ENUM5978_2),   ENUM5978_2,   DEFAULT_FLAG, DEV_162_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H5
{0x053D0DCE,  CAT_KONFIG,           VT_ENUM,          5978,  STR5978_2,sizeof(ENUM5978_2),   ENUM5978_2,   DEFAULT_FLAG, DEV_163_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H5
{0x053D0DCE,  CAT_KONFIG,           VT_ENUM,          5978,  STR5978_2,sizeof(ENUM5978_2),   ENUM5978_2,   DEFAULT_FLAG, DEV_195_ALL}, // [0] - Konfiguration - Wirksinn Kontakt H5
{0x053D09FD,  CAT_KONFIG,           VT_ENUM,          5980,  STR5980,  sizeof(ENUM5980),     ENUM5980,     DEFAULT_FLAG, DEV_ALL}, // Funktion Eingang EX1 //FUJITSU
{0x053D09FE,  CAT_KONFIG,           VT_ENUM,          5981,  STR5981,  sizeof(ENUM5981),     ENUM5981,     DEFAULT_FLAG, DEV_ALL}, // Wirksinn Eingang EX1 //FUJITSU
{0x053D07CE,  CAT_KONFIG,           VT_ENUM,          5982,  STR5982,  sizeof(ENUM5980),     ENUM5980,     DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Funktion Eingang EX2 //FUJITSU
{0x053D07D1,  CAT_KONFIG,           VT_ENUM,          5983,  STR5983,  sizeof(ENUM5983),     ENUM5983,     DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Wirksinn Eingang EX2
{CMD_UNKNOWN, CAT_KONFIG,           VT_ENUM,          5984,  STR5984,  sizeof(ENUM5984),     ENUM5984,     DEFAULT_FLAG, DEV_ALL}, // Funktion Eingang EX3
{0x053D0B7E,  CAT_KONFIG,           VT_ENUM,          5985,  STR5985,  sizeof(ENUM5985),     ENUM5985,     DEFAULT_FLAG, DEV_ALL}, // Wirksinn Eingang EX3 //FUJITSU
{CMD_UNKNOWN, CAT_KONFIG,           VT_ENUM,          5986,  STR5986,  sizeof(ENUM5986),     ENUM5986,     DEFAULT_FLAG, DEV_ALL}, // Funktion Eingang EX4
{0x053D0B7F,  CAT_KONFIG,           VT_ENUM,          5987,  STR5987,  sizeof(ENUM5987),     ENUM5987,     DEFAULT_FLAG, DEV_ALL}, // Wirksinn Eingang EX4
{CMD_UNKNOWN, CAT_KONFIG,           VT_ENUM,          5988,  STR5988,  sizeof(ENUM5988),     ENUM5988,     DEFAULT_FLAG, DEV_ALL}, // Funktion Eingang EX5
{0x053D0B80,  CAT_KONFIG,           VT_ENUM,          5989,  STR5989,  sizeof(ENUM5989),     ENUM5989,     DEFAULT_FLAG, DEV_ALL}, // Wirksinn Eingang EX5
{CMD_UNKNOWN, CAT_KONFIG,           VT_ENUM,          5990,  STR5990,  sizeof(ENUM5990),     ENUM5990,     DEFAULT_FLAG, DEV_ALL}, // Funktion Eingang EX6
{CMD_UNKNOWN, CAT_KONFIG,           VT_ENUM,          5992,  STR5992,  sizeof(ENUM5992),     ENUM5992,     DEFAULT_FLAG, DEV_ALL}, // Funktion Eingang EX7
{0x053D07CF,  CAT_KONFIG,           VT_ENUM,          6014,  STR6014,  sizeof(ENUM6014),     ENUM6014,     DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Funktion Mischergruppe 1
{0x053D07D0,  CAT_KONFIG,           VT_ENUM,          6015,  STR6015,  sizeof(ENUM6015),     ENUM6015,     DEFAULT_FLAG, DEV_ALL}, // Funktion Mischergruppe 2
{0x053D0788,  CAT_KONFIG,           VT_ENUM,          6020,  STR6020,  sizeof(ENUM6020),     ENUM6020,     DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Funktion Erweiterungsmodul 1
{0x053D0789,  CAT_KONFIG,           VT_ENUM,          6021,  STR6021,  sizeof(ENUM6021),     ENUM6021,     DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Funktion Erweiterungsmodul 2
{0x053D0785,  CAT_KONFIG,           VT_ENUM,          6030,  STR6030,  sizeof(ENUM6030),     ENUM6030,     DEFAULT_FLAG, DEV_ALL}, // Relaisausgang QX21
{0x053D0D52,  CAT_KONFIG,           VT_ENUM,          6030,  STR6030,  sizeof(ENUM6030),     ENUM6030,     DEFAULT_FLAG, DEV_096_ALL}, // Relaisausgang QX21
{0x053D0D52,  CAT_KONFIG,           VT_ENUM,          6030,  STR6030,  sizeof(ENUM6030),     ENUM6030,     DEFAULT_FLAG, DEV_108_ALL}, // Relaisausgang QX21
{0x053D0D52,  CAT_KONFIG,           VT_ENUM,          6030,  STR6030,  sizeof(ENUM6030),     ENUM6030,     DEFAULT_FLAG, DEV_123_ALL}, // Relaisausgang QX21
{0x053D0D52,  CAT_KONFIG,           VT_ENUM,          6030,  STR6030,  sizeof(ENUM6030),     ENUM6030,     DEFAULT_FLAG, DEV_162_ALL}, // Relaisausgang QX21
{0x053D0D52,  CAT_KONFIG,           VT_ENUM,          6030,  STR6030,  sizeof(ENUM6030),     ENUM6030,     DEFAULT_FLAG, DEV_163_ALL}, // Relaisausgang QX21
{0x053D0D52,  CAT_KONFIG,           VT_ENUM,          6030,  STR6030,  sizeof(ENUM6030),     ENUM6030,     DEFAULT_FLAG, DEV_195_ALL}, // Relaisausgang QX21
{0x053D0D52,  CAT_KONFIG,           VT_ENUM,          6030,  STR6030,  sizeof(ENUM6030),     ENUM6030,     DEFAULT_FLAG, DEV_205_ALL}, // Relaisausgang QX21
{0x053D0D52,  CAT_KONFIG,           VT_ENUM,          6030,  STR6030,  sizeof(ENUM6030),     ENUM6030,     DEFAULT_FLAG, DEV_211_ALL}, // Relaisausgang QX21
{0x053D0786,  CAT_KONFIG,           VT_ENUM,          6031,  STR6031,  sizeof(ENUM6031),     ENUM6031,     DEFAULT_FLAG, DEV_ALL}, // Relaisausgang QX22
{0x053D0D53,  CAT_KONFIG,           VT_ENUM,          6031,  STR6031,  sizeof(ENUM6031),     ENUM6031,     DEFAULT_FLAG, DEV_098_ALL}, // Relaisausgang QX22
{0x053D0D53,  CAT_KONFIG,           VT_ENUM,          6031,  STR6031,  sizeof(ENUM6031),     ENUM6031,     DEFAULT_FLAG, DEV_108_ALL}, // Relaisausgang QX22
{0x053D0D53,  CAT_KONFIG,           VT_ENUM,          6031,  STR6031,  sizeof(ENUM6031),     ENUM6031,     DEFAULT_FLAG, DEV_123_ALL}, // Relaisausgang QX22
{0x053D0D53,  CAT_KONFIG,           VT_ENUM,          6031,  STR6031,  sizeof(ENUM6031),     ENUM6031,     DEFAULT_FLAG, DEV_162_ALL}, // Relaisausgang QX22
{0x053D0D53,  CAT_KONFIG,           VT_ENUM,          6031,  STR6031,  sizeof(ENUM6031),     ENUM6031,     DEFAULT_FLAG, DEV_163_ALL}, // Relaisausgang QX22
{0x053D0D53,  CAT_KONFIG,           VT_ENUM,          6031,  STR6031,  sizeof(ENUM6031),     ENUM6031,     DEFAULT_FLAG, DEV_195_ALL}, // Relaisausgang QX22
{0x053D0D53,  CAT_KONFIG,           VT_ENUM,          6031,  STR6031,  sizeof(ENUM6031),     ENUM6031,     DEFAULT_FLAG, DEV_205_ALL}, // Relaisausgang QX22
{0x053D0D53,  CAT_KONFIG,           VT_ENUM,          6031,  STR6031,  sizeof(ENUM6031),     ENUM6031,     DEFAULT_FLAG, DEV_211_ALL}, // Relaisausgang QX22
{0x053D0787,  CAT_KONFIG,           VT_ENUM,          6032,  STR6032,  sizeof(ENUM6032),     ENUM6032,     DEFAULT_FLAG, DEV_ALL}, // Relaisausgang QX23
{0x053D0D54,  CAT_KONFIG,           VT_ENUM,          6032,  STR6032,  sizeof(ENUM6032),     ENUM6032,     DEFAULT_FLAG, DEV_096_ALL}, // Relaisausgang QX23
{0x053D0D54,  CAT_KONFIG,           VT_ENUM,          6032,  STR6032,  sizeof(ENUM6032),     ENUM6032,     DEFAULT_FLAG, DEV_108_ALL}, // Relaisausgang QX23
{0x053D0D54,  CAT_KONFIG,           VT_ENUM,          6032,  STR6032,  sizeof(ENUM6032),     ENUM6032,     DEFAULT_FLAG, DEV_123_ALL}, // Relaisausgang QX23
{0x053D0D54,  CAT_KONFIG,           VT_ENUM,          6032,  STR6032,  sizeof(ENUM6032),     ENUM6032,     DEFAULT_FLAG, DEV_162_ALL}, // Relaisausgang QX23
{0x053D0D54,  CAT_KONFIG,           VT_ENUM,          6032,  STR6032,  sizeof(ENUM6032),     ENUM6032,     DEFAULT_FLAG, DEV_163_ALL}, // Relaisausgang QX23
{0x053D0D54,  CAT_KONFIG,           VT_ENUM,          6032,  STR6032,  sizeof(ENUM6032),     ENUM6032,     DEFAULT_FLAG, DEV_195_ALL}, // Relaisausgang QX23
{0x053D0D54,  CAT_KONFIG,           VT_ENUM,          6032,  STR6032,  sizeof(ENUM6032),     ENUM6032,     DEFAULT_FLAG, DEV_205_ALL}, // Relaisausgang QX23
{0x053D0D54,  CAT_KONFIG,           VT_ENUM,          6032,  STR6032,  sizeof(ENUM6032),     ENUM6032,     DEFAULT_FLAG, DEV_211_ALL}, // Relaisausgang QX23
// {CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6033,  STR6033,  sizeof(ENUM6033),     ENUM6033,     DEFAULT_FLAG, DEV_ALL},              // Relaisausgang QX21 Modul 2
// {CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6034,  STR6034,  sizeof(ENUM6034),     ENUM6034,     DEFAULT_FLAG, DEV_ALL},              // Relaisausgang QX22 Modul 2
// {CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6035,  STR6035,  sizeof(ENUM6035),     ENUM6035,     DEFAULT_FLAG, DEV_ALL},              // Relaisausgang QX23 Modul 2
// !FIXME! !AUTOGENERATED! same cmd as 5941
{0x053D077F,  CAT_KONFIG,           VT_ENUM,          6040,  STR6040,  sizeof(ENUM6040),     ENUM6040,     DEFAULT_FLAG, DEV_ALL}, // Fühlereingang BX21 Modul 1
// !FIXME! !AUTOGENERATED! same cmd as 5942
{0x053D0784,  CAT_KONFIG,           VT_ENUM,          6041,  STR6041,  sizeof(ENUM6041),     ENUM6041,     DEFAULT_FLAG, DEV_ALL}, // Fühlereingang BX22 Modul 1
// {CMD_UNKNOWN, CAT_KONFIG,           VT_ENUM,          6042,  STR6042,  sizeof(ENUM6042),     ENUM6042,     DEFAULT_FLAG, DEV_ALL}, // Fühlereingang BX21 Modul 2
// {CMD_UNKNOWN, CAT_KONFIG,           VT_ENUM,          6043,  STR6043,  sizeof(ENUM6043),     ENUM6043,     DEFAULT_FLAG, DEV_ALL}, // Fühlereingang BX22 Modul 2
{0x063D0807,  CAT_KONFIG,           VT_ENUM,          6046,  STR6046,  sizeof(ENUM6046),     ENUM6046,     DEFAULT_FLAG, DEV_ALL}, // Funktion Eingang H2
{0x053D0D92,  CAT_KONFIG,           VT_ENUM,          6046,  STR6046,  sizeof(ENUM6046),     ENUM6046,     DEFAULT_FLAG, DEV_108_ALL}, // Funktion Eingang H2
{0x053D0D92,  CAT_KONFIG,           VT_ENUM,          6046,  STR6046,  sizeof(ENUM6046),     ENUM6046,     FL_NO_CMD,    DEV_123_ALL}, // Funktion Eingang H2
{0x053D0D92,  CAT_KONFIG,           VT_ENUM,          6046,  STR6046,  sizeof(ENUM6046),     ENUM6046,     DEFAULT_FLAG, DEV_162_ALL}, // Funktion Eingang H2
{0x053D0D92,  CAT_KONFIG,           VT_ENUM,          6046,  STR6046,  sizeof(ENUM6046),     ENUM6046,     DEFAULT_FLAG, DEV_163_ALL}, // Funktion Eingang H2
{0x053D0D92,  CAT_KONFIG,           VT_ENUM,          6046,  STR6046,  sizeof(ENUM6046),     ENUM6046,     DEFAULT_FLAG, DEV_195_ALL}, // Funktion Eingang H2
{0x053D0D92,  CAT_KONFIG,           VT_ENUM,          6046,  STR6046,  sizeof(ENUM6046),     ENUM6046,     DEFAULT_FLAG, DEV_205_ALL}, // Funktion Eingang H2
{0x053D0D92,  CAT_KONFIG,           VT_ENUM,          6046,  STR6046,  sizeof(ENUM6046),     ENUM6046,     DEFAULT_FLAG, DEV_211_ALL}, // Funktion Eingang H2
{0x063D0700,  CAT_KONFIG,           VT_ENUM,          6046,  STR6046,  sizeof(ENUM6046_2),   ENUM6046_2,   DEFAULT_FLAG, DEV_119_ALL}, // Funktion Eingang H2
{0x063D0808,  CAT_KONFIG,           VT_ENUM,          6047,  STR6047,  sizeof(ENUM6047),     ENUM6047,     DEFAULT_FLAG, DEV_ALL}, // Wirksinn Kontakt H2 | Arbeitskontakt
{0x053D0DC9,  CAT_KONFIG,           VT_ENUM,          6047,  STR6047,  sizeof(ENUM6047),     ENUM6047,     DEFAULT_FLAG, DEV_108_ALL}, // Wirksinn Kontakt H2 | Arbeitskontakt
{0x053D0DC9,  CAT_KONFIG,           VT_ENUM,          6047,  STR6047,  sizeof(ENUM6047),     ENUM6047,     DEFAULT_FLAG, DEV_123_ALL}, // Wirksinn Kontakt H2 | Arbeitskontakt
{0x053D0DC9,  CAT_KONFIG,           VT_ENUM,          6047,  STR6047,  sizeof(ENUM6047),     ENUM6047,     DEFAULT_FLAG, DEV_162_ALL}, // Wirksinn Kontakt H2 | Arbeitskontakt
{0x053D0DC9,  CAT_KONFIG,           VT_ENUM,          6047,  STR6047,  sizeof(ENUM6047),     ENUM6047,     DEFAULT_FLAG, DEV_163_ALL}, // Wirksinn Kontakt H2 | Arbeitskontakt
{0x053D0DC9,  CAT_KONFIG,           VT_ENUM,          6047,  STR6047,  sizeof(ENUM6047),     ENUM6047,     DEFAULT_FLAG, DEV_195_ALL}, // Wirksinn Kontakt H2 | Arbeitskontakt
{0x053D0DC9,  CAT_KONFIG,           VT_ENUM,          6047,  STR6047,  sizeof(ENUM6047),     ENUM6047,     DEFAULT_FLAG, DEV_205_ALL}, // Wirksinn Kontakt H2 | Arbeitskontakt
{0x053D0DC9,  CAT_KONFIG,           VT_ENUM,          6047,  STR6047,  sizeof(ENUM6047),     ENUM6047,     DEFAULT_FLAG, DEV_211_ALL}, // Wirksinn Kontakt H2 | Arbeitskontakt
// !FIXME! !AUTOGENERATED! same cmd as 5962
{0x2A3D0656,  CAT_KONFIG,           VT_TEMP,          6048,  STR6048,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Minimaler Vorlaufsollwert H2
{0x2A3D0656,  CAT_KONFIG,           VT_TEMP,          6048,  STR6048_2,0,                    NULL,         DEFAULT_FLAG, DEV_119_ALL}, // Funktionswert Kontakt H2
{0x063D0B7B,  CAT_KONFIG,           VT_VOLTAGE,       6049,  STR6049,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Spannungswert 1 H2
// !FIXME! !AUTOGENERATED! same cmd as 5964
{0x063D079F,  CAT_KONFIG,           VT_TEMP,          6050,  STR6050,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Temperaturwert 10V H2
{0x063D0B7D,  CAT_KONFIG,           VT_UNKNOWN,       6050,  STR6050_2,0,                    NULL,         DEFAULT_FLAG, DEV_103_ALL}, // Funktionswert 1 H2
{0x063D0B7D,  CAT_KONFIG,           VT_UNKNOWN,       6050,  STR6050_2,0,                    NULL,         DEFAULT_FLAG, DEV_107_ALL}, // Funktionswert 1 H2
{0x063D0B7D,  CAT_KONFIG,           VT_UNKNOWN,       6050,  STR6050_2,0,                    NULL,         DEFAULT_FLAG, DEV_108_ALL}, // Funktionswert 1 H2
{0x063D0B7D,  CAT_KONFIG,           VT_UNKNOWN,       6050,  STR6050_2,0,                    NULL,         DEFAULT_FLAG, DEV_119_ALL}, // Funktionswert 1 H2
{0x063D0B7D,  CAT_KONFIG,           VT_UNKNOWN,       6050,  STR6050_2,0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Funktionswert 1 H2
{0x063D0B7D,  CAT_KONFIG,           VT_UNKNOWN,       6050,  STR6050_2,0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Funktionswert 1 H2
{0x063D0B7D,  CAT_KONFIG,           VT_UNKNOWN,       6050,  STR6050_2,0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Funktionswert 1 H2
{0x063D0B7D,  CAT_KONFIG,           VT_UNKNOWN,       6050,  STR6050_2,0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Funktionswert 1 H2
{0x063D0B7D,  CAT_KONFIG,           VT_UNKNOWN,       6050,  STR6050_2,0,                    NULL,         DEFAULT_FLAG, DEV_205_ALL}, // Funktionswert 1 H2
{0x063D0B7D,  CAT_KONFIG,           VT_UNKNOWN,       6050,  STR6050_2,0,                    NULL,         DEFAULT_FLAG, DEV_211_ALL}, // Funktionswert 1 H2
{0x063D0B7C,  CAT_KONFIG,           VT_VOLTAGE,       6051,  STR6051,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Spannungswert 2 H2
{0x063D0B83,  CAT_KONFIG,           VT_UNKNOWN,       6052,  STR6052,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Funktionswert 2 H2 BAR
{0x053D045A,  CAT_KONFIG,           VT_ENUM,          6070,  STR6070,  sizeof(ENUM6070),     ENUM6070,     DEFAULT_FLAG, DEV_ALL}, // Funktion Ausgang UX
{0x053D045B,  CAT_KONFIG,           VT_ENUM,          6071,  STR6071,  sizeof(ENUM6071),     ENUM6071,     DEFAULT_FLAG, DEV_ALL}, // Signallogik Ausgang UX Standard | Invertiert
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6072,  STR6072,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Signal Ausgang UX
{0x053D042B,  CAT_KONFIG,           VT_TEMP,          6075,  STR6075,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Temperaturwert 10V UX
{0x053D04A0,  CAT_KONFIG,           VT_ENUM,          6085,  STR6085,  sizeof(ENUM6085),     ENUM6085,     DEFAULT_FLAG, DEV_ALL}, // PWM-Ausgang P1
{0x113D2F97,  CAT_KONFIG,           VT_BYTE,          6089,  STR6089,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 6089 Mod Pumpe Drehzahlstufen [?]
{0x113D2FE1,  CAT_KONFIG,           VT_PERCENT,       6092,  STR6092,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 6092 Mod Pumpe PWM [?]
{0x053D075D,  CAT_KONFIG,           VT_ENUM,          6097,  STR6097,  sizeof(ENUM6097),     ENUM6097,     DEFAULT_FLAG, DEV_ALL}, // Fühlertyp Kollektor NTC|PT1000
{0x053D08B6,  CAT_KONFIG,           VT_TEMP,          6098,  STR6098,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Korrektur Kollektorfühler
{0x053D08B7,  CAT_KONFIG,           VT_TEMP,          6099,  STR6099,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Korrektur Kollektorfühler 2
{0x053D05F1,  CAT_KONFIG,           VT_TEMP,          6100,  STR6100,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [°C ] - Konfiguration - korrektur Aussenfühler
{0x053D08E6,  CAT_KONFIG,           VT_ENUM,          6101,  STR6101,  sizeof(ENUM6101),     ENUM6101,     DEFAULT_FLAG, DEV_ALL}, // Fühlertyp Abgastemperatur NTC | PT1000
{0x053D08E7,  CAT_KONFIG,           VT_TEMP,          6102,  STR6102,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Korrektur Abgastemp'fühler
{0x053D0600,  CAT_KONFIG,           VT_HOURS_SHORT,   6110,  STR6110,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [h ] - Konfiguration - Zeitkonstante Gebaeude
{0x2D3D05E7,  CAT_KONFIG,           VT_GRADIENT,      6112,  STR6112,  0,                    NULL,         FL_OEM, DEV_ALL}, // Thision 6112 Gradient Raummodell [min/K]
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6116,  STR6116,  0,                    NULL,         FL_OEM, DEV_ALL}, // Zeitkonstante Sollw’führung
{0x053D0855,  CAT_KONFIG,           VT_TEMP,          6117,  STR6117,  0,                    NULL,         FL_OEM, DEV_ALL}, // Zentrale Sollwertfuehrung //FUJITSU
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6118,  STR6118,  0,                    NULL,         FL_OEM, DEV_ALL}, // Sollwertabfall Verzögerung
{0x053D05FE,  CAT_KONFIG,           VT_ONOFF,         6120,  STR6120,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Anlagenfrostschutz
{0x113D2FB4,  CAT_KONFIG,           VT_SECONDS_SHORT, 6127,  STR6127,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pumpen/Ventilkick Dauer
{0x053D0B5C,  CAT_KONFIG,           VT_TEMP,          6128,  STR6128,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Wärm'anfo unter Außentemp
{0x053D0B5B,  CAT_KONFIG,           VT_TEMP,          6129,  STR6129,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Wärm'anfo über Außentemp
{0x293D07C6,  CAT_KONFIG,           VT_YESNO,         6130,  STR6130,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // H1 mit Pufferspeicher
{0x053D0D17,  CAT_KONFIG,           VT_ENUM,          6131,  STR6131,  sizeof(ENUM6131),     ENUM6131,     DEFAULT_FLAG, DEV_ALL}, // Wärm'anfo bei Ökobetrieb AUS| EIN Trinkwasser | ein
{0x2A3D07C6,  CAT_KONFIG,           VT_YESNO,         6134,  STR6134,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // H2 mit Pufferspeicher
{0x053D0D26,  CAT_KONFIG,           VT_ONOFF,         6135,  STR6135,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Luftentfeuchter
{0x053D0D25,  CAT_KONFIG,           VT_ENUM,          6136,  STR6136,  sizeof(ENUM6136),     ENUM6136,     DEFAULT_FLAG, DEV_ALL}, // Luftentfeuchter Freigabe
{0x053D0D23,  CAT_KONFIG,           VT_PERCENT,       6137,  STR6137,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Luftentfeuchter r. F. EIN
{0x053D0D24,  CAT_KONFIG,           VT_PERCENT,       6138,  STR6138,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Luftentfeuchter r. F. SD
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6140,  STR6140,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Wasserdruck Maximum
{0x053D05D9,  CAT_KONFIG,           VT_PRESSURE,      6141,  STR6141,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Wasserdruck minimum
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6142,  STR6142,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Wasserdruck kritisch Min
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6150,  STR6150,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Wasserdruck 2 Maximum
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6151,  STR6151,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Wasserdruck 2 Minimum
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6152,  STR6152,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Wasserdruck 2 kritisch Min
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6180,  STR6180,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Wasserdruck 3 Maximum
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6181,  STR6181,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Wasserdruck 3 Minimum
{CMD_UNKNOWN, CAT_KONFIG,           VT_UNKNOWN,       6182,  STR6182,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Wasserdruck 3 kritisch Min
{0x053D06AB,  CAT_KONFIG,           VT_YESNO,         6200,  STR6200,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Fühler Speichern
{0x053D0BBF,  CAT_KONFIG,           VT_YESNO,         6201,  STR6201,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Fühler löschen //FUJITSU
{0x053D05D4,  CAT_KONFIG,           VT_YESNO,         6204,  STR6204,  0,                    NULL,         FL_OEM, DEV_ALL}, // [-] - Konfiguration - Parameter speichern
{0x053D05D5,  CAT_KONFIG,           VT_YESNO,         6205,  STR6205,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [-] - Konfiguration - Parameter zurücksetzen
{0x053D0BD0,  CAT_KONFIG,           VT_DWORD,         6212,  STR6212,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Kontrollnummer Erzeuger 1
{0x053D0BD1,  CAT_KONFIG,           VT_DWORD,         6213,  STR6213,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Kontrollnummer Erzeuger 2
{0x053D0BD2,  CAT_KONFIG,           VT_DWORD,         6215,  STR6215,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Kontrollnummer Speicher
// # !FIXME! ProgNr 6217 is listed as 0x053D0BD2 in Python project
{0x053D0BD3,  CAT_KONFIG,           VT_DWORD,         6217,  STR6217,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Kontrollnummer Heizkreise
{0x053D000E,  CAT_KONFIG,           VT_FP1,           6220,  STR6220,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Konfiguration - Software- Version LOGON B
{0x093D3033,  CAT_KONFIG,           VT_BYTE,          6221,  STR6221,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 6221 Entwicklungs-Index [?]
{0x053D0011,  CAT_KONFIG,           VT_HOURS,         6222,  STR6222,  0,                    NULL,         FL_OEM, DEV_ALL}, // Gerätebetriebsstunden
{0x051A0000,  CAT_KONFIG,           VT_UNKNOWN,       6223,  STR6223,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Unbekannte Geräteabfrage
{0x053D0001,  CAT_KONFIG,           VT_STRING,        6224,  STR6224,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Geräte-Identifikation
{0x053D0002,  CAT_KONFIG,           VT_UINT,          6225,  STR6225,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 6225 Gerätefamilie [?]
{0x053D0003,  CAT_KONFIG,           VT_UINT,          6226,  STR6226,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 6226 Gerätevariante [?]
{0x053D0004,  CAT_KONFIG,           VT_FP1,           6227,  STR6227,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 6227 Objektverzeichnis-Version [?]
{0x05050064,  CAT_KONFIG,           VT_UNKNOWN,       6228,  STR6229,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Letzte vier Byte: Herstellernummer
{0x153D020A,  CAT_KONFIG,           VT_UNKNOWN,       6229,  STR6223,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 01 00 01 F4 / on LMU64: 00 01 1D 00 AA // regularly called by ACS700 diagnosis software
{0x153D2F9D,  CAT_KONFIG,           VT_BIT,           6230,  STR6230,  sizeof(ENUM6230),     ENUM6230,     DEFAULT_FLAG, DEV_ALL}, // KonfigRg0 Bit 0-7
{0x053D1193,  CAT_KONFIG,           VT_UINT,          6230,  STR6230_2,0,                    NULL,         FL_RONLY, DEV_162_ALL}, // Konfiguration - Info 1 OEM
{0x053D1193,  CAT_KONFIG,           VT_UINT,          6230,  STR6230_2,0,                    NULL,         FL_RONLY, DEV_123_ALL}, // Konfiguration - Info 1 OEM
{0x053D1195,  CAT_KONFIG,           VT_UINT,          6231,  STR6231,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Konfiguration - Info 2 OEM
{0x053D1770,  CAT_KONFIG,           VT_DWORD,         6232,  STR6232,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Zugangscode Inbetriebssetzung?
{0x053D1771,  CAT_KONFIG,           VT_DWORD,         6233,  STR6233,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Zugangscode Fachmannebene?
{0x053D1772,  CAT_KONFIG,           VT_DWORD,         6234,  STR6234,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Zugangscode OEM?
{0x053D1773,  CAT_KONFIG,           VT_DWORD,         6235,  STR6235,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Zugangscode OEM2?
{0x153D2F9E,  CAT_KONFIG,           VT_BIT,           6240,  STR6240,  sizeof(ENUM6240),     ENUM6240,     DEFAULT_FLAG, DEV_ALL}, // Thision 6240 KonfigRg1 Bit 0-7 [?]
{0x253D2F9F,  CAT_KONFIG,           VT_BIT,           6250,  STR6250,  sizeof(ENUM6250),     ENUM6250,     DEFAULT_FLAG, DEV_ALL}, // KonfigRg2 Bit 0-7
{0x153D3064,  CAT_KONFIG,           VT_BIT,           6260,  STR6260,  sizeof(ENUM6260),     ENUM6260,     DEFAULT_FLAG, DEV_ALL}, // KonfigRg3 Bit 0-7
{0x153D2FA1,  CAT_KONFIG,           VT_BIT,           6270,  STR6270,  sizeof(ENUM6270),     ENUM6270,     DEFAULT_FLAG, DEV_ALL}, // Thision 6270 KonfigRg4 Bit 0-7 [?]
{0x053D11E1,  CAT_KONFIG,           VT_TEMP,          6270,  STR6270_2,0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Überhitzschutztemperatur
{0x053D11E2,  CAT_KONFIG,           VT_TEMP,          6271,  STR6271,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Überhitzschutz Schaltdiff
{0x053D11E0,  CAT_KONFIG,           VT_ENUM,          6272,  STR6272,  sizeof(ENUM6272),     ENUM6272,     DEFAULT_FLAG, DEV_ALL}, // Überhitzschutzfühler
{0x053D11E3,  CAT_KONFIG,           VT_MINUTES_SHORT, 6273,  STR6273,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Überhitzschutz Dauer Min.
{0x153D2FA2,  CAT_KONFIG,           VT_BIT,           6280,  STR6280,  sizeof(ENUM6280),     ENUM6280,     DEFAULT_FLAG, DEV_ALL}, // KonfigRg3 Bit 0-7
{0x153D2FA3,  CAT_KONFIG,           VT_BIT,           6290,  STR6290,  sizeof(ENUM6290),     ENUM6290,     DEFAULT_FLAG, DEV_ALL}, // KonfigRg3 Bit 0-7
{0x153D2FA4,  CAT_KONFIG,           VT_BIT,           6300,  STR6300,  sizeof(ENUM6300),     ENUM6300,     DEFAULT_FLAG, DEV_ALL}, // Thision 6300 KonfigRg7 Bit 0-7 [?]
{0x313D2FB7,  CAT_KONFIG,           VT_BIT,           6310,  STR6310,  sizeof(ENUM6310),     ENUM6310,     DEFAULT_FLAG, DEV_ALL}, // Thision 6310 KonfigRg8 Bit 0-7 [?]
{0x0D3D3017,  CAT_KONFIG,           VT_BIT,           6330,  STR6330,  sizeof(ENUM6330),     ENUM6330,     DEFAULT_FLAG, DEV_ALL}, // Thision 6330 KonfigRg10 Bit 0-7 [?]
{0x053D1224,  CAT_KONFIG,           VT_ENUM,          6375,  STR6375,  sizeof(ENUM6375),     ENUM6375,     DEFAULT_FLAG, DEV_ALL}, // Relaisausgang QX35 //FUJITSU
{0x053D1264,  CAT_KONFIG,           VT_ENUM,          6420,  STR6420,  sizeof(ENUM6420),     ENUM6420,     DEFAULT_FLAG, DEV_ALL}, // Funktion Eingang H33 //FUJITSU
{0x053D1277,  CAT_KONFIG,           VT_ENUM,          6421,  STR6421,  sizeof(ENUM6421),     ENUM6421,     DEFAULT_FLAG, DEV_ALL}, // Wirksinn Kontakt H33 //FUJITSU
// Virtuelle Parameter aus der Kommunikation zwischen OCI700 und ZR1
{0x213D061E,  CAT_KONFIG,           VT_UNKNOWN,       6486,  STR6486,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Teilschema Heizkreis 1 (VT_BYTE)
{0x693D0A7A,  CAT_KONFIG,           VT_UNKNOWN,       6487,  STR6487,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Teilschema Kühlkreis 1 (VT_BYTE)
{0x223D061E,  CAT_KONFIG,           VT_UNKNOWN,       6488,  STR6488,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Teilschema Heizkreis 2 (VT_BYTE)
{0x233D061E,  CAT_KONFIG,           VT_UNKNOWN,       6489,  STR6489,  0,                    NULL,         FL_RONLY, DEV_064_ALL}, // Teilschema Heizkreis 3/P (VT_BYTE)
{0x053D061F,  CAT_KONFIG,           VT_UNKNOWN,       6489,  STR6489,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 // Teilschema Heizkreis 3/P
{0x253D0620,  CAT_KONFIG,           VT_UNKNOWN,       6490,  STR6490,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Teilschema Trinkwasserspeicher (VT_BYTE)
{0x053D07C0,  CAT_KONFIG,           VT_UNKNOWN,       6491,  STR6491,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Teilschema Umformer (VT_BYTE)
{0x053D080B,  CAT_KONFIG,           VT_UNKNOWN,       6492,  STR6492,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Teilschema H1 (Ja/Nein)
{0x063D080B,  CAT_KONFIG,           VT_UNKNOWN,       6493,  STR6493,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Teilschema H2 (Ja/Nein)
{0x513D061B,  CAT_KONFIG,           VT_UNKNOWN,       6494,  STR6494,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Teilschema Feststoffkessel
{0x113D061C,  CAT_KONFIG,           VT_UNKNOWN,       6495,  STR6495,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 02 // Teilschema Oel-/Gasheizkessel
{0x053D082A,  CAT_KONFIG,           VT_UNKNOWN,       6496,  STR6496,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Teilschema Schwimmbad
{0x313D0B14,  CAT_KONFIG,           VT_UNKNOWN,       6497,  STR6497,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Teilschema Trinkwasser Durchlauferhitzer
{0x493D061D,  CAT_KONFIG,           VT_UNKNOWN,       6498,  STR6498,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 // Teilschema Sonnenkollektor

// LPB-System
{0x053D00C9,  CAT_LPB,              VT_BYTE,          6600,  STR6600,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - LPB - Geraeteadresse
{0x0505000C,  CAT_LPB,              VT_BYTE,          6600,  STR6600,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - LPB - Geraeteadresse
{0x0505000C,  CAT_LPB,              VT_BYTE,          6600,  STR6600,  0,                    NULL,         DEFAULT_FLAG, DEV_076_ALL}, // [0] - LPB - Geraeteadresse
{0x0505000C,  CAT_LPB,              VT_BYTE,          6600,  STR6600,  0,                    NULL,         DEFAULT_FLAG, DEV_090_ALL}, // [0] - LPB - Geraeteadresse
{0x0505000C,  CAT_LPB,              VT_BYTE,          6600,  STR6600,  0,                    NULL,         DEFAULT_FLAG, DEV_097_100}, // [0] - LPB - Geraeteadresse
{0x053D00CA,  CAT_LPB,              VT_BYTE,          6601,  STR6601,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - LPB - Segmentadresse
{0x053D0071,  CAT_LPB,              VT_ENUM,          6604,  STR6604,  sizeof(ENUM6604),     ENUM6604,     DEFAULT_FLAG, DEV_ALL}, // [0] - LPB - Busspeisung Funktion
{0x053D0072,  CAT_LPB,              VT_ONOFF,         6605,  STR6605,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - LPB - Busspeisung Status
{0x053D3053,  CAT_LPB,              VT_BIT,           6606,  STR6606,  sizeof(ENUM6606),     ENUM6606,     DEFAULT_FLAG, DEV_ALL}, // Thision 6606 LPB-Konfig. 0 [?]
{0x053D006A,  CAT_LPB,              VT_YESNO,         6610,  STR6610,  0,                    NULL,         FL_OEM, DEV_ALL}, // [0] - LPB - Anzeige Systemmeldungen
{0x053D08D2,  CAT_LPB,              VT_MINUTES_SHORT, 6612,  STR6612,  0,                    NULL,         FL_OEM, DEV_ALL}, // Alarmverzögerung
{0x053D0839,  CAT_LPB,              VT_ENUM,          6620,  STR6620,  sizeof(ENUM6620),     ENUM6620,     DEFAULT_FLAG, DEV_ALL}, // [ - ] - LPB - Wirkbereich Umschaltungen
{0x2D3D0611,  CAT_LPB,              VT_ENUM,          6621,  STR6621,  sizeof(ENUM6621),     ENUM6621,     DEFAULT_FLAG, DEV_ALL}, // [0] - LPB - Sommerumschaltung
{0x053D0B34,  CAT_LPB,              VT_ENUM,          6623,  STR6623,  sizeof(ENUM6623),     ENUM6623,     DEFAULT_FLAG, DEV_ALL}, // Betriebsartumschaltung
{0x05050A86,  CAT_LPB,              VT_ENUM,          6624,  STR6624,  sizeof(ENUM6624),     ENUM6624,     DEFAULT_FLAG, DEV_ALL}, // Manuelle Erzeugersperre
{0x053D0A86,  CAT_LPB,              VT_ENUM,          6624,  STR6624,  sizeof(ENUM6624),     ENUM6624,     DEFAULT_FLAG, DEV_138_ALL}, // Manuelle Erzeugersperre
{0x253D074A,  CAT_LPB,              VT_ENUM,          6625,  STR6625,  sizeof(ENUM6625),     ENUM6625,     DEFAULT_FLAG, DEV_ALL}, // [0] - LPB - Trinkwasserzuordnung
{0x053D0D04,  CAT_LPB,              VT_ENUM,          6627,  STR6627,  sizeof(ENUM6627),     ENUM6627,     DEFAULT_FLAG, DEV_ALL}, // Kälteanforderung
{CMD_UNKNOWN, CAT_LPB,              VT_ENUM,          6630,  STR6630,  sizeof(ENUM6630),     ENUM6630,     FL_OEM, DEV_ALL}, // LPB - Externe Erzeuger bei Ökobetrieb
{0x05050D18,  CAT_LPB,              VT_ENUM,          6631,  STR6631,  sizeof(ENUM6631),     ENUM6631,     DEFAULT_FLAG, DEV_ALL}, // LPB - Externe Erzeuger bei Ökobetrieb
{0x053D0D6F,  CAT_LPB,              VT_YESNO,         6632,  STR6632,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TA'grenze ext Erz beachten
{0x053D006D,  CAT_LPB,              VT_ENUM,          6640,  STR6640,  sizeof(ENUM6640),     ENUM6640,     DEFAULT_FLAG, DEV_ALL}, // [0] - LPB - Uhrbetrieb
// Codierung unklar: 15.01 -> HEIZ->DISP ANS 6650 Aussentemperatur Lieferant 00 F0 ??? 00.01 = 00 00 ???
{0x053D009F,  CAT_LPB,              VT_LPBADDR,       6650,  STR6650,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - LPB - Aussentemperatur Lieferant
{0x053D0082,  CAT_LPB,              VT_LPBADDR,       6650,  STR6650,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - LPB - Aussentemperatur Lieferant - logged on OCI700 via LPB
{0x053D0082,  CAT_LPB,              VT_LPBADDR,       6650,  STR6650,  0,                    NULL,         DEFAULT_FLAG, DEV_076_ALL}, // [0] - LPB - Aussentemperatur Lieferant
{0x413D000E,  CAT_LPB,              VT_FP1    ,       6699,  STR6699,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - LPB - Software Version Einschub

//Fehler
{0x053D009A,  CAT_FEHLER,           VT_UNKNOWN,       6700,  STR10200, 0,                    NULL,         FL_RONLY,     DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00 00 00 00 00 00 00 00 00 00 / same on RVS43.222 // bytes 4 and 5 same as 053D000B, probably error log with some kind of date, error number and error origin (VT_LPBADDR)
{0x053D006B,  CAT_FEHLER,           VT_UNKNOWN,       6701,  STR10200, 0,                    NULL,         FL_RONLY,     DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222 // first byte error code, second byte FA Phase?
{0x053D0099,  CAT_FEHLER,           VT_ERRORCODE,     6705,  STR6705,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision 6705 SW Diagnosecode [VT_ERRORCODE?]
{0x093D3008,  CAT_FEHLER,           VT_ERRORCODE,     6705,  STR6705,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // Thision 6705 SW Diagnosecode [VT_ERRORCODE?] - logged on OCU700 via LPB
{0x093D3072,  CAT_FEHLER,           VT_BYTE,          6706,  STR6706,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision 6705 FA Phase Störstellung - mapped to parameter 6706 according to Brötje manual
{0x053D3072,  CAT_FEHLER,           VT_BYTE,          6706,  STR6706,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // Thision 6705 FA Phase Störstellung - mapped to parameter 6706 according to Brötje manual
{0x053D3072,  CAT_FEHLER,           VT_BYTE,          6706,  STR6706,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // Thision 6705 FA Phase Störstellung - mapped to parameter 6706 according to Brötje manual
{0x053D3072,  CAT_FEHLER,           VT_BYTE,          6706,  STR6706,  0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // Thision 6705 FA Phase Störstellung - mapped to parameter 6706 according to Brötje manual
{0x053D3072,  CAT_FEHLER,           VT_BYTE,          6706,  STR6706,  0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // Thision 6705 FA Phase Störstellung - mapped to parameter 6706 according to Brötje manual
{0x053D05D6,  CAT_FEHLER,           VT_YESNO,         6710,  STR6710,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Fehler - Reset Alarmrelais
{0x593D06AC,  CAT_FEHLER,           VT_YESNO,         6711,  STR6711,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Reset Wärmepumpe //FUJITSU
{0x213D069D,  CAT_FEHLER,           VT_MINUTES_SHORT, 6740,  STR6740,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [min ] - Fehler - Vorlauftemperatur 1 Alarm
{0x213D069D,  CAT_FEHLER,           VT_MINUTES_WORD,  6740,  STR6740,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [min ] - Fehler - Vorlauftemperatur 1 Alarm - logged on OCI700 via LPB
{0x223D069D,  CAT_FEHLER,           VT_MINUTES_SHORT, 6741,  STR6741,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [min ] - Fehler - Vorlauftemperatur 2 Alarm
{0x223D069D,  CAT_FEHLER,           VT_MINUTES_WORD,  6741,  STR6741,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [min ] - Fehler - Vorlauftemperatur 2 Alarm - logged on OCI700 via LPB
{0x233D069D,  CAT_FEHLER,           VT_MINUTES_SHORT, 6742,  STR6742,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Vorlauftemperatur Heizkreis 3 Fehler
{0x113D05DE,  CAT_FEHLER,           VT_MINUTES_SHORT, 6743,  STR6743,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [min ] - Fehler - Kesseltemperatur Alarm
{0x25050B10,  CAT_FEHLER,           VT_HOURS_SHORT,   6745,  STR6745,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Trinkwasserladung Alarm
{0x253D0B10,  CAT_FEHLER,           VT_HOURS_SHORT,   6745,  STR6745,  0,                    NULL,         FL_RONLY,     DEV_138_ALL}, // Trinkwasserladung Alarm
{0x693D0B67,  CAT_FEHLER,           VT_MINUTES_SHORT, 6746,  STR6746,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Vorlauftemp Kühlen 1 Alarm
{0x053D06D3,  CAT_FEHLER,           VT_DATETIME,      6800,  STR6800,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 1 Datum/Zeit
{0x053D2FF1,  CAT_FEHLER,           VT_BYTE,          6800,  STR6800_2,0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [ ] - THISION: Fehler Historie 1 - logged on OCI700 via LPB
{0x053D2FF1,  CAT_FEHLER,           VT_BYTE,          6800,  STR6800_2,0,                    NULL,         FL_RONLY,     DEV_097_ALL}, // [ ] - THISION: Fehler Historie 1
{0x053D2FF1,  CAT_FEHLER,           VT_BYTE,          6800,  STR6800_2,0,                    NULL,         FL_RONLY,     DEV_098_ALL}, // [ ] - THISION: Fehler Historie 1
{0x053D0814,  CAT_FEHLER,           VT_ERRORCODE,     6801,  STR6801,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 1 Fehlercode
{0x053D06DD,  CAT_FEHLER,           VT_ENUM,          6801,  STR6801,  sizeof(ENUM_ERROR),   ENUM_ERROR,   FL_RONLY,     DEV_096_ALL}, // [ ] - Fehler - Historie 1 Fehlercode
{0x053D06DD,  CAT_FEHLER,           VT_BYTE,          6801,  STR6801_2,0,                    NULL,         FL_RONLY,     DEV_097_ALL}, // [ ] - THISION: Fehler Historie 1 Fehlermeldung (6800 on display, mapped to 6801)
{0x053D06D4,  CAT_FEHLER,           VT_DATETIME,      6802,  STR6802,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 2 Datum/Zeit
{0x053D06D4,  CAT_FEHLER,           VT_DATETIME,      6802,  STR6802,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 2 Datum/Zeit
{0x053D06D4,  CAT_FEHLER,           VT_DATETIME,      6802,  STR6802,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 2 Datum/Zeit
{0x053D0815,  CAT_FEHLER,           VT_ERRORCODE,     6803,  STR6803,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 2 Fehlercode
{0x31052FF4,  CAT_FEHLER,           VT_ERRORCODE,     6803,  STR6803_2,0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [ ] - Fehler - Historie 2 Fehlercode - logged on OCI700 via LPB
{0x053D0815,  CAT_FEHLER,           VT_ENUM,          6803,  STR6803,  sizeof(ENUM_ERROR),   ENUM_ERROR,   FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 2 Fehlercode
{0x053D06DE,  CAT_FEHLER,           VT_ENUM,          6803,  STR6803,  sizeof(ENUM_ERROR),   ENUM_ERROR,   FL_RONLY,     DEV_096_ALL}, // [ ] - Fehler - Historie 2 Fehlercode
{0x053D06D5,  CAT_FEHLER,           VT_DATETIME,      6804,  STR6804,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 3 Datum/Zeit
{0x053D06D5,  CAT_FEHLER,           VT_DATETIME,      6804,  STR6804,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 3 Datum/Zeit
{0x053D06D5,  CAT_FEHLER,           VT_DATETIME,      6804,  STR6804,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 3 Datum/Zeit
{0x053D06DF,  CAT_FEHLER,           VT_ENUM,          6805,  STR6805,  sizeof(ENUM_ERROR),   ENUM_ERROR,   FL_RONLY,     DEV_096_ALL}, // [ ] - Fehler - Historie 3 Fehlercode
{0x053D0816,  CAT_FEHLER,           VT_ERRORCODE,     6805,  STR6805,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 3 Fehlercode
{0x053D0816,  CAT_FEHLER,           VT_ERRORCODE,     6805,  STR6805,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 3 Fehlercode
{0x053D0816,  CAT_FEHLER,           VT_ERRORCODE,     6805,  STR6805,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 3 Fehlercode
{0x053D2FF3,  CAT_FEHLER,           VT_ERRORCODE,     6805,  STR6805_2,0,                    NULL,         FL_RONLY,     DEV_097_ALL}, // [ ] - THISION: Fehler SW Diagnosecode 1
{0x053D2FF3,  CAT_FEHLER,           VT_ERRORCODE,     6805,  STR6805_2,0,                    NULL,         FL_RONLY,     DEV_098_ALL}, // [ ] - THISION: Fehler SW Diagnosecode 1
{0x053D2FF3,  CAT_FEHLER,           VT_UINT,          6805,  STR6805_2,0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [ ] - Fehler SW Diagnosecode 1 - logged on OCI700 via LPB
{0x053D2FF3,  CAT_FEHLER,           VT_UINT,          6805,  STR6805_2,0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler SW Diagnosecode 1
{0x053D2FF3,  CAT_FEHLER,           VT_ERRORCODE,     6805,  STR6805_2,0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [ ] - THISION: Fehler SW Diagnosecode 1
{0x053D06D6,  CAT_FEHLER,           VT_DATETIME,      6806,  STR6806,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 4 Datum/Zeit
{0x053D06D6,  CAT_FEHLER,           VT_DATETIME,      6806,  STR6806,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 4 Datum/Zeit
{0x053D2FF2,  CAT_FEHLER,           VT_BYTE,          6806,  STR6806_2,0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [ ] - THISION: FA Phase 1 (6805 on display, mapped to 6806) - logged on OCI700 via LPB
{0x053D2FF2,  CAT_FEHLER,           VT_BYTE,          6806,  STR6806_2,0,                    NULL,         FL_RONLY,     DEV_097_ALL}, // [ ] - THISION: FA Phase 1 (6805 on display, mapped to 6806)
{0x053D2FF2,  CAT_FEHLER,           VT_BYTE,          6806,  STR6806_2,0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [ ] - THISION: FA Phase 1 (6805 on display, mapped to 6806)
{0x053D2FF2,  CAT_FEHLER,           VT_BYTE,          6806,  STR6806_2,0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - FA Phase 1
{0x053D0817,  CAT_FEHLER,           VT_ERRORCODE,     6807,  STR6807,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 4 Fehlercode
{0x053D06E0,  CAT_FEHLER,           VT_ENUM,          6807,  STR6807,  sizeof(ENUM_ERROR),   ENUM_ERROR,   FL_RONLY,     DEV_096_ALL}, // [ ] - Fehler - Historie 4 Fehlercode
{0x053D0817,  CAT_FEHLER,           VT_ERRORCODE,     6807,  STR6807,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 4 Fehlercode
{0x053D0817,  CAT_FEHLER,           VT_ERRORCODE,     6807,  STR6807,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 4 Fehlercode
{0x053D06D7,  CAT_FEHLER,           VT_DATETIME,      6808,  STR6808,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 5 Datum/Zeit
{0x053D06D7,  CAT_FEHLER,           VT_DATETIME,      6808,  STR6808,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 5 Datum/Zeit
{0x053D06D7,  CAT_FEHLER,           VT_DATETIME,      6808,  STR6808,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 5 Datum/Zeit
{0x053D0818,  CAT_FEHLER,           VT_ERRORCODE,     6809,  STR6809,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 5 Fehlercode
{0x053D06E1,  CAT_FEHLER,           VT_ENUM,          6809,  STR6809,  sizeof(ENUM_ERROR),   ENUM_ERROR,   FL_RONLY,     DEV_096_ALL}, // [ ] - Fehler - Historie 5 Fehlercode
{0x053D0818,  CAT_FEHLER,           VT_ERRORCODE,     6809,  STR6809,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 5 Fehlercode
{0x053D0818,  CAT_FEHLER,           VT_ERRORCODE,     6809,  STR6809,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 5 Fehlercode
{0x053D06D8,  CAT_FEHLER,           VT_DATETIME,      6810,  STR6810,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 6 Datum/Zeit
{0x053D06D8,  CAT_FEHLER,           VT_DATETIME,      6810,  STR6810,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 6 Datum/Zeit
{0x053D06D8,  CAT_FEHLER,           VT_DATETIME,      6810,  STR6810,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 6 Datum/Zeit
{0x053D06D4,  CAT_FEHLER,           VT_DATETIME,      6810,  STR6802,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler - Historie 2 Datum/Zeit
{0x053D06D4,  CAT_FEHLER,           VT_DATETIME,      6810,  STR6802,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [ ] - Fehler - Historie 2 Datum/Zeit
{0x053D2FF5,  CAT_FEHLER,           VT_BYTE,          6810,  STR6810_2,0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [ ] - THISION: Fehler Historie 2 - logged on OCI700 via LPB
{0x053D2FF5,  CAT_FEHLER,           VT_BYTE,          6810,  STR6810_2,0,                    NULL,         FL_RONLY,     DEV_097_ALL}, // [ ] - THISION: Fehler Historie 2
{0x053D2FF5,  CAT_FEHLER,           VT_BYTE,          6810,  STR6810_2,0,                    NULL,         FL_RONLY,     DEV_098_ALL}, // [ ] - THISION: Fehler Historie 2
{0x053D0819,  CAT_FEHLER,           VT_ERRORCODE,     6811,  STR6811,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 6 Fehlercode
{0x053D06E2,  CAT_FEHLER,           VT_ENUM,          6811,  STR6811,  sizeof(ENUM_ERROR),   ENUM_ERROR,   FL_RONLY,     DEV_096_ALL}, // [ ] - Fehler - Historie 6 Fehlercode
{0x053D06DE,  CAT_FEHLER,           VT_BYTE,          6811,  STR6811_2,0,                    NULL,         FL_RONLY,     DEV_097_ALL}, // [ ] - THISION: Fehlercode 2 (6810 on display, mapped to 6811)
{0x053D0815,  CAT_FEHLER,           VT_ERRORCODE,     6811,  STR6803,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler - Historie 2 Fehlercode
{0x053D0819,  CAT_FEHLER,           VT_ERRORCODE,     6811,  STR6811,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 6 Fehlercode
{0x053D0815,  CAT_FEHLER,           VT_ERRORCODE,     6811,  STR6803,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [ ] - Fehler - Historie 2 Fehlercode
{0x053D0819,  CAT_FEHLER,           VT_ERRORCODE,     6811,  STR6811,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [ ] - Fehler - Historie 6 Fehlercode
{0x053D06D9,  CAT_FEHLER,           VT_DATETIME,      6812,  STR6812,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 7 Datum/Zeit
{0x053D06D9,  CAT_FEHLER,           VT_DATETIME,      6812,  STR6812,  0,                    NULL,         FL_RONLY,     DEV_096_ALL}, // [ ] - Fehler - Historie 7 Datum/Zeit
{0x053D06D9,  CAT_FEHLER,           VT_DATETIME,      6812,  STR6812,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 7 Datum/Zeit
{0x053D06D9,  CAT_FEHLER,           VT_DATETIME,      6812,  STR6812,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 7 Datum/Zeit
{0x053D081A,  CAT_FEHLER,           VT_ERRORCODE,     6813,  STR6813,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 7 Fehlercode
{0x393D2FF8,  CAT_FEHLER,           VT_ERRORCODE,     6813,  STR6813_2,0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [ ] - Fehler - Historie 7 Fehlercode - logged on OCI700 via LPB
{0x053D06E3,  CAT_FEHLER,           VT_ENUM,          6813,  STR6813,  sizeof(ENUM_ERROR),   ENUM_ERROR,   FL_RONLY,     DEV_096_ALL}, // [ ] - Fehler - Historie 7 Fehlercode
{0x053D081A,  CAT_FEHLER,           VT_ERRORCODE,     6813,  STR6813,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 7 Fehlercode
{0x053D081A,  CAT_FEHLER,           VT_ERRORCODE,     6813,  STR6813,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 7 Fehlercode
{0x053D06DA,  CAT_FEHLER,           VT_DATETIME,      6814,  STR6814,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 8 Datum/Zeit
{0x053D06DA,  CAT_FEHLER,           VT_DATETIME,      6814,  STR6814,  0,                    NULL,         FL_RONLY,     DEV_096_ALL}, // [ ] - Fehler - Historie 8 Datum/Zeit
{0x053D06DA,  CAT_FEHLER,           VT_DATETIME,      6814,  STR6814,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 8 Datum/Zeit
{0x053D06DA,  CAT_FEHLER,           VT_DATETIME,      6814,  STR6814,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 8 Datum/Zeit
{0x053D081B,  CAT_FEHLER,           VT_ERRORCODE,     6815,  STR6815,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 8 Fehlercode
{0x053D06E4,  CAT_FEHLER,           VT_ENUM,          6815,  STR6815,  sizeof(ENUM_ERROR),   ENUM_ERROR,   FL_RONLY,     DEV_096_ALL}, // [ ] - Fehler - Historie 8 Fehlercode
{0x053D2FF7,  CAT_FEHLER,           VT_ERRORCODE,     6815,  STR6815_2,0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [ ] - THISION: Fehler Software Diagnosecode 2 - logged on OCI700 via LPB
{0x053D2FF7,  CAT_FEHLER,           VT_ERRORCODE,     6815,  STR6815_2,0,                    NULL,         FL_RONLY,     DEV_097_ALL}, // [ ] - THISION: Fehler Software Diagnosecode 2
{0x053D2FF7,  CAT_FEHLER,           VT_ERRORCODE,     6815,  STR6815_2,0,                    NULL,         FL_RONLY,     DEV_098_ALL}, // [ ] - THISION: Fehler Software Diagnosecode 2
{0x053D2FF7,  CAT_FEHLER,           VT_UINT,          6815,  STR6815_2,0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler Software Diagnosecode 2
{0x053D081B,  CAT_FEHLER,           VT_ERRORCODE,     6815,  STR6815,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 8 Fehlercode
{0x053D2FF7,  CAT_FEHLER,           VT_ERRORCODE,     6815,  STR6815_2,0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [ ] - THISION: Fehler Software Diagnosecode 2
{0x053D081B,  CAT_FEHLER,           VT_ERRORCODE,     6815,  STR6815,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 8 Fehlercode
{0x053D06DB,  CAT_FEHLER,           VT_DATETIME,      6816,  STR6816,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 9 Datum/Zeit
{0x053D06DB,  CAT_FEHLER,           VT_DATETIME,      6816,  STR6816,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 9 Datum/Zeit
{0x053D06DB,  CAT_FEHLER,           VT_DATETIME,      6816,  STR6816,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 9 Datum/Zeit
{0x053D2FF6,  CAT_FEHLER,           VT_BYTE,          6816,  STR6816_2,0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [ ] - THISION: FA Phase 2 (6815 on display, mapped to 6816) - logged on OCI700 via LPB
{0x053D2FF6,  CAT_FEHLER,           VT_BYTE,          6816,  STR6816_2,0,                    NULL,         FL_RONLY,     DEV_097_ALL}, // [ ] - THISION: FA Phase 2 (6815 on display, mapped to 6816)
{0x053D2FF6,  CAT_FEHLER,           VT_BYTE,          6816,  STR6816_2,0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - FA Phase 2
{0x053D2FF6,  CAT_FEHLER,           VT_BYTE,          6816,  STR6816_2,0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [ ] - THISION: FA Phase 2 (6815 on display, mapped to 6816)
{0x053D081C,  CAT_FEHLER,           VT_ERRORCODE,     6817,  STR6817,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 9 Fehlercode
{0x053D06E5,  CAT_FEHLER,           VT_ENUM,          6817,  STR6817,  sizeof(ENUM_ERROR),   ENUM_ERROR,   FL_RONLY,     DEV_096_ALL}, // [ ] - Fehler - Historie 9 Fehlercode
{0x053D081C,  CAT_FEHLER,           VT_ERRORCODE,     6817,  STR6817,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 9 Fehlercode
{0x053D081C,  CAT_FEHLER,           VT_ERRORCODE,     6817,  STR6817,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 9 Fehlercode
{0x053D06DC,  CAT_FEHLER,           VT_DATETIME,      6818,  STR6818,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 10 Datum/Zeit
{0x053D06DC,  CAT_FEHLER,           VT_DATETIME,      6818,  STR6818,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 10 Datum/Zeit
{0x053D06DC,  CAT_FEHLER,           VT_DATETIME,      6818,  STR6818,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 10 Datum/Zeit
{0x053D081D,  CAT_FEHLER,           VT_ERRORCODE,     6819,  STR6819,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 10 Fehlercode
{0x053D06E6,  CAT_FEHLER,           VT_ENUM,          6819,  STR6819,  sizeof(ENUM_ERROR),   ENUM_ERROR,   FL_RONLY,     DEV_096_ALL}, // [ ] - Fehler - Historie 10 Fehlercode
{0x053D081D,  CAT_FEHLER,           VT_ERRORCODE,     6819,  STR6819,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // [ ] - Fehler - Historie 10 Fehlercode
{0x053D081D,  CAT_FEHLER,           VT_ERRORCODE,     6819,  STR6819,  0,                    NULL,         FL_NO_CMD,    DEV_162_ALL}, // [ ] - Fehler - Historie 10 Fehlercode
// 3
{0x0D3D06E7,  CAT_FEHLER,           VT_YESNO,         6820,  STR6820,  0,                    NULL,         FL_OEM,       DEV_ALL}, // [ ] - Fehler - Reset Historie
{0x053D2FF9,  CAT_FEHLER,           VT_BYTE,          6820,  STR6820_2,0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [ ] - THISION: Fehler Historie 3 - logged on OCI700 via LPB
{0x053D2FF9,  CAT_FEHLER,           VT_BYTE,          6820,  STR6820_2,0,                    NULL,         FL_RONLY,     DEV_097_ALL}, // [ ] - THISION: Fehler Historie 3
{0x053D2FF9,  CAT_FEHLER,           VT_BYTE,          6820,  STR6820_2,0,                    NULL,         FL_RONLY,     DEV_098_ALL}, // [ ] - THISION: Fehler Historie 3
{0x053D06D5,  CAT_FEHLER,           VT_DATETIME,      6820,  STR6804,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler - Historie 3 Datum/Zeit
{0x053D06D5,  CAT_FEHLER,           VT_DATETIME,      6820,  STR6804,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [ ] - Fehler - Historie 3 Datum/Zeit
{0x053D06DF,  CAT_FEHLER,           VT_BYTE,          6821,  STR6821,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - THISION: Fehlercode 3 (6820 on display, mapped to 6821)
{0x053D0816,  CAT_FEHLER,           VT_ERRORCODE,     6821,  STR6805,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler - Historie 3 Fehlercode
{0x053D0816,  CAT_FEHLER,           VT_ERRORCODE,     6821,  STR6805,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [ ] - Fehler - Historie 3 Fehlercode
{0x393D2FFC,  CAT_FEHLER,           VT_ERRORCODE,     6823,  STR6823,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - 3. Vergangenheitswert Albatros Fehlercode - logged on OCI700 via LPB
{0x0D3D2FFC,  CAT_FEHLER,           VT_ERRORCODE,     6823,  STR6823_2,0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [ ] - Fehler - 3. Vergangenheitswert Albatros Fehlercode - logged on OCI700 via LPB
{0x053D2FFB,  CAT_FEHLER,           VT_ERRORCODE,     6825,  STR6825,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - THISION: Fehler Software Diagnosecode 3
{0x053D2FFB,  CAT_FEHLER,           VT_UINT,          6825,  STR6825,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler Software Diagnosecode 3
{0x053D2FFA,  CAT_FEHLER,           VT_BYTE,          6826,  STR6826,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - THISION: FA Phase 3 (6825 on display, mapped to 6826)
// 4
{0x053D2FFD,  CAT_FEHLER,           VT_BYTE,          6830,  STR6830,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - THISION: Fehler Historie 4
{0x053D06D6,  CAT_FEHLER,           VT_DATETIME,      6830,  STR6806,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler - Historie 4 Datum/Zeit
{0x053D06D6,  CAT_FEHLER,           VT_DATETIME,      6830,  STR6806,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [ ] - Fehler - Historie 4 Datum/Zeit
{0x053D06E0,  CAT_FEHLER,           VT_BYTE,          6831,  STR6831,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - THISION: Fehlercode 4 (6830 on display, mapped to 6831)
{0x053D0817,  CAT_FEHLER,           VT_ERRORCODE,     6831,  STR6807,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler - Historie 4 Fehlercode
{0x053D0817,  CAT_FEHLER,           VT_ERRORCODE,     6831,  STR6807,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [ ] - Fehler - Historie 4 Fehlercode
{0x113D3000,  CAT_FEHLER,           VT_ERRORCODE,     6833,  STR6833,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - 4. Vergangenheitswert Albatros Fehlercode - logged on OCI700 via LPB
{0x113D3000,  CAT_FEHLER,           VT_ERRORCODE,     6833,  STR6833_2,0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [ ] - Fehler - 4. Vergangenheitswert Albatros Fehlercode - logged on OCI700 via LPB
{0x053D2FFF,  CAT_FEHLER,           VT_ERRORCODE,     6835,  STR6835,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - THISION: Fehler Software Diagnosecode 4
{0x053D2FFF,  CAT_FEHLER,           VT_UINT,          6835,  STR6835,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler Software Diagnosecode 4
{0x053D2FFE,  CAT_FEHLER,           VT_BYTE,          6836,  STR6836,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - THISION: FA Phase 4 (6835 on display, mapped to 6836)
// 5
{0x053D3001,  CAT_FEHLER,           VT_BYTE,          6840,  STR6840,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - THISION: Fehler Historie 5
{0x053D3001,  CAT_FEHLER,           VT_BYTE,          6840,  STR6840_2,0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [ ] - THISION: Fehler Historie 5
{0x053D06D7,  CAT_FEHLER,           VT_DATETIME,      6840,  STR6840,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler Historie 5
{0x053D06D7,  CAT_FEHLER,           VT_DATETIME,      6840,  STR6840,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [ ] - THISION: Fehler Historie 5
{0x053D06E1,  CAT_FEHLER,           VT_BYTE,          6841,  STR6841,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - THISION: Fehlercode 5 (6840 on display, mapped to 6841)
{0x053D0818,  CAT_FEHLER,           VT_ERRORCODE,     6841,  STR6841,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler - Historie 5 Fehlercode
{0x053D0818,  CAT_FEHLER,           VT_ERRORCODE,     6841,  STR6841,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [ ] - THISION: Fehlercode 5 (6840 on display, mapped to 6841)
{0x15053004,  CAT_FEHLER,           VT_ERRORCODE,     6843,  STR6843,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - 5. Vergangenheitswert Albatros Fehlercode - logged on OCI700 via LPB
{0x15053004,  CAT_FEHLER,           VT_ERRORCODE,     6843,  STR6843_2,0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [ ] - Fehler - 5. Vergangenheitswert Albatros Fehlercode - logged on OCI700 via LPB
{0x053D3003,  CAT_FEHLER,           VT_ERRORCODE,     6845,  STR6845,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - THISION: Fehler Software Diagnosecode 5
{0x053D3003,  CAT_FEHLER,           VT_UINT,          6845,  STR6845,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler Software Diagnosecode 5
{0x053D3002,  CAT_FEHLER,           VT_BYTE,          6846,  STR6846,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - THISION: FA Phase 5 (6845 on display, mapped to 6846)
// 6
{0x053D06D8,  CAT_FEHLER,           VT_DATETIME,      6850,  STR6850,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Historie 6
{0x053D0819,  CAT_FEHLER,           VT_ERRORCODE,     6851,  STR6851,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Historie 6 Datum/Uhrzeit (6850 on display, mapped to 6851)
{0x053D3084,  CAT_FEHLER,           VT_ERRORCODE,     6855,  STR6855,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Software Diagnosecode 6
{0x053D3084,  CAT_FEHLER,           VT_UINT,          6855,  STR6855,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler Software Diagnosecode 6
{0x053D3093,  CAT_FEHLER,           VT_BYTE,          6856,  STR6856,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - FA Phase 6 (6855 on display, mapped to 6856)
// 7
{0x053D06D9,  CAT_FEHLER,           VT_DATETIME,      6860,  STR6860,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Historie 7
{0x053D081A,  CAT_FEHLER,           VT_ERRORCODE,     6861,  STR6861,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Historie 7 Datum/Uhrzeit (6860 on display, mapped to 6861)
{0x053D3085,  CAT_FEHLER,           VT_ERRORCODE,     6865,  STR6865,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Software Diagnosecode 7
{0x053D3085,  CAT_FEHLER,           VT_UINT,          6865,  STR6865,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler Software Diagnosecode 7
{0x053D3094,  CAT_FEHLER,           VT_BYTE,          6866,  STR6866,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - FA Phase 7 (6865 on display, mapped to 6866)
// 8
{0x053D06DA,  CAT_FEHLER,           VT_DATETIME,      6870,  STR6870,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Historie 8
{0x053D081B,  CAT_FEHLER,           VT_ERRORCODE,     6871,  STR6871,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Historie 8 Datum/Uhrzeit (6870 on display, mapped to 6871)
{0x053D3086,  CAT_FEHLER,           VT_ERRORCODE,     6875,  STR6875,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Software Diagnosecode 8
{0x053D3086,  CAT_FEHLER,           VT_UINT,          6875,  STR6875,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler Software Diagnosecode 8
{0x053D3095,  CAT_FEHLER,           VT_BYTE,          6876,  STR6876,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - FA Phase 8 (6875 on display, mapped to 6876)
// 9
{0x053D06DB,  CAT_FEHLER,           VT_DATETIME,      6880,  STR6880,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Historie 9
{0x053D081C,  CAT_FEHLER,           VT_ERRORCODE,     6881,  STR6881,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Historie 9 Datum/Uhrzeit (6880 on display, mapped to 6881)
{0x053D3087,  CAT_FEHLER,           VT_ERRORCODE,     6885,  STR6885,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Software Diagnosecode 9
{0x053D3087,  CAT_FEHLER,           VT_UINT,          6885,  STR6885,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler Software Diagnosecode 9
{0x053D3096,  CAT_FEHLER,           VT_BYTE,          6886,  STR6886,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - FA Phase 9 (6885 on display, mapped to 6886)
// 10
{0x053D06DC,  CAT_FEHLER,           VT_DATETIME,      6890,  STR6890,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Historie 10
{0x053D081D,  CAT_FEHLER,           VT_ERRORCODE,     6891,  STR6891,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Historie 10 Datum/Uhrzeit (6890 on display, mapped to 6891)
{0x053D3088,  CAT_FEHLER,           VT_ERRORCODE,     6895,  STR6895,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler Software Diagnosecode 10
{0x053D3088,  CAT_FEHLER,           VT_UINT,          6895,  STR6895,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [ ] - Fehler Software Diagnosecode 10
{0x053D3097,  CAT_FEHLER,           VT_BYTE,          6896,  STR6896,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - FA Phase 10 (6895 on display, mapped to 6896)
// 11
{0x053D30A2,  CAT_FEHLER,           VT_DATETIME,      6900,  STR6900,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 11 Datum/Zeit
{0x053D30AC,  CAT_FEHLER,           VT_ERRORCODE,     6901,  STR6901,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 11 Fehlercode
{0x053D3089,  CAT_FEHLER,           VT_UINT,          6905,  STR6905,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - SW Diagnosecode 11
{0x053D3098,  CAT_FEHLER,           VT_BYTE,          6906,  STR6906,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - FA Phase 11
// 12
{0x053D30A3,  CAT_FEHLER,           VT_DATETIME,      6910,  STR6910,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 12 Datum/Zeit
{0x053D30AD,  CAT_FEHLER,           VT_ERRORCODE,     6911,  STR6911,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 12 Fehlercode
{0x053D308A,  CAT_FEHLER,           VT_UINT,          6915,  STR6915,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - SW Diagnosecode 12
{0x053D3099,  CAT_FEHLER,           VT_BYTE,          6916,  STR6916,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - FA Phase 12
// 13
{0x053D30A4,  CAT_FEHLER,           VT_DATETIME,      6920,  STR6920,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 13 Datum/Zeit
{0x053D30AE,  CAT_FEHLER,           VT_ERRORCODE,     6921,  STR6921,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 13 Fehlercode
{0x053D308B,  CAT_FEHLER,           VT_UINT,          6925,  STR6925,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - SW Diagnosecode 13
{0x053D309A,  CAT_FEHLER,           VT_BYTE,          6926,  STR6926,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - FA Phase 13
// 14
{0x053D30A5,  CAT_FEHLER,           VT_DATETIME,      6930,  STR6930,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 14 Datum/Zeit
{0x053D30AF,  CAT_FEHLER,           VT_ERRORCODE,     6931,  STR6931,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 14 Fehlercode
{0x053D308C,  CAT_FEHLER,           VT_UINT,          6935,  STR6935,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - SW Diagnosecode 14
{0x053D309B,  CAT_FEHLER,           VT_BYTE,          6936,  STR6936,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - FA Phase 14
// 15
{0x053D30A6,  CAT_FEHLER,           VT_DATETIME,      6940,  STR6940,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 15 Datum/Zeit
{0x053D30B0,  CAT_FEHLER,           VT_ERRORCODE,     6941,  STR6941,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 15 Fehlercode
{0x053D308D,  CAT_FEHLER,           VT_UINT,          6945,  STR6945,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - SW Diagnosecode 15
{0x053D309C,  CAT_FEHLER,           VT_BYTE,          6946,  STR6946,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - FA Phase 15
// 16
{0x053D30A7,  CAT_FEHLER,           VT_DATETIME,      6950,  STR6950,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 16 Datum/Zeit
{0x053D30B1,  CAT_FEHLER,           VT_ERRORCODE,     6951,  STR6951,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 16 Fehlercode
{0x053D308E,  CAT_FEHLER,           VT_UINT,          6955,  STR6955,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - SW Diagnosecode 16
{0x053D309D,  CAT_FEHLER,           VT_BYTE,          6956,  STR6956,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - FA Phase 16
// 17
{0x053D30A8,  CAT_FEHLER,           VT_DATETIME,      6960,  STR6960,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 17 Datum/Zeit
{0x053D30B2,  CAT_FEHLER,           VT_ERRORCODE,     6961,  STR6961,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 17 Fehlercode
{0x053D308F,  CAT_FEHLER,           VT_UINT,          6965,  STR6965,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - SW Diagnosecode 17
{0x053D309E,  CAT_FEHLER,           VT_BYTE,          6966,  STR6966,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - FA Phase 17
// 18
{0x053D30A9,  CAT_FEHLER,           VT_DATETIME,      6970,  STR6970,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 18 Datum/Zeit
{0x053D30B3,  CAT_FEHLER,           VT_ERRORCODE,     6971,  STR6971,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 18 Fehlercode
{0x053D3090,  CAT_FEHLER,           VT_UINT,          6975,  STR6975,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - SW Diagnosecode 18
{0x053D309F,  CAT_FEHLER,           VT_BYTE,          6976,  STR6976,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - FA Phase 18
// 19
{0x053D30AA,  CAT_FEHLER,           VT_DATETIME,      6980,  STR6980,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 19 Datum/Zeit
{0x053D30B4,  CAT_FEHLER,           VT_ERRORCODE,     6981,  STR6981,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 19 Fehlercode
{0x053D3091,  CAT_FEHLER,           VT_UINT,          6985,  STR6985,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - SW Diagnosecode 19
{0x053D30A0,  CAT_FEHLER,           VT_BYTE,          6986,  STR6986,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - FA Phase 19
// 20
{0x053D30AB,  CAT_FEHLER,           VT_DATETIME,      6990,  STR6990,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 20 Datum/Zeit
{0x053D30B5,  CAT_FEHLER,           VT_ERRORCODE,     6991,  STR6991,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - Historie 20 Fehlercode
{0x053D3092,  CAT_FEHLER,           VT_UINT,          6995,  STR6995,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - SW Diagnosecode 20
{0x053D30A1,  CAT_FEHLER,           VT_BYTE,          6996,  STR6996,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [ ] - Fehler - FA Phase 20

// Wartung/Sonderbetrieb

{0x053D009C,  CAT_WARTUNG,          VT_UNKNOWN,       7000,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00 00 00 00 00 00 00 00 / same on RVS43.222 // probably some kind of "Wartung" log with date, message number and origin (VT_LPBADDR)
// 7001: 0x053D0075??? 2 byte VT_ENUM aber ENUM nicht verfügbar
{0x053D0090,  CAT_WARTUNG,          VT_BYTE,          7001,  STR7001,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 7001 Meldung [?]
{0x2D3D0090,  CAT_WARTUNG,          VT_BYTE,          7001,  STR7001,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Thision 7001 Meldung [?] - logged on OCI700 via LPB
{0x2D3D2FDA,  CAT_WARTUNG,          VT_ONOFF,         7007,  STR7007,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 7007 Anzeige Meldungen [Ein/Aus]
{0x2D3D2FDA,  CAT_WARTUNG,          VT_UNKNOWN,       7007,  STR7007,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // TODO Thision 7007 Anzeige Meldungen [Ein/Aus] - logged on OCI700 via LPB
{0x2D3D2FD9,  CAT_WARTUNG,          VT_ONOFF,         7010,  STR7010,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 7010 Quittierung Meldung [Ein/Aus]
{0x2E3D2FD9,  CAT_WARTUNG,          VT_ONOFF,         7010,  STR7010,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Thision 7010 Quittierung Meldung [Ein/Aus]
{0x253D2FDD,  CAT_WARTUNG,          VT_DAYS_WORD,     7011,  STR7011,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 7011 Repetitionszeit Meldung [Tage]
// !FIXME! !AUTOGENERATED! same cmd as 7007
{0x2D3D2FDA,  CAT_WARTUNG,          VT_YESNO,         7012,  STR7012,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 7012 Reset Meldungen 1-6 [Ja/Nein]
{0x053D03F1,  CAT_WARTUNG,          VT_HOURS_WORD,    7040,  STR7040,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [h ] - Wartung/Service - Brennerstunden Intervall
{0x2E3D03F1,  CAT_WARTUNG,          VT_HOURS_WORD,    7040,  STR7011,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Thision 7011 Repetitionszeit Meldung [Tage] - logged on OCI700 via LPB
{0x053D03F3,  CAT_WARTUNG,          VT_HOURS_WORD,    7041,  STR7041,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [h ] - Wartung/Service - Brennerstunden seit Wartung
{0x250503F3,  CAT_WARTUNG,          VT_HOURS_WORD,    7041,  STR7041,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [h ] - Wartung/Service - Brennerstunden seit Wartung - logged on OCI700 via LPB
{0x2E052FD6,  CAT_WARTUNG,          VT_UINT,          7042,  STR7042,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - Wartung/Service - Brennerstarts Intervall - logged on OCI700 via LPB
{0x2D3D2FD6,  CAT_WARTUNG,          VT_UINT,          7042,  STR7042,  0,                    NULL,         DEFAULT_FLAG, DEV_098_ALL}, // [0] - Wartung/Service - Brennerstarts Intervall
{0x2D3D2FD6,  CAT_WARTUNG,          VT_UINT,          7042,  STR7042,  0,                    NULL,         DEFAULT_FLAG, DEV_097_ALL}, // [0] - Wartung/Service - Brennerstarts Intervall
{0x053D05DF,  CAT_WARTUNG,          VT_UINT,          7042,  STR7042,  0,                    NULL,         DEFAULT_FLAG, DEV_096_ALL}, // [0] - Wartung/Service - Brennerstarts Intervall
{0x053D0C69,  CAT_WARTUNG,          VT_UINT,          7042,  STR7042,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Wartung/Service - Brennerstarts Intervall
{0x253D2FDF,  CAT_WARTUNG,          VT_UINT5,         7043,  STR7043,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [0] - Wartung/Service - Brennerstarts seit Wartung - logged on OCI700 via LPB
{0x253D2FDF,  CAT_WARTUNG,          VT_UINT5,         7043,  STR7043,  0,                    NULL,         DEFAULT_FLAG, DEV_098_ALL}, // [0] - Wartung/Service - Brennerstarts seit Wartung
{0x253D2FDF,  CAT_WARTUNG,          VT_UINT5,         7043,  STR7043,  0,                    NULL,         DEFAULT_FLAG, DEV_097_ALL}, // [0] - Wartung/Service - Brennerstarts seit Wartung
{0x053D05E0,  CAT_WARTUNG,          VT_UINT,          7043,  STR7043,  0,                    NULL,         DEFAULT_FLAG, DEV_096_ALL}, // [0] - Wartung/Service - Brennerstarts seit Wartung
{0x053D05E0,  CAT_WARTUNG,          VT_UINT,          7043,  STR7043,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Wartung/Service - Brennerstarts seit Wartung
//FUJITSU
{0x053D05E1,  CAT_WARTUNG,          VT_MONTHS,        7044,  STR7044,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [Monate ] - Wartung/Service - Wartungsintervall
{0x2E0505E1,  CAT_WARTUNG,          VT_MONTHS,        7044,  STR7044,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [Monate ] - Wartung/Service - Wartungsintervall - logged on OCI700 via LPB
{0x053D05E2,  CAT_WARTUNG,          VT_MONTHS,        7045,  STR7045,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [Monate ] - Wartung/Service - Zeit seit Wartung
{0x250505E2,  CAT_WARTUNG,          VT_MONTHS,        7045,  STR7045,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // [Monate ] - Wartung/Service - Zeit seit Wartung - logged on OCI700 via LPB
{0x053D0B0F,  CAT_WARTUNG,          VT_MONTHS,        7045,  STR7045,  0,                    NULL,         DEFAULT_FLAG, DEV_138_ALL}, // [Monate ] - Wartung/Service - Zeit seit Wartung

{0x2D3D2FD8,  CAT_WARTUNG,          VT_SPEED,         7050,  STR7050,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Gebläsedrehzahl Ion Strom
{0x2E052FD8,  CAT_WARTUNG,          VT_SPEED,         7050,  STR7050,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // Gebläsedrehzahl Ion Strom - logged on OCI700 via LPB
{0x093D10B0,  CAT_WARTUNG,          VT_SPEED2,        7050,  STR7050,  0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Gebläsedrehzahl Ion Strom
{0x093D10B0,  CAT_WARTUNG,          VT_SPEED2,        7050,  STR7050,  0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Gebläsedrehzahl Ion Strom
{0x093D10B0,  CAT_WARTUNG,          VT_SPEED2,        7050,  STR7050,  0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Gebläsedrehzahl Ion Strom
{0x093D10B0,  CAT_WARTUNG,          VT_SPEED2,        7050,  STR7050,  0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Gebläsedrehzahl Ion Strom
{0x2D3D300C,  CAT_WARTUNG,          VT_BYTE,          7051,  STR7051,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TODO Thision 7051 Meldung Ion Strom [?]
{0x2E3D300C,  CAT_WARTUNG,          VT_BYTE,          7051,  STR7051,  0,                    NULL,         DEFAULT_FLAG, DEV_064_ALL}, // TODO Thision 7051 Meldung Ion Strom [?] - logged on OCI700 via LPB
{0x053D300C,  CAT_WARTUNG,          VT_YESNO,         7051,  STR7051,  0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Meldung Ionisationsstrom
{0x053D300C,  CAT_WARTUNG,          VT_YESNO,         7051,  STR7051,  0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Meldung Ionisationsstrom
{0x053D300C,  CAT_WARTUNG,          VT_YESNO,         7051,  STR7051,  0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Meldung Ionisationsstrom
{0x053D300C,  CAT_WARTUNG,          VT_YESNO,         7051,  STR7051,  0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Meldung Ionisationsstrom
{0x05050B0F,  CAT_WARTUNG,          VT_TEMP   ,       7053,  STR7053,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgastemperaturgrenze
{0x053D0B2B,  CAT_WARTUNG,          VT_TEMP,          7053,  STR7053,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abgastemperaturgrenze
{0x053D0B2B,  CAT_WARTUNG,          VT_MINUTES_SHORT, 7054,  STR7054,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Verzögerung Abgasmeldung
{0x053D107E,  CAT_WARTUNG,          VT_TEMP,          7056,  STR7056,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TWW Verbrühungsgefahr
{0x053D05E1,  CAT_WARTUNG,          VT_MONTHS,        7070,  STR7070,  0,                    NULL,         DEFAULT_FLAG, DEV_170_ALL}, // WP Zeitintervall //FUJITSU
{0x053D05E2,  CAT_WARTUNG,          VT_MONTHS,        7071,  STR7071,  0,                    NULL,         DEFAULT_FLAG, DEV_170_ALL}, // WP Zeit seit Wartung //FUJITSU
{0x593D06B2,  CAT_WARTUNG,          VT_UNKNOWN,       7072,  STR7072,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Max Starts Verd1 / Betr’Std
{0x593D06B3,  CAT_WARTUNG,          VT_FP1,           7073,  STR7073,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Akt Starts Verd1 / Betr’Std //FUJITSU
{CMD_UNKNOWN, CAT_WARTUNG,          VT_UNKNOWN,       7074,  STR7074,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Max Starts Verd2 / Betr’Std
{CMD_UNKNOWN, CAT_WARTUNG,          VT_UNKNOWN,       7075,  STR7075,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Akt Starts Verd2 / Betr’Std
{0x593D06E9,  CAT_WARTUNG,          VT_UNKNOWN,       7076,  STR7076,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Spreiz Kondens Max / Wo
{0x593D06EA,  CAT_WARTUNG,          VT_UNKNOWN,       7077,  STR7077,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Akt Spreiz Kondens Max / Wo
{0x593D06EB,  CAT_WARTUNG,          VT_UNKNOWN,       7078,  STR7078,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Spreiz Kondens Min / Wo
{0x593D06EC,  CAT_WARTUNG,          VT_UNKNOWN,       7079,  STR7079,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Akt Spreiz Kondens Min / Wo
{CMD_UNKNOWN, CAT_WARTUNG,          VT_UNKNOWN,       7080,  STR7080,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Spreiz Verdampfer Max / Wo
{CMD_UNKNOWN, CAT_WARTUNG,          VT_UNKNOWN,       7081,  STR7081,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Akt Spreiz Verdampfer Max / Wo
{CMD_UNKNOWN, CAT_WARTUNG,          VT_UNKNOWN,       7082,  STR7082,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Spreiz Verdampfer Min / Wo
{CMD_UNKNOWN, CAT_WARTUNG,          VT_UNKNOWN,       7083,  STR7083,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Akt Spreiz Verdampfer Min / Wo
{0x253D06F1,  CAT_WARTUNG,          VT_MONTHS,        7090,  STR7090,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TWW Speicher Zeitintervall
{0x253D06F2,  CAT_WARTUNG,          VT_UNKNOWN,       7091,  STR7091,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TWW Speicher seit Wartung
{CMD_UNKNOWN, CAT_WARTUNG,          VT_UNKNOWN,       7092,  STR7092,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // TWW Ladetemp WP Minimum
{CMD_UNKNOWN, CAT_WARTUNG,          VT_UNKNOWN,       7093,  STR7093,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Akt TWW Ladetemperatur WP
{0x05050D20,  CAT_WARTUNG,          VT_ENUM,          7119,  STR7119,  sizeof(ENUM7119),     ENUM7119,     DEFAULT_FLAG, DEV_ALL}, // Ökofunktion
{0x053D0D20,  CAT_WARTUNG,          VT_ENUM,          7119,  STR7119,  sizeof(ENUM7119),     ENUM7119,     DEFAULT_FLAG, DEV_138_ALL}, // Ökofunktion
{0x05050B4E,  CAT_WARTUNG,          VT_ONOFF,         7120,  STR7120,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Ökobetrieb
{0x053D0B4E,  CAT_WARTUNG,          VT_ONOFF,         7120,  STR7120,  0,                    NULL,         DEFAULT_FLAG, DEV_138_ALL}, // Ökobetrieb
{0x0D3D092A,  CAT_WARTUNG,          VT_ONOFF,         7130,  STR7130,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Wartung/Service - Schornsteinfegerfunktion
{0x0505058D,  CAT_WARTUNG,          VT_ENUM,          7131,  STR7131,  sizeof(ENUM7131),     ENUM7131,     DEFAULT_FLAG, DEV_ALL}, // [0] - Wartung/Service - Schornsteinfegerfunktion Brennerleistung (00 02 = Vollast)
{0x053D0075,  CAT_WARTUNG,          VT_ONOFF,         7140,  STR7140,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Wartung/Service - Handbetrieb
{0x053D06AD,  CAT_WARTUNG,          VT_ONOFF,         7141,  STR7141,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Notbetrieb //FUJITSU
{0x053D06AE,  CAT_WARTUNG,          VT_ENUM,          7142,  STR7142,  sizeof(ENUM7142),     ENUM7142,     DEFAULT_FLAG, DEV_ALL}, // Notbetrieb Funktionsstart //FUJITSU
{0x093D3021,  CAT_WARTUNG,          VT_ONOFF,         7143,  STR7143,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 7143 Reglerstoppfunktion [Ein/Aus]
{0x093D3022,  CAT_WARTUNG,          VT_PERCENT,       7145,  STR7145,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 7145 Reglerstopp Sollwert [%]
{0x053D3022,  CAT_WARTUNG,          VT_PERCENT,       7145,  STR7145,  0,                    NULL,         DEFAULT_FLAG, DEV_123_ALL}, // Reglerstopp Sollwert [%]
{0x053D3022,  CAT_WARTUNG,          VT_PERCENT,       7145,  STR7145,  0,                    NULL,         DEFAULT_FLAG, DEV_162_ALL}, // Reglerstopp Sollwert [%]
{0x053D3022,  CAT_WARTUNG,          VT_PERCENT,       7145,  STR7145,  0,                    NULL,         DEFAULT_FLAG, DEV_163_ALL}, // Reglerstopp Sollwert [%]
{0x053D3022,  CAT_WARTUNG,          VT_PERCENT,       7145,  STR7145,  0,                    NULL,         DEFAULT_FLAG, DEV_195_ALL}, // Reglerstopp Sollwert [%]
{0x113D307C,  CAT_WARTUNG,          VT_ONOFF,         7146,  STR7146,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Thision 7146 Entlüftungsfunktion [Ein/Aus]
{0x113D0F97,  CAT_WARTUNG,          VT_ENUM,          7147,  STR7147,  sizeof(ENUM7147),     ENUM7147,     DEFAULT_FLAG, DEV_ALL}, // [ ] Wartung/Sonderbetrieb - Entlüftungsart
{0x053D0528,  CAT_WARTUNG,          VT_TEMP,          7150,  STR7150,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [ °C ] - Wartung/Service - Simulation Aussentemperatur
{CMD_UNKNOWN, CAT_WARTUNG,          VT_UNKNOWN,       7152,  STR7152,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Abtauen auslösen
{CMD_UNKNOWN, CAT_WARTUNG,          VT_UNKNOWN,       7160,  STR7160,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Reset Begrenzungszeiten
{0x113D1A9A,  CAT_WARTUNG,          VT_BYTE,          7166,  STR7166,  0,                    NULL,         FL_RONLY, DEV_ALL}, // [ ] Wartung/Sonderbetrieb - Inbetriebnahmefunktion
{0x053D06E8,  CAT_WARTUNG,          VT_STRING,        7170,  STR7170,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Wartung/Service - Telefon Kundendienst
{0x053D07B7,  CAT_WARTUNG,          VT_STRING,        7181,  STR7181,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Wartung/Service - Telefon Zuständigkeit 1
{0x053D07B8,  CAT_WARTUNG,          VT_STRING,        7183,  STR7183,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // [0] - Wartung/Service - Telefon Zuständigkeit 2
{0x053D11DA,  CAT_WARTUNG,          VT_UNKNOWN,       7250,  STR7250,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pstick Pos
{CMD_UNKNOWN, CAT_WARTUNG,          VT_UNKNOWN,       7251,  STR7251,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pstick Bez Datensatz
{0x053D11D9,  CAT_WARTUNG,          VT_ENUM,          7252,  STR7252,  sizeof(ENUM7252),     ENUM7252,     DEFAULT_FLAG, DEV_ALL}, // Pstick Befehl
{0x053D11D8,  CAT_WARTUNG,          VT_PERCENT,       7253,  STR7253,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pstick Fortschritt
{0x053D11D7,  CAT_WARTUNG,          VT_PERCENT,       7254,  STR7253,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Pstick Fortschritt TODO: Check double telegram ..D8 ..D7

// Konfiguration Erweit'module
{0x053D0D92,  CAT_MODULE,           VT_ENUM,          7311,  STR7311,  sizeof(ENUM5950_4),   ENUM5950_4,   DEFAULT_FLAG, DEV_123_ALL}, // Funktion Eingang H2 Modul 1
{0x053D0D55,  CAT_MODULE,           VT_ENUM,          7376,  STR7376,  sizeof(ENUM7376),     ENUM7376,     DEFAULT_FLAG, DEV_ALL}, // Relaisausgang QX21 Modul 2
{0x053D0D56,  CAT_MODULE,           VT_ENUM,          7377,  STR7377,  sizeof(ENUM7376),     ENUM7376,     DEFAULT_FLAG, DEV_ALL}, // Relaisausgang QX22 Modul 2
{0x053D0D57,  CAT_MODULE,           VT_ENUM,          7378,  STR7378,  sizeof(ENUM7376),     ENUM7376,     DEFAULT_FLAG, DEV_ALL}, // Relaisausgang QX23 Modul 2
{0x053D0D8A,  CAT_MODULE,           VT_ENUM,          7382,  STR6042,  sizeof(ENUM6040),     ENUM6040,     DEFAULT_FLAG, DEV_ALL}, // Fühlereingang BX21 Modul 2
{0x053D0D8D,  CAT_MODULE,           VT_ENUM,          7383,  STR6043,  sizeof(ENUM6040),     ENUM6040,     DEFAULT_FLAG, DEV_ALL}, // Fühlereingang BX22 Modul 2
{0x053D0D93,  CAT_MODULE,           VT_ENUM,          7386,  STR7386,  sizeof(ENUM5950_4),   ENUM5950_4,   DEFAULT_FLAG, DEV_ALL}, // Funktion Eingang H2 Modul 2
{0x053D0DCA,  CAT_MODULE,           VT_ENUM,          7387,  STR7387,  sizeof(ENUM5951),     ENUM5951,     DEFAULT_FLAG, DEV_ALL}, // Wirksinn Kontakt H2 Modul 2
{0x053D15BE,  CAT_MODULE,           VT_ENUM,          7396,  STR7396,  sizeof(ENUM5950_4),   ENUM5950_4,   DEFAULT_FLAG, DEV_ALL}, // Funktion Eing' H21 Modul 2
{0x053D15D3,  CAT_MODULE,           VT_VOLTAGE,       7399,  STR7399,  0,                    0,            DEFAULT_FLAG, DEV_ALL}, // Eingangswert 1 H21 Modul 2 // todo: dies ein 3 byte spannungswert wert...
{0x053D15DF,  CAT_MODULE,           VT_UINT,          7400,  STR7400,  0,                    0,            DEFAULT_FLAG, DEV_ALL}, // Funkt'wert 1 H21 Modul 2
{0x053D15D9,  CAT_MODULE,           VT_VOLTAGE,       7401,  STR7401,  0,                    0,            DEFAULT_FLAG, DEV_ALL}, // Eingangswert 2 H21 Modul 2 // todo: dies ein 3 byte spannungswert wert...
{0x053D15E5,  CAT_MODULE,           VT_UINT,          7402,  STR7402,  0,                    0,            DEFAULT_FLAG, DEV_ALL}, // Funkt'wert 2 H21 Modul 2
{0x053D15CD,  CAT_MODULE,           VT_ENUM,          7423,  STR7423,  sizeof(ENUM6085),     ENUM6085,     DEFAULT_FLAG, DEV_ALL}, // Fkt Ausg' UX21 Modul 2
{0x053D15EB,  CAT_MODULE,           VT_ENUM,          7425,  STR7425,  sizeof(ENUM7425),     ENUM7425,     DEFAULT_FLAG, DEV_ALL}, // Signal Ausg' UX21 Modul 2
{0x053D15D0,  CAT_MODULE,           VT_ENUM,          7430,  STR7430,  sizeof(ENUM6085),     ENUM6085,     DEFAULT_FLAG, DEV_ALL}, // Fkt Ausg' UX22 Modul 2
{0x053D15EE,  CAT_MODULE,           VT_ENUM,          7432,  STR7432,  sizeof(ENUM7425),     ENUM7425,     DEFAULT_FLAG, DEV_ALL}, // Signal Ausg' UX22 Modul 2

// Ein-/Ausgangstest
{0x053D0073,  CAT_IOTEST,           VT_ENUM,          7700,  STR7700,  sizeof(ENUM7700),     ENUM7700,     DEFAULT_FLAG, DEV_ALL}, // [0] - Ein-/Ausgangstest - Relaistest
{0x053D0073,  CAT_IOTEST,           VT_ENUM,          7700,  STR7700,  sizeof(ENUM7700_2),   ENUM7700_2,   DEFAULT_FLAG, DEV_076_ALL}, // [0] - Ein-/Ausgangstest - Relaistest
{0x053D040C,  CAT_IOTEST,           VT_PERCENT,       7705,  STR7705,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Mod'sollwert QX3 Relaistest
{0x053D040C,  CAT_IOTEST,           VT_PERCENT,       7705,  STR7705,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // Mod'sollwert QX3 Relaistest
{0x053D04A2,  CAT_IOTEST,           VT_PERCENT,       7708,  STR7708,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Modulationssignal QX3
{0x053D04A2,  CAT_IOTEST,           VT_PERCENT,       7708,  STR7708,  0,                    NULL,         FL_NO_CMD,    DEV_123_ALL}, // Modulationssignal QX3
{0x053D040E,  CAT_IOTEST,           VT_PERCENT,       7710,  STR7710,  0,                    NULL,         FL_RONLY,     DEV_170_ALL}, // Ausgangstest UX1 //FUJITSU
{0x053D040E,  CAT_IOTEST,           VT_VOLTAGE,       7710,  STR7710,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Ausgangstest UX
{0x053D0821,  CAT_IOTEST,           VT_VOLTAGE,       7711,  STR7711,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Spannungssignal UX
{0x073D0B38,  CAT_IOTEST,           VT_PERCENT,       7712,  STR7712,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // PWM-Signal UX1 //FUJITSU
{0x053D040C,  CAT_IOTEST,           VT_PERCENT,       7713,  STR7713,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // Ausgangstest P1
{0x053D04A2,  CAT_IOTEST,           VT_PERCENT,       7714,  STR7714,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // PWM-Signal P1
{0x063D040E,  CAT_IOTEST,           VT_PERCENT,       7716,  STR7716,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Ausgangstest UX2 //FUJITSU
{0x063D04A2,  CAT_IOTEST,           VT_PERCENT,       7719,  STR7719,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // PWM-Signal UX2 //FUJITSU
{0x053D0D62,  CAT_IOTEST,           VT_UNKNOWN,       7720,  STR7720,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Ausgangstest Digital
{0x053D0D81,  CAT_IOTEST,           VT_ONOFF,         7721,  STR7721,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Digitalausgang D01
{0x053D0D82,  CAT_IOTEST,           VT_ONOFF,         7722,  STR7722,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kühlbetrieb D2 //FUJITSU
{0x053D127B,  CAT_IOTEST,           VT_ONOFF,         7723,  STR7723,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Wärmepumpe D3 //FUJITSU
{0x073D040E,  CAT_IOTEST,           VT_PERCENT,       7724,  STR7724,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Ausgangstest UX3 //FUJITSU
{0x073D1238,  CAT_IOTEST,           VT_VOLTAGE,       7725,  STR7725,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal U4 (Ux3) //FUJITSU
{0x053D0470,  CAT_IOTEST,           VT_TEMP,          7730,  STR7730,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - Aussentemperatur B9
{0x053D08C5,  CAT_IOTEST,           VT_TEMP,          7732,  STR7732,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - vorlauftemperatur B1
{0x053D08C6,  CAT_IOTEST,           VT_TEMP,          7734,  STR7734,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - Vorlauftemperatur B12
{0x053D0462,  CAT_IOTEST,           VT_TEMP,          7750,  STR7750,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - Trinkwassertemperatur B3
{0x053D0D86,  CAT_IOTEST,           VT_TEMP,          7750,  STR7750,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [°C ] - Ein-/Ausgangstest - Trinkwassertemperatur B3
{0x053D0468,  CAT_IOTEST,           VT_TEMP,          7760,  STR7760,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - Kesseltemperatur B2
{CMD_UNKNOWN, CAT_IOTEST,           VT_UNKNOWN,       7770,  STR7770,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Vorlauftemperatur WP B21
{CMD_UNKNOWN, CAT_IOTEST,           VT_UNKNOWN,       7771,  STR7771,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Rücklauftemperatur WP B71
{CMD_UNKNOWN, CAT_IOTEST,           VT_UNKNOWN,       7772,  STR7772,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Heissgastemperatur B81
{CMD_UNKNOWN, CAT_IOTEST,           VT_UNKNOWN,       7775,  STR7775,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Quelle Eintrittstemp B91
{CMD_UNKNOWN, CAT_IOTEST,           VT_UNKNOWN,       7777,  STR7777,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Fühlertemperatur B92 B84
{0x053D15F7,  CAT_IOTEST,           VT_PERCENT,       7784,  STR7784,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Ausgangstest UX21 Modul 2
{0x053D1703,  CAT_IOTEST,           VT_UNKNOWN,       7785,  STR7785,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Ausg'signal UX21 Modul 2
{0x053D170A,  CAT_IOTEST,           VT_UNKNOWN,       7788,  STR7785_2,0,                    NULL,         FL_RONLY,     DEV_ALL}, // Ausg'signal UX21 Modul 2 PWM % // Teil 2 von 7785 abgelegt als 7788
{0x053D15FA,  CAT_IOTEST,           VT_PERCENT,       7786,  STR7786,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Ausgangstest UX22 Modul 2
{0x053D1706,  CAT_IOTEST,           VT_UNKNOWN,       7787,  STR7787,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Ausg'signal UX22 Modul 2
{0x053D1717,  CAT_IOTEST,           VT_UNKNOWN,       7789,  STR7787_2,0,                    NULL,         FL_RONLY,     DEV_ALL}, // Ausg'signal UX22 Modul 2 PWM % // Teil 2 von 7787 abgelegt als 7789

{0x053D056B,  CAT_IOTEST,           VT_TEMP,          7804,  STR7820,  0,                    NULL,         FL_RONLY,     DEV_170_ALL}, // [°C ] - Ein-/Ausgangstest - Fühlertemperatur BX1
{0x053D056C,  CAT_IOTEST,           VT_TEMP,          7805,  STR7821,  0,                    NULL,         FL_RONLY,     DEV_170_ALL}, // [°C ] - Ein-/Ausgangstest - Fühlertemperatur BX2
{0x053D0791,  CAT_IOTEST,           VT_TEMP,          7806,  STR7822,  0,                    NULL,         FL_RONLY,     DEV_170_ALL}, // [°C ] - Ein-/Ausgangstest - Fühlertemperatur BX3
{0x053D0792,  CAT_IOTEST,           VT_TEMP,          7807,  STR7823,  0,                    NULL,         FL_RONLY,     DEV_170_ALL}, // [°C ] - Ein-/Ausgangstest - Fühlertemperatur BX4
{0x053D07C9,  CAT_IOTEST,           VT_TEMP,          7808,  STR7824,  0,                    NULL,         FL_RONLY,     DEV_170_ALL}, // Fühlertemperatur BX5 //FUJITSU
{0x053D1273,  CAT_IOTEST,           VT_TEMP,          7809,  STR7809,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - Fühlertemperatur BX6 //FUJITSU
{0x053D056B,  CAT_IOTEST,           VT_TEMP,          7820,  STR7820,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - Fühlertemperatur BX1
{0x053D056C,  CAT_IOTEST,           VT_TEMP,          7821,  STR7821,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - Fühlertemperatur BX2
{0x053D0791,  CAT_IOTEST,           VT_TEMP,          7822,  STR7822,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - Fühlertemperatur BX3
{0x053D0792,  CAT_IOTEST,           VT_TEMP,          7823,  STR7823,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - Fühlertemperatur BX4
{0x053D07C9,  CAT_IOTEST,           VT_TEMP,          7824,  STR7824,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Fühlertemperatur BX5 //FUJITSU

{0x053D0793,  CAT_IOTEST,           VT_TEMP,          7830,  STR7830,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - Fühlertemp. BX21 Modul 1
{0x053D0799,  CAT_IOTEST,           VT_TEMP,          7831,  STR7831,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - Fühlertemp. BX22 Modul 1
{0x053D079A,  CAT_IOTEST,           VT_TEMP,          7832,  STR7832,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - Fühlertemp. BX21 Modul 2
{0x053D079B,  CAT_IOTEST,           VT_TEMP,          7833,  STR7833,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Ein-/Ausgangstest - Fühlertemp. BX22 Modul 2
{0x053D082F,  CAT_IOTEST,           VT_VOLTAGE,       7840,  STR7840,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H1
{0x053D0579,  CAT_IOTEST,           VT_VOLTAGE,       7840,  STR7840,  0,                    NULL,         FL_RONLY,     DEV_096_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H1
{0x053D0579,  CAT_IOTEST,           VT_VOLTAGE,       7840,  STR7840,  0,                    NULL,         FL_RONLY,     DEV_108_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H1
{0x053D0579,  CAT_IOTEST,           VT_VOLTAGE,       7840,  STR7840,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H1
{0x053D0579,  CAT_IOTEST,           VT_VOLTAGE,       7840,  STR7840,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H1
{0x053D0579,  CAT_IOTEST,           VT_VOLTAGE,       7840,  STR7840,  0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H1
{0x053D0579,  CAT_IOTEST,           VT_VOLTAGE,       7840,  STR7840,  0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H1
{0x053D0579,  CAT_IOTEST,           VT_VOLTAGE,       7840,  STR7840,  0,                    NULL,         FL_RONLY,     DEV_205_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H1
{0x053D0579,  CAT_IOTEST,           VT_VOLTAGE,       7840,  STR7840,  0,                    NULL,         FL_RONLY,     DEV_211_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H1
{0x053D045D,  CAT_IOTEST,           VT_CLOSEDOPEN,    7841,  STR7841,  0,                    NULL,         FL_RONLY,     DEV_096_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H1
{0x053D0809,  CAT_IOTEST,           VT_CLOSEDOPEN,    7841,  STR7841,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H1
{0x053D0DA3,  CAT_IOTEST,           VT_CLOSEDOPEN,    7841,  STR7841,  0,                    NULL,         FL_RONLY,     DEV_108_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H1
{0x053D0DA3,  CAT_IOTEST,           VT_CLOSEDOPEN,    7841,  STR7841,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H1
{0x053D0DA3,  CAT_IOTEST,           VT_CLOSEDOPEN,    7841,  STR7841,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H1
{0x053D0DA3,  CAT_IOTEST,           VT_CLOSEDOPEN,    7841,  STR7841,  0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H1
{0x053D0DA3,  CAT_IOTEST,           VT_CLOSEDOPEN,    7841,  STR7841,  0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H1
{0x053D0DA3,  CAT_IOTEST,           VT_CLOSEDOPEN,    7841,  STR7841,  0,                    NULL,         FL_RONLY,     DEV_205_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H1
{0x053D0DA3,  CAT_IOTEST,           VT_CLOSEDOPEN,    7841,  STR7841,  0,                    NULL,         FL_RONLY,     DEV_211_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H1
{0x053D171C,  CAT_IOTEST,           VT_UNKNOWN,       7844,  STR7844,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Eingangssignal H1
{0x053D057A,  CAT_IOTEST,           VT_VOLTAGE,       7845,  STR7845,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H2
{0x063D082F,  CAT_IOTEST,           VT_VOLTAGE,       7845,  STR7845,  0,                    NULL,         FL_RONLY,     DEV_090_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H2
{0x063D082F,  CAT_IOTEST,           VT_VOLTAGE,       7845,  STR7845,  0,                    NULL,         FL_RONLY,     DEV_103_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H2
{0x063D082F,  CAT_IOTEST,           VT_VOLTAGE,       7845,  STR7845,  0,                    NULL,         FL_RONLY,     DEV_107_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H2
{0x063D082F,  CAT_IOTEST,           VT_VOLTAGE,       7845,  STR7845,  0,                    NULL,         FL_RONLY,     DEV_116_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H2
{0x063D082F,  CAT_IOTEST,           VT_VOLTAGE,       7845,  STR7845,  0,                    NULL,         FL_RONLY,     DEV_119_ALL}, // [V ] - Ein-/Ausgangstest - Spannungssignal H2
{0x053D0DA4,  CAT_IOTEST,           VT_CLOSEDOPEN,    7845,  STR7846,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2
{0x053D078F,  CAT_IOTEST,           VT_CLOSEDOPEN,    7846,  STR7846,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2
{0x06050809,  CAT_IOTEST,           VT_CLOSEDOPEN,    7846,  STR7846,  0,                    NULL,         FL_RONLY,     DEV_090_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2
{0x06050809,  CAT_IOTEST,           VT_CLOSEDOPEN,    7846,  STR7846,  0,                    NULL,         FL_RONLY,     DEV_103_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2
{0x06050809,  CAT_IOTEST,           VT_CLOSEDOPEN,    7846,  STR7846,  0,                    NULL,         FL_RONLY,     DEV_107_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2
{0x06050809,  CAT_IOTEST,           VT_CLOSEDOPEN,    7846,  STR7846,  0,                    NULL,         FL_RONLY,     DEV_116_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2
{0x06050809,  CAT_IOTEST,           VT_CLOSEDOPEN,    7846,  STR7846,  0,                    NULL,         FL_RONLY,     DEV_119_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2
{0x053D0DA4,  CAT_IOTEST,           VT_CLOSEDOPEN,    7846,  STR7846,  0,                    NULL,         FL_RONLY,     DEV_108_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2
{0x053D0DA4,  CAT_IOTEST,           VT_CLOSEDOPEN,    7846,  STR7846,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2
{0x053D0DA4,  CAT_IOTEST,           VT_CLOSEDOPEN,    7846,  STR7846,  0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2
{0x053D0DA4,  CAT_IOTEST,           VT_CLOSEDOPEN,    7846,  STR7846,  0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2
{0x053D0DA4,  CAT_IOTEST,           VT_CLOSEDOPEN,    7846,  STR7846,  0,                    NULL,         FL_RONLY,     DEV_205_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2
{0x053D0DA4,  CAT_IOTEST,           VT_CLOSEDOPEN,    7846,  STR7846,  0,                    NULL,         FL_RONLY,     DEV_211_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2
{0x053D0DA5,  CAT_IOTEST,           VT_CLOSEDOPEN,    7847,  STR7847,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Ein-/Ausgangstest - Zustand Kontakt H2, modul 2 //FUJITSU
// Lukas P. 7848 a (statt 7847) besteht aus 3 Telegrammen
{0x053D0DA5,  CAT_IOTEST,           VT_CLOSEDOPEN,    7848,  STR7848,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2 modul 2
// Lukas P. 7848 b
{0x053D1622,  CAT_IOTEST,           VT_VOLTAGE,       7849,  STR7849,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2 modul 2 - Parameter [Volt] // Teil 2 von 7848 abgelegt als 7849
// Lukas P. 7848 c
{0x053D1628,  CAT_IOTEST,           VT_CLOSEDOPEN,    7850,  STR7849,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H2 modul 2 - Parameter [Offen/Geschlossen] // Teil 3 von 7848 abgelegt als 7850

{0x073D082F,  CAT_IOTEST,           VT_VOLTAGE,       7854,  STR7854,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Spannungssignal H3
{0x073D0809,  CAT_IOTEST,           VT_CLOSEDOPEN,    7855,  STR7855,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kontaktzustand H3
{0x053D174E,  CAT_IOTEST,           VT_UNKNOWN,       7858,  STR7858,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Eingangssignal H3
{0x053D0DA8,  CAT_IOTEST,           VT_CLOSEDOPEN,    7860,  STR7860,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H4
{0x053D0DA9,  CAT_IOTEST,           VT_CLOSEDOPEN,    7865,  STR7865,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H5
{0x053D03F6,  CAT_IOTEST,           VT_VOLTAGE,       7870,  STR7870,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [V] - Ein-/Ausgangstest - Brennerstörung S3
{0x053D0DAA,  CAT_IOTEST,           VT_CLOSEDOPEN,    7872,  STR7872,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Ein-/Ausgangstest - Kontaktzustand H6
{0x053D03F5,  CAT_IOTEST,           VT_VOLTAGE,       7881,  STR7881,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [V] - Ein-/Ausgangstest - 1. Brennerstufe E1
{0x053D03F7,  CAT_IOTEST,           VT_VOLTAGEONOFF,  7884,  STR7884,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // STB Fehlermeldung L1
{CMD_UNKNOWN, CAT_IOTEST,           VT_UNKNOWN,       7889,  STR7889,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Niederdruckwächter E9
{CMD_UNKNOWN, CAT_IOTEST,           VT_UNKNOWN,       7890,  STR7890,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Hochdruckwächter E10
{CMD_UNKNOWN, CAT_IOTEST,           VT_UNKNOWN,       7891,  STR7891,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Wickl’schutz Verdicht 1 E11
{0x053D03F8,  CAT_IOTEST,           VT_VOLTAGEONOFF,  7911,  STR7911,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Eingang EX 1 //FUJITSU
//following CommandID used to be ...FC, but since it doubles with 7915 and ...09 make much more sense here, I changed it accordingly
{0x053D03F9,  CAT_IOTEST,           VT_VOLTAGEONOFF,  7912,  STR7912,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [V] - Ein-/Ausgangstest - Eingang EX2
{0x053D03FA,  CAT_IOTEST,           VT_VOLTAGEONOFF,  7913,  STR7913,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Eingang EX 3 //FUJITSU
{0x053D03FB,  CAT_IOTEST,           VT_VOLTAGEONOFF,  7914,  STR7914,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Eingang EX 4
// following CommandID from device family 119, same one in 7912
{0x053D03FC,  CAT_IOTEST,           VT_VOLTAGEONOFF,  7915,  STR7915,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Eingang EX 5
{0x053D03FD,  CAT_IOTEST,           VT_VOLTAGEONOFF,  7916,  STR7916,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Eingang EX 6
//following CommandID is just extrapolated from above ones...
{0x053D03FE,  CAT_IOTEST,           VT_VOLTAGEONOFF,  7917,  STR7917,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Eingang EX 7
{0x053D1078,  CAT_IOTEST,           VT_VOLTAGEONOFF,  7950,  STR7950,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Eingang EX01 Modul 1
{0x053D1079,  CAT_IOTEST,           VT_VOLTAGEONOFF,  7951,  STR7951,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Eingang EX01 Modul 2
{0x053D107A,  CAT_IOTEST,           VT_VOLTAGEONOFF,  7952,  STR7952,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Eingang EX01 Modul 3
{0x053D08C5,  CAT_IOTEST,           VT_TEMP,          7973,  STR7973,  0,                    NULL,         FL_RONLY,     DEV_170_ALL}, // Fühlertemperatur BX31 //FUJITSU
{0x053D1219,  CAT_IOTEST,           VT_TEMP,          7974,  STR7974,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Fühlertemperatur BX32 //FUJITSU
{0x053D121A,  CAT_IOTEST,           VT_TEMP,          7975,  STR7975,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Fühlertemperatur BX33 //FUJITSU
{0x053D121B,  CAT_IOTEST,           VT_TEMP,          7976,  STR7976,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Fühlertemperatur BX34 //FUJITSU
{0x053D126F,  CAT_IOTEST,           VT_TEMP,          7977,  STR7977,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Fühlertemperatur BX35 //FUJITSU
{0x053D1270,  CAT_IOTEST,           VT_TEMP,          7978,  STR7978,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Fühlertemperatur BX36 //FUJITSU
{0x053D1285,  CAT_IOTEST,           VT_CLOSEDOPEN,    7996,  STR7996,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Zustand Kontakt H33 //FUJITSU
{0x053D175F,  CAT_IOTEST,           VT_ENUM,          7999,  STR7999,  sizeof(ENUM7999),     ENUM7999,     FL_RONLY,     DEV_ALL}, // Eingangssignal H33 //FUJITSU

//Status
{0x053D07A3,  CAT_STATUS,           VT_ENUM,          8000,  STR8000,  sizeof(ENUM8000),     ENUM8000,     FL_RONLY,     DEV_ALL}, // [ ] - Status - Status Heizkreis 1
{0x053D07A4,  CAT_STATUS,           VT_ENUM,          8000,  STR8000,  sizeof(ENUM8000),     ENUM8000,     FL_RONLY,     DEV_ALL}, // [ ] - Status - Status Heizkreis 1  // gleiche Funktion in eigener CommandID
{0x053D07A5,  CAT_STATUS,           VT_ENUM,          8001,  STR8001,  sizeof(ENUM8001),     ENUM8001,     FL_RONLY,     DEV_ALL}, // [ ] - Status - Status Heizkreis 2
{0x053D07A6,  CAT_STATUS,           VT_ENUM,          8001,  STR8001,  sizeof(ENUM8001),     ENUM8001,     FL_RONLY,     DEV_ALL}, // [ ] - Status - Status Heizkreis 2  // gleiche Funktion in eigener CommandID
{0x053D07A7,  CAT_STATUS,           VT_ENUM,          8002,  STR8002,  sizeof(ENUM8002),     ENUM8002,     FL_RONLY,     DEV_ALL}, // [ ] - Status - Status Heizkreis P
{0x053D07A8,  CAT_STATUS,           VT_ENUM,          8002,  STR8002,  sizeof(ENUM8002),     ENUM8002,     FL_RONLY,     DEV_ALL}, // [ ] - Status - Status Heizkreis P  // gleiche Funktion in eigener CommandID
{0x053D07A1,  CAT_STATUS,           VT_ENUM,          8003,  STR8003,  sizeof(ENUM8003),     ENUM8003,     FL_RONLY,     DEV_ALL}, // [] - Status - Status Trinkwasser
{0x053D07A2,  CAT_STATUS,           VT_ENUM,          8003,  STR8003,  sizeof(ENUM8003),     ENUM8003,     FL_RONLY,     DEV_ALL}, // [] - Status - Status Trinkwasser  // gleiche Funktion in eigener CommandID
{0x053D0F73,  CAT_STATUS,           VT_ENUM,          8004,  STR8004,  sizeof(ENUM8004),     ENUM8004,     FL_RONLY,     DEV_ALL}, // Status Kühlkreis 1
{0x053D0F74,  CAT_STATUS,           VT_ENUM,          8004,  STR8004,  sizeof(ENUM8004),     ENUM8004,     FL_RONLY,     DEV_ALL}, // Status Kühlkreis 1  // gleiche Funktion in eigener CommandID

{0x053D07A9,  CAT_STATUS,           VT_ENUM,          8005,  STR8005,  sizeof(ENUM8005),     ENUM8005,     FL_RONLY,     DEV_ALL}, // [] - Status - Status Kessel
{0x053D07AA,  CAT_STATUS,           VT_ENUM,          8005,  STR8005,  sizeof(ENUM8005),     ENUM8005,     FL_RONLY,     DEV_ALL}, // [] - Status - Status Kessel       // gleiche Funktion in eigener CommandID
{0x053D17DC,  CAT_STATUS,           VT_ENUM,          8006,  STR8006,  sizeof(ENUM8006),     ENUM8006,     FL_RONLY,     DEV_ALL}, // Status Wärmepumpe //FUJITSU
{0x053D07AF,  CAT_STATUS,           VT_ENUM,          8006,  STR8006,  sizeof(ENUM8006),     ENUM8006,     FL_RONLY,     DEV_119_ALL}, // Status Wärmepumpe
{0x053D07AD,  CAT_STATUS,           VT_ENUM,          8007,  STR8007,  sizeof(ENUM8007),     ENUM8007,     FL_RONLY,     DEV_ALL}, // [] - Status - Status Solar
{0x053D07AE,  CAT_STATUS,           VT_ENUM,          8007,  STR8007,  sizeof(ENUM8007),     ENUM8007,     FL_RONLY,     DEV_ALL}, // [] - Status - Status Solar        // gleiche Funktion in eigener CommandID
{0x053D0A08,  CAT_STATUS,           VT_ENUM,          8008,  STR8008,  sizeof(ENUM8008),     ENUM8008,     FL_RONLY,     DEV_ALL}, // [] - Status - Status Feststoffkessel
//{CMD_UNKNOWN, CAT_STATUS,           VT_ENUM,          8009,  STR8009,  sizeof(ENUM8009),     ENUM8009,     FL_RONLY,     DEV_096_ALL+DEV_097_ALL}, // [] - Status - Status Brenner Thision / Brötje SOB
{0x053D0F66,  CAT_STATUS,           VT_ENUM,          8009,  STR8009,  sizeof(ENUM8009_2),   ENUM8009_2,   FL_RONLY,     DEV_ALL}, // [] - Status - Status Brenner Brötje BSW
{0x053D07AB,  CAT_STATUS,           VT_ENUM,          8010,  STR8010,  sizeof(ENUM8010),     ENUM8010,     FL_RONLY,     DEV_ALL}, // [] - Status - Status Pufferspeicher
{0x053D0AFC,  CAT_STATUS,           VT_ENUM,          8011,  STR8011,  sizeof(ENUM8011),     ENUM8011,     FL_RONLY,     DEV_ALL}, // Status Schwimmbad
{0x053D17E6,  CAT_STATUS,           VT_ENUM,          8022,  STR8022,  sizeof(ENUM8022),     ENUM8022,     FL_RONLY,     DEV_ALL}, // Status Zusatzerzeuger //FUJITSU
{0x053D0D68,  CAT_STATUS,           VT_ENUM,          8022,  STR8022,  sizeof(ENUM8022),     ENUM8022,     FL_RONLY,     DEV_119_ALL}, // Status Zusatzerzeuger
{0x053D1AC1,  CAT_STATUS,           VT_ENUM,          8023,  STR8023,  sizeof(ENUM8009),     ENUM8009,     FL_RONLY,     DEV_123_ALL}, // Status Sitherm Pro
{0x053D17D1,  CAT_STATUS,           VT_ENUM,          8025,  STR8025,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Status Kühlkreis 2
{0x053D06FD,  CAT_STATUS,           VT_DATETIME,      8050,  STR8050,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Zeitstempel Statushistorie 1
{0x053D17EA,  CAT_STATUS,           VT_ENUM,          8051,  STR8051,  sizeof(ENUM8051),     ENUM8051,     FL_RONLY,     DEV_ALL}, // Statuscode Statushistorie 1
{0x053D06FE,  CAT_STATUS,           VT_DATETIME,      8052,  STR8052,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Zeitstempel Statushistorie 2
{0x053D17EB,  CAT_STATUS,           VT_ENUM,          8053,  STR8053,  sizeof(ENUM8053),     ENUM8053,     FL_RONLY,     DEV_ALL}, // Statuscode Statushistorie 2
{0x053D06FF,  CAT_STATUS,           VT_DATETIME,      8054,  STR8054,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Zeitstempel Statushistorie 3
{0x053D06F5,  CAT_STATUS,           VT_ENUM,          8055,  STR8055,  sizeof(ENUM8055),     ENUM8055,     FL_RONLY,     DEV_ALL}, // Statuscode Statushistorie 3
{0x053D0700,  CAT_STATUS,           VT_DATETIME,      8056,  STR8056,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Zeitstempel Statushistorie 4
{0x053D06F6,  CAT_STATUS,           VT_ENUM,          8057,  STR8057,  sizeof(ENUM8057),     ENUM8057,     FL_RONLY,     DEV_ALL}, // Statuscode Statushistorie 4
{0x053D0701,  CAT_STATUS,           VT_DATETIME,      8058,  STR8058,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Zeitstempel Statushistorie 5
{0x053D06F7,  CAT_STATUS,           VT_ENUM,          8059,  STR8059,  sizeof(ENUM8059),     ENUM8059,     FL_RONLY,     DEV_ALL}, // Statuscode Statushistorie 5
{0x053D0702,  CAT_STATUS,           VT_DATETIME,      8060,  STR8060,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Zeitstempel Statushistorie 6
{0x053D06F8,  CAT_STATUS,           VT_ENUM,          8061,  STR8061,  sizeof(ENUM8061),     ENUM8061,     FL_RONLY,     DEV_ALL}, // Statuscode Statushistorie 6
{0x053D0703,  CAT_STATUS,           VT_DATETIME,      8062,  STR8062,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Zeitstempel Statushistorie 7
{0x053D06F9,  CAT_STATUS,           VT_ENUM,          8063,  STR8063,  sizeof(ENUM8063),     ENUM8063,     FL_RONLY,     DEV_ALL}, // Statuscode Statushistorie 7
{0x053D0704,  CAT_STATUS,           VT_DATETIME,      8064,  STR8064,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Zeitstempel Statushistorie 8
{0x053D06FA,  CAT_STATUS,           VT_ENUM,          8065,  STR8065,  sizeof(ENUM8065),     ENUM8065,     FL_RONLY,     DEV_ALL}, // Statuscode Statushistorie 8
{0x053D0705,  CAT_STATUS,           VT_DATETIME,      8066,  STR8066,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Zeitstempel Statushistorie 9
{0x053D06FB,  CAT_STATUS,           VT_ENUM,          8067,  STR8067,  sizeof(ENUM8067),     ENUM8067,     FL_RONLY,     DEV_ALL}, // Statuscode Statushistorie 10
{0x053D0706,  CAT_STATUS,           VT_DATETIME,      8068,  STR8068,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Zeitstempel Statushistorie 10
{0x053D06FC,  CAT_STATUS,           VT_ENUM,          8069,  STR8069,  sizeof(ENUM8069),     ENUM8069,     FL_RONLY,     DEV_ALL}, // Statuscode Statushistorie 10

{0x053D17DD,  CAT_STATUS,           VT_ENUM,          8099,  STR8099,  sizeof(ENUM8006),     ENUM8099,     FL_RONLY,     DEV_ALL}, // Status Wärmepumpe im Hauptdisplay, virtueller Parameter, BSW-K

// Diagnose Kaskade
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8100,  STR8100,  sizeof(ENUM8100),     ENUM8100,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 1
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8102,  STR8102,  sizeof(ENUM8102),     ENUM8102,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 2
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8104,  STR8104,  sizeof(ENUM8104),     ENUM8104,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 3
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8106,  STR8106,  sizeof(ENUM8106),     ENUM8106,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 4
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8108,  STR8108,  sizeof(ENUM8108),     ENUM8108,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 5
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8110,  STR8110,  sizeof(ENUM8110),     ENUM8110,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 6
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8112,  STR8112,  sizeof(ENUM8112),     ENUM8112,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 7
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8114,  STR8114,  sizeof(ENUM8114),     ENUM8114,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 8
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8116,  STR8116,  sizeof(ENUM8116),     ENUM8116,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 9
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8118,  STR8118,  sizeof(ENUM8118),     ENUM8118,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 10
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8120,  STR8120,  sizeof(ENUM8120),     ENUM8120,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 11
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8122,  STR8122,  sizeof(ENUM8122),     ENUM8122,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 12
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8124,  STR8124,  sizeof(ENUM8124),     ENUM8124,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 13
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8126,  STR8126,  sizeof(ENUM8126),     ENUM8126,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 14
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8128,  STR8128,  sizeof(ENUM8128),     ENUM8128,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 15
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_ENUM,          8130,  STR8130,  sizeof(ENUM8130),     ENUM8130,     FL_RONLY,     DEV_ALL}, // Priorität / Status Erzeuger 16
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_UNKNOWN,       8138,  STR8138,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kaskadenvorlauftemperatur
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_UNKNOWN,       8139,  STR8139,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kaskadenvorlaufsollwert
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_UNKNOWN,       8140,  STR8140,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kaskadenrücklauftemperatur
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_UNKNOWN,       8141,  STR8141,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kaskadenrücklaufsollwert
{CMD_UNKNOWN, CAT_DIAG_KASKADE,     VT_UNKNOWN,       8150,  STR8150,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Erz'folge Umschalt aktuell
{0x053D0ABC,  CAT_DIAG_KASKADE,     VT_UNKNOWN,       8199,  STR8199,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kaskaden Zustand, virtueller Parameter von ACS700


//Diagnose Erzeuger
{0x053D09A0,  CAT_DIAG_ERZEUGER,    VT_ONOFF,         8300,  STR8300,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Erzeuger - 1. Brennerstufe T2
{0x053D09A1,  CAT_DIAG_ERZEUGER,    VT_ONOFF,         8301,  STR8301,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Erzeuger - 2. Brennerstufe T8
{0x050509C1,  CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8302,  STR8302,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Erzeuger - Zustand Brennerklappe Auf
{0x050509C2,  CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8303,  STR8303,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Erzeuger - Zustand Brennerklappe Zu
{0x053D09A2,  CAT_DIAG_ERZEUGER,    VT_ENUM,          8304,  STR8304,  sizeof(ENUM8304),     ENUM8304,     FL_RONLY,     DEV_ALL}, // Kesselpumpe Q1 TODO determine enum values
{0x053D0826,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8308,  STR8308,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Kesselpumpe
{0x0D3D0519,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8310,  STR8310,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Erzeuger - Kesseltemperatur
{0x0500021D,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8310,  STR8310,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [°C ] - Diagnose Erzeuger - Kesseltemperatur
{0x0500021D,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8310,  STR8310,  0,                    NULL,         FL_RONLY,     DEV_090_ALL}, // [°C ] - Diagnose Erzeuger - Kesseltemperatur
{0x0500021D,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8310,  STR8310,  0,                    NULL,         FL_RONLY,     DEV_108_ALL}, // [°C ] - Diagnose Erzeuger - Kesseltemperatur
{0x0500021D,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8310,  STR8310,  0,                    NULL,         FL_RONLY,     DEV_119_ALL}, // [°C ] - Diagnose Erzeuger - Kesseltemperatur
{0x0500021D,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8310,  STR8310,  0,                    NULL,         FL_RONLY,     DEV_205_ALL}, // [°C ] - Diagnose Erzeuger - Kesseltemperatur
{0x0500021D,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8310,  STR8310,  0,                    NULL,         FL_RONLY,     DEV_211_ALL}, // [°C ] - Diagnose Erzeuger - Kesseltemperatur
{0x0D3D0923,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8311,  STR8311,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Erzeuger - Kesselsollwert
{0x193D0923,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8311,  STR8311,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [°C ] - Diagnose Erzeuger - Kesselsollwert - logged on OCI700 by LPB
{0x053D0B26,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8312,  STR8312,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kesselschaltpunkt
{0x053D130C,  CAT_DIAG_ERZEUGER,    VT_ENUM,          8313,  STR8313,  sizeof(ENUM8313),     ENUM8313,     FL_RONLY,     DEV_ALL}, // Regelfühler
{0x113D051A,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8314,  STR8314,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Erzeuger - Kesselrücklauftemperatur
{0x0500021E,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8314,  STR8314,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [°C ] - Diagnose Erzeuger - Kesselrücklauftemperatur
{0x0500021E,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8314,  STR8314,  0,                    NULL,         FL_RONLY,     DEV_NONE}, // [°C ] - Diagnose Erzeuger - Kesselrücklauftemperatur
{0x113D0B64,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8315,  STR8315,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kesselrücklaufsollwert
{0x053D051D,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8316,  STR8316,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Erzeuger - Abgastemperatur
{0x053D051C,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8318,  STR8318,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Erzeuger - Abgastemperatur Maximum
{0x053D130E,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8319,  STR8319,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Teil 2 zu 8310 an Brötje WMS 24 "Regeltemperatur"
{0x053D130D,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8320,  STR8320,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Teil 2 zu 8311 an Brötje WMS 24 "Regelsollwert"
{0x113D0C86,  CAT_USER_DEFINED,     VT_TEMP,          8321,  STR8321,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Virtual parameter logged on OCI420 via ACS700 diagnosis software: Aktuelle Regeldifferenz
{0x093D0E69,  CAT_DIAG_ERZEUGER,    VT_SPEED2,        8323,  STR8323,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gebläsedrehzahl - Broetje NovoCondens WOB20-25
{0x113D0C82,  CAT_DIAG_ERZEUGER,    VT_SPEED2,        8323,  STR8323,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // Gebläsedrehzahl - Elco Thision S 17.1 - logged on OCI700 via LPB
{0x21050518,  CAT_DIAG_ERZEUGER,    VT_SPEED2,        8323,  STR8323,  0,                    NULL,         FL_RONLY,     DEV_076_ALL}, // Gebläsedrehzahl - Elco Thision S 17.1
{0x21050518,  CAT_DIAG_ERZEUGER,    VT_SPEED2,        8323,  STR8323,  0,                    NULL,         FL_RONLY,     DEV_097_ALL}, // Gebläsedrehzahl - Elco Thision S 17.1
{0x21050518,  CAT_DIAG_ERZEUGER,    VT_SPEED2,        8323,  STR8323,  0,                    NULL,         FL_RONLY,     DEV_119_ALL}, // Gebläsedrehzahl - Elco Thision S 17.1
{0x0D3D0C82,  CAT_DIAG_ERZEUGER,    VT_SPEED2,        8324,  STR8324,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // WGBS Diagnose Erzeuger - Gebläsedrehzahl - logged on OCI700 via LPB
{0x093D0E6A,  CAT_DIAG_ERZEUGER,    VT_UINT,          8324,  STR8324,  0,                    NULL,         FL_RONLY,     DEV_096_ALL}, // WGBS Diagnose Erzeuger - Gebläsedrehzahl
{0x093D0E6A,  CAT_DIAG_ERZEUGER,    VT_SPEED2,        8324,  STR8324,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // WGBS Diagnose Erzeuger - Gebläsedrehzahl
{0x093D0E6A,  CAT_DIAG_ERZEUGER,    VT_UINT,          8324,  STR8324,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // WGBS Diagnose Erzeuger - Gebläsedrehzahl
{0x093D0E6A,  CAT_DIAG_ERZEUGER,    VT_UINT,          8324,  STR8324,  0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // WGBS Diagnose Erzeuger - Gebläsedrehzahl
{0x093D0E6A,  CAT_DIAG_ERZEUGER,    VT_UINT,          8324,  STR8324,  0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // WGBS Diagnose Erzeuger - Gebläsedrehzahl
{0x113D305D,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8324,  STR8324,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision Diagnose Erzeuger - Gebläsedrehzahl
{0x093D0E00,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8325,  STR8325,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Akt. Gebläsesteuerung - Broetje NovoCondens WOB20-25
{0x11050C83,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8325,  STR8325,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // Akt. Gebläsesteuerung - Broetje NovoCondens WOB20-25 - logged on OCI700 via LPB
{0x093D0E00,  CAT_DIAG_ERZEUGER,    VT_PERCENT_100,   8325,  STR8325_2,0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // Akt. Gebläsesteuerung - Broetje NovoCondens WOB20-25
{0x0D3D0C85,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8326,  STR8326,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // WGBS Brennermodulation - logged on OCI700 via LPB
{0x053D0834,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8326,  STR8326,  0,                    NULL,         FL_RONLY,     DEV_090_ALL}, // WGBS Brennermodulation
{0x053D0834,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8326,  STR8326,  0,                    NULL,         FL_RONLY,     DEV_096_ALL}, // WGBS Brennermodulation
{0x053D0834,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8326,  STR8326,  0,                    NULL,         FL_RONLY,     DEV_103_ALL}, // WGBS Brennermodulation
{0x053D0834,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8326,  STR8326,  0,                    NULL,         FL_RONLY,     DEV_107_ALL}, // WGBS Brennermodulation
{0x053D0834,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8326,  STR8326,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // WGBS Brennermodulation
{0x053D0834,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8326,  STR8326,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // WGBS Brennermodulation
{0x053D0834,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8326,  STR8326,  0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // WGBS Brennermodulation
{0x053D0834,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8326,  STR8326,  0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // WGBS Brennermodulation
{0x113D305F,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8326,  STR8326,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision Brennermodulation
{0x113D3063,  CAT_DIAG_ERZEUGER,    VT_PRESSURE_WORD, 8327,  STR8327,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision Wasserdruck
{0x053D19F0,  CAT_DIAG_ERZEUGER,    VT_PRESSURE_WORD, 8327,  STR8327,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // Wasserdruck
{0x093D3034,  CAT_DIAG_ERZEUGER,    VT_BYTE,          8328,  STR8328,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision Betriebsanzeige FA [?]
{0x153D2FF0,  CAT_DIAG_ERZEUGER,    VT_CURRENT1000,   8329,  STR8329,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // WGBS Ionisationsstrom [uA?] - logged on OCI700 via LPB
{0x093D0E16,  CAT_DIAG_ERZEUGER,    VT_CURRENT,       8329,  STR8329,  0,                    NULL,         FL_RONLY,     DEV_096_ALL}, // WGBS Ionisationsstrom [uA?]
{0x093D0E16,  CAT_DIAG_ERZEUGER,    VT_CURRENT,       8329,  STR8329,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // WGBS Ionisationsstrom [uA?]
{0x093D0E16,  CAT_DIAG_ERZEUGER,    VT_CURRENT,       8329,  STR8329,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // WGBS Ionisationsstrom [uA?]
{0x093D0E16,  CAT_DIAG_ERZEUGER,    VT_CURRENT,       8329,  STR8329,  0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // WGBS Ionisationsstrom [uA?]
{0x093D0E16,  CAT_DIAG_ERZEUGER,    VT_CURRENT,       8329,  STR8329,  0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // WGBS Ionisationsstrom [uA?]
{0x153D2FF0,  CAT_DIAG_ERZEUGER,    VT_CURRENT,       8329,  STR8329,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision Ionisationsstrom [uA?]
{0x0D3D093B,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8330,  STR8330,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [h ] - Diagnose Erzeuger - Betriebstunden 1.Stufe
{0x053D08A5,  CAT_DIAG_ERZEUGER,    VT_DWORD,         8331,  STR8331,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Erzeuger - Startzaehler 1.Stufe
{0x0D3D093D,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8332,  STR8332,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [h ] - Diagnose Erzeuger - Betriebsstunden 2. Stufe
{0x053D08A6,  CAT_DIAG_ERZEUGER,    VT_DWORD,         8333,  STR8333,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Erzeuger - Startzaehler 2.Stufe
{0x093D3036,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8336,  STR8336,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision Betriebsstunden Brenner
{0x053D0011,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8336,  STR8336,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // Thision Betriebsstunden Brenner - logged on OCI700 via LPB
{0x093D3035,  CAT_DIAG_ERZEUGER,    VT_DWORD,         8337,  STR8337,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision Startzähler Brenner
{0x39ED093F,  CAT_DIAG_ERZEUGER,    VT_UINT5,         8337,  STR8337,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // Thision Startzähler Brenner - logged on OCI700 via LPB
{0x053D2FEB,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8338,  STR8338,  0,                    NULL,         FL_RONLY,     DEV_096_ALL}, // WGBS Betriebsstunden Heizbetrieb
{0x053D2FEB,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8338,  STR8338,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // WGBS Betriebsstunden Heizbetrieb
{0x053D2FEB,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8338,  STR8338,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // WGBS Betriebsstunden Heizbetrieb
{0x053D2FEB,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8338,  STR8338,  0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // WGBS Betriebsstunden Heizbetrieb
{0x053D2FEB,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8338,  STR8338,  0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // WGBS Betriebsstunden Heizbetrieb
{0x193D2FEB,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8338,  STR8338,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision Betriebsstunden Heizbetrieb
{0x053D2FEC,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8339,  STR8339,  0,                    NULL,         FL_RONLY,     DEV_096_ALL}, // WGBS Betriebsstunden TWW
{0x053D2FEC,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8339,  STR8339,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // WGBS Betriebsstunden TWW
{0x053D2FEC,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8339,  STR8339,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // WGBS Betriebsstunden TWW
{0x053D2FEC,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8339,  STR8339,  0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // WGBS Betriebsstunden TWW
{0x053D2FEC,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8339,  STR8339,  0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // WGBS Betriebsstunden TWW
{0x193D2FEC,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8339,  STR8339,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision Betriebsstunden TWW
{0x193D2FED,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8340,  STR8340,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision Betriebsstunden Zonen
{0x053D1A7A,  CAT_DIAG_ERZEUGER,    VT_ENERGY,        8378,  STR8378,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gesamt Gasenergie Heizen
{0x053D1A7B,  CAT_DIAG_ERZEUGER,    VT_ENERGY,        8379,  STR8379,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gesamt Gasenergie Trinkwasser
{0x053D1A7C,  CAT_DIAG_ERZEUGER,    VT_ENERGY,        8380,  STR8380,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gesamt Gasenergie
{0x053D1A7D,  CAT_DIAG_ERZEUGER,    VT_ENERGY,        8381,  STR8381,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gasenergie Heizen (Reset?)
{0x053D1A7E,  CAT_DIAG_ERZEUGER,    VT_ENERGY,        8382,  STR8382,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gasenergie Trinkwasser (Reset?)
{0x053D1A7F,  CAT_DIAG_ERZEUGER,    VT_ENERGY,        8383,  STR8383,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gasenergie
{0x093D0DFD,  CAT_DIAG_ERZEUGER,    VT_ENUM,          8390,  STR8390,  sizeof(ENUM8390),     ENUM8390,     FL_RONLY,     DEV_ALL}, // Aktuelle Phasennummer - Broetje NovoCondens WOB20-25
{0x053D19D8,  CAT_DIAG_ERZEUGER,    VT_POWER100,      8395,  STR8395,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Wärmeabgabe in kW // Broetje BSW-K
{0x053D19DA,  CAT_DIAG_ERZEUGER,    VT_DWORD,         8396,  STR8396,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Wärmeabgabe Quelle in kW // Broetje BSW-K
{0x053D19D9,  CAT_DIAG_ERZEUGER,    VT_DWORD,         8397,  STR8397,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Leistungsaufnahme in kW // Broetje BSW-K
{0x053D19DB,  CAT_DIAG_ERZEUGER,    VT_POWER_WORD,    8398,  STR8398,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Leistungszahl

// Diagnose Erzeuger - Wärmepumpe
{0x053D09B5,  CAT_DIAG_ERZEUGER,    VT_ONOFF,         8400,  STR8400,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Verdichter 1 K1
{0x053D09B6,  CAT_DIAG_ERZEUGER,    VT_ONOFF,         8401,  STR8401,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Verdichter 2 K2
{0x053D0AD1,  CAT_DIAG_ERZEUGER,    VT_ONOFF,         8402,  STR8402,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Elektroeinsatz 1 Vorlauf //FUJITSU ("Elektrischer Widerstand 1 Ausgang")
{0x053D09BE,  CAT_DIAG_ERZEUGER,    VT_ONOFF,         8403,  STR8403,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Elektroeinsatz 2 Vorlauf //FUJITSU
{0x053D09B8,  CAT_DIAG_ERZEUGER,    VT_ONOFF,         8404,  STR8404,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Quellenpu Q8 / Ventilat K19
{0x053D0B35,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8405,  STR8405,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Quellenpumpe
{0x053D09B9,  CAT_DIAG_ERZEUGER,    VT_ONOFF,         8406,  STR8406,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kondensatorpumpe Q9 //FUJITSU
{0x053D167A,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8407,  STR8407,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Kondensatorpumpe
{0x053D0AB3,  CAT_DIAG_ERZEUGER,    VT_ONOFF,         8408,  STR8408,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kühlumlenkventil Quelle
{0x593D0537,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8410,  STR8410,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Rücklauftemperatur WP //FUJITSU
{0x593D0767,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8411,  STR8411,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Sollwert WP //FUJITSU
{0x593D052D,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8412,  STR8412,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Vorlauftemperatur WP //FUJITSU
{0x053D0D2A,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8413,  STR8413,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Modulation des Kompressors //FUJITSU
{0x053D12F4,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8414,  STR8414,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Elektro-Vorlauf Modulation //FUJITSU
{0x593D05BF,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8415,  STR8415,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Heissgastemperatur 1
{0x593D05A8,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8416,  STR8416,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Heissgastemperatur Max
{0x593D05C0,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8417,  STR8417,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Heissgastemperatur 2
{0x593D05C8,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8420,  STR8420,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kältemitteltemperatur flüssig
{0x053D163C,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8423,  STR8423,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kondensatortemperatur
{0x593D05C3,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8425,  STR8425,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Temp’spreizung Kondensator //FUJITSU
{0x593D05C2,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8426,  STR8426,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Temp’spreizung Verdampfer
{0x593D05B9,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8427,  STR8427,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Quelle Eintrittstemperatur
{0x593D176A,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8428,  STR8428,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Quelle Eintritt Min
{0x593D05BA,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8429,  STR8429,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Quelle Austrittstemperatur
// Ausschaltschwelle 0x593D0766
{0x593D1769,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8430,  STR8430,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Quelle Austritt Min
{0x053D195A,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8431,  STR8431,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Quellenzw'kreis Vorlauftemp
{0x053D196D,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8434,  STR8434,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Sauggastemperatur
{0x053D163B,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8435,  STR8435,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Verdampfungstemperatur
{0x593D1662,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8436,  STR8436,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Überhitzung oder Überhitzungssollwert
// vorheriges könnte auch 1663 sein weil da noch Überhitzungssollwert übermittelt wird
{0x053D163A,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8437,  STR8437,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Expansionsventil // kein Funktion
{0x053D165B,  CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8438,  STR8438,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Magnetventil
{0x593D0BD4,  CAT_DIAG_ERZEUGER,    VT_MINUTES_SHORT, 8440,  STR8440,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Rest Stufe 1 Stillst’zeit Min
{0x593D0BD5,  CAT_DIAG_ERZEUGER,    VT_MINUTES_SHORT, 8441,  STR8441,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Rest Stufe 2 Stillst’zeit Min
{0x593D0BD6,  CAT_DIAG_ERZEUGER,    VT_MINUTES_SHORT, 8442,  STR8442,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Rest Stufe 1 Laufzeit Min
{0x593D0BD7,  CAT_DIAG_ERZEUGER,    VT_MINUTES_SHORT, 8443,  STR8443,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Rest Stufe 2 Laufzeit Min
{0x593D0BCB,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8444,  STR8444,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Restzeit Begr Quelle TempMin
{0x593D05C9,  CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8446,  STR8446,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Verdichterfolge // 1- 2 ??
{0x593D19AF,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8448,  STR8448,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Betr'std erw Verdampf'temp // RESET ?
{0x593D189B,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8449,  STR8449,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Betr'stunden Kältekreis
{0x593D0897,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8450,  STR8450,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Betr’stunden Verdichter 1 //FUJITSU
{0x593D089B,  CAT_DIAG_ERZEUGER,    VT_DWORD,         8451,  STR8451,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Startzähler Verdichter 1
{0x593D0898,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8452,  STR8452,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Betr’stunden Verdichter 2
{0x593D089C,  CAT_DIAG_ERZEUGER,    VT_DWORD,         8453,  STR8453,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Startzähler Verdichter 2
{0x593D06C6,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8454,  STR8454,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Sperrdauer WP //FUJITSU
{0x593D06C1,  CAT_DIAG_ERZEUGER,    VT_DWORD,         8455,  STR8455,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Zähler Anzahl Sperren WP //FUJITSU
{0x593D06C5,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8456,  STR8456,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Betr’stunden Elektro Vorl //FUJITSU
{0x593D06C0,  CAT_DIAG_ERZEUGER,    VT_DWORD,         8457,  STR8457,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Startzähler Elektro Vorlauf //FUJITSU
// ab hier zu testen
{0x053D196E,  CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8458,  STR8458,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Status Smart Grid // todo: ENUM ? Keine Funktion
{0x053D130F,  CAT_DIAG_ERZEUGER,    VT_LITERPERMIN,   8460,  STR8460,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Wärmepumpendurchfluss // FUJITSU
{0x053D19E6,  CAT_DIAG_ERZEUGER,    VT_LITERPERMIN,   8461,  STR8461,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Quellendurchfluss // FUJITSU
{0x053D1760,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8462,  STR8462,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Sauggasttemperatur EVI
{0x593D17AD,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8463,  STR8463,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Verdampfungstemperatur EVI
// Kommt auch noch ein Telegramm 0x593D1779, könnte Verdampfungsdruck E in bar sein oder vertauscht mit dem oben
{0x593D17AB,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8464,  STR8464,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Überhitzung EVI
// Kommt auch noch ein Telegramm 0x593D17AC, könnte Überhitzungssollwert E in °C sein oder vertauscht mit dem oben
{0x053D17AA,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8465,  STR8465,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Expansionsventil EVI
{0x053D165C,  CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8466,  STR8466,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Magnetventil EVI // Keine Funktion
{0x053D165D,  CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8467,  STR8467,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Mag'ventil Einspritzkapillare // todo: ENUM ? Keine Funktion
{CMD_UNKNOWN, CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8469,  STR8469,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Ventilator
{CMD_UNKNOWN, CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8470,  STR8470,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Ventilator K19
{0x053D0A02,  CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8471,  STR8471,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Prozessumkehrventil // Keine Funktion
{CMD_UNKNOWN, CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8475,  STR8475,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Verdampfertemperatur
{CMD_UNKNOWN, CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8477,  STR8477,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Temp'diff Abtauen Istwert
{CMD_UNKNOWN, CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8478,  STR8478,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Temp'diff Abtauen Sollwert
{CMD_UNKNOWN, CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8480,  STR8480,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Restzeit Abtausperrung
{CMD_UNKNOWN, CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8481,  STR8481,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Restzeit Zwangsabtauen
{CMD_UNKNOWN, CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8482,  STR8482,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Restzeit Abtaustabilisierung
{CMD_UNKNOWN, CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8485,  STR8485,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Anzahl Abtauversuche
{CMD_UNKNOWN, CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8487,  STR8487,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Status Abtauen WP

// Diagnose Erzeuger - Solar
{0x053D09AB,  CAT_DIAG_ERZEUGER,    VT_ONOFF,         8499,  STR8499,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kollektorpumpe 1 (Aus) - Broetje NovoCondens WOB20-25
{0x053D09AB,  CAT_DIAG_ERZEUGER,    VT_ONOFF,         8499,  STR8499_2,0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // Kollektorpumpe 1  - Broetje EcoTherm WMS 24
{0x053D0A89,  CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8501,  STR8501,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Solarstellglied Puffer - Broetje NovoCondens WOB20-25
{0x053D0A8B,  CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8502,  STR8502,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Solarstellglied Schwimmbad - Broetje NovoCondens WOB20-25
{0x493D04CE,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8505,  STR8505,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Kollektorpumpe 1
{0x053D0825,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8506,  STR8506,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Solarpump ext.Tau
{0x053D0823,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8507,  STR8507,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Solarpumpe Puffer
{0x053D0824,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8508,  STR8508,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Solarpump Sch'bad
{0x493D052A,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8510,  STR8510,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Erzeuger - Kollektortemperatur 1
{0x053D052A,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8510,  STR8510,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [°C ] - Diagnose Erzeuger - Kollektortemperatur 1 - logged on OCI700 via LPB
{0x053D052A,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8510,  STR8510,  0,                    NULL,         FL_RONLY,     DEV_076_ALL}, // [°C ] - Diagnose Erzeuger - Kollektortemperatur 1
{0x493D053F,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8511,  STR8511,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Erzeuger - Kollektortemperatur 1 Max
{0x493D0718,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8512,  STR8512,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Erzeuger - Kollektortemperatur 1 Min
{0x493D053B,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8513,  STR8513,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Erzeuger - dT Kollektor 1/TWW
{0x493D053B,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8513,  STR8513_2,0,                    NULL,         FL_RONLY,     DEV_096_ALL}, // [°C ] - Diagnose Erzeuger - dT Kollektor 1/TWW
{0x493D053C,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8514,  STR8514,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Erzeuger - dT Kollektor 1/Puffer
{0x493D042E,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8515,  STR8515,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // dT Kollektor 1 / Schwimmbad
{0x493D050E,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8519,  STR8519,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Solarvorlauftemperatur
{0x493D050F,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8520,  STR8520,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Solarrücklauftemperatur
{0x053D12F6,  CAT_DIAG_ERZEUGER,    VT_UNKNOWN,       8521,  STR8521,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Solardurchfluss
{0x493D0599,  CAT_DIAG_ERZEUGER,    VT_ENERGY_WORD,   8526,  STR8526,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Tagesertrag Solarenergie
{0x493D0598,  CAT_DIAG_ERZEUGER,    VT_ENERGY10,      8527,  STR8527,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gesamtertrag Solarenergie
{0x493D0893,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8530,  STR8530,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [h ] - Diagnose Erzeuger - Betr`stunden Solarertrag
{0x15050893,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8530,  STR8530,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [h ] - Diagnose Erzeuger - Betr`stunden Solarertrag - logged on OCI700 via LPB
{0x493D0717,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8531,  STR8531,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [h ] - Diagnose Erzeuger - Betr`stunden Kollektor`überhitz
{0x053D10A5,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8532,  STR8532,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Betr`stunden Kollektorpumpe - Broetje NovoCondens WOB20-25
{0x053D0822,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8543,  STR8543,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Kollektorpumpe
{0x493D052B,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8547,  STR8547,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kollektortemperatur 2
{0x493D0540,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8548,  STR8548,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kollektortemperatur 2 Max
{0x493D0ADB,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8549,  STR8549,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kollektortemperatur 2 Min
{0x493D053D,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8550,  STR8550,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // dT Kollektor 2 / TWW
{0x493D053E,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8551,  STR8551,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // dT Kollektor 2 / Puffer
{0x493D042F,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8552,  STR8552,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // dT Kollektor 2 / Schwimmbad
{0x513D0882,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8559,  STR8559,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // !!! TODO: Parameternummer unklar !!! [°C ] - Diagnose Erzeuger - Feststoffkesselsollwert
{0x513D052E,  CAT_DIAG_ERZEUGER,    VT_TEMP,          8560,  STR8560,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Erzeuger - Feststoffkesseltemperatur
{0x513D04CF,  CAT_DIAG_ERZEUGER,    VT_PERCENT,       8568,  STR8568,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Festst'pumpe
{0x513D0892,  CAT_DIAG_ERZEUGER,    VT_HOURS,         8570,  STR8570,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Betr'std Feststoffkessel

// Diagnose Verbraucher
{0x053D0521,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8700,  STR8700,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Aussentemperatur
{0x0500021F,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8700,  STR8700,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [°C ] - Diagnose Verbraucher - Aussentemperatur
{0x0500021F,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8700,  STR8700,  0,                    NULL,         FL_RONLY,     DEV_090_ALL}, // [°C ] - Diagnose Verbraucher - Aussentemperatur
{0x0500021F,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8700,  STR8700,  0,                    NULL,         FL_RONLY,     DEV_097_100}, // [°C ] - Diagnose Verbraucher - Aussentemperatur
{0x053D056F,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8701,  STR8701,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Außentemperatur Minimum
{0x053D056E,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8702,  STR8702,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Außentemperatur Maximum
{0x053D05F0,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8703,  STR8703,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Aussentemperatur gedaempft
{0x053D05F2,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8704,  STR8704,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Aussentemperatur gemischt
// Virtueller Parameter aus ACS700
{0x413D021F,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8705,  STR8705,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Außentemperatur LPB
{0x053D0806,  CAT_DIAG_VERBRAUCHER, VT_PERCENT,       8720,  STR8720,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Relative Raumfeuchte
{0x053D0B84,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8721,  STR8721,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Raumtemperatur
{0x653D0B72,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8722,  STR8722,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Taupunkttemperatur
{0x053D09A5,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         8730,  STR8730,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Heizkreispumpe Q2
{0x053D09A6,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         8731,  STR8731,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Heizkreismischer Auf Y1
{0x053D09A7,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         8732,  STR8732,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Heizkreismischer Zu Y2
{0x213D04A7,  CAT_DIAG_VERBRAUCHER, VT_PERCENT,       8735,  STR8735,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Heizkreispumpe 1
{0x2D3D051E,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8740,  STR8740,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Raumtemperatur 1
{0x2D3D0593,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8741,  STR8741,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Raumsollwert 1
{0x2D3D0593,  CAT_DIAG_VERBRAUCHER, VT_TEMP_WORD5_US, 8741,  STR8741,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [°C ] - Diagnose Verbraucher - Raumsollwert 1 - logged on OCI700 via LPB
{0x2D3D05E9,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8742,  STR8742,  0,                    NULL,         FL_OEM,       DEV_ALL}, // Thision 8742 Raumtemperatur 1 Modell [°C]
{0x213D0518,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8743,  STR8743,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Vorlauftemperatur 1 Alarm
{0x213D0667,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8744,  STR8744,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert 1
{0x053D0C7D,  CAT_DIAG_VERBRAUCHER, VT_ENUM,          8749,  STR8749,  sizeof(ENUM8749),     ENUM8749,     FL_RONLY,     DEV_ALL}, // Raumthermostat 1
{0x053D04A2,  CAT_DIAG_VERBRAUCHER, VT_PERCENT,       8750,  STR8750,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision 8750 Mod Pumpe Sollwert [%]
{0x153D04A2,  CAT_DIAG_VERBRAUCHER, VT_PERCENT,       8750,  STR8750,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // Thision 8750 Mod Pumpe Sollwert [%] - logged on OCI700 via LPB
{0x053D0A81,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       8751,  STR8751,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kühlkreispumpe Q24
{0x053D0A82,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       8752,  STR8752,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kühlkreismischer Auf Y23
{0x053D0A83,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       8753,  STR8753,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Kühlkreismischer Zu Y24
{0x053D0A01,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       8754,  STR8754,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Umlenkventil Kühlen Y21
{0x693D0A1D,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8756,  STR8756,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Vorlauftemperatur Kühlen 1 //FUJITSU
{0x693D0A79,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8757,  STR8757,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Vorlaufsollwert Kühlen1
{0x053D09A8,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         8760,  STR8760,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Heizkreispumpe Q6
{0x053D09A9,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         8761,  STR8761,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Heizkreismischer Auf Y5
{0x053D09AA,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         8762,  STR8762,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Heizkreismischer Zu Y6
{0x223D04A7,  CAT_DIAG_VERBRAUCHER, VT_PERCENT,       8765,  STR8765,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Heizkreispumpe 2
{0x2E3D051E,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8770,  STR8770,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Raumtemperatur 2
{0x2E3D0593,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8771,  STR8771,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Raumsollwert 2
{0x2E3D05E9,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8772,  STR8772,  0,                    NULL,         FL_OEM,       DEV_ALL}, // Thision 8772 Raumtemperatur 2 Modell [°C]
{0x223D0518,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8773,  STR8773,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Vorlauftemperatur 2
{0x2E3D0C81,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8773,  STR8773,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [°C ] - Diagnose Verbraucher - Vorlauftemperatur 2 - logged on OCI700 via LPB
{0x223D0667,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8774,  STR8774,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert 2
{0x063D0C7D,  CAT_DIAG_VERBRAUCHER, VT_ENUM,          8779,  STR8779,  sizeof(ENUM8779),     ENUM8779,     FL_RONLY,     DEV_ALL}, // Raumthermostat 2
{0x053D09B0,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         8790,  STR8790,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Heizkreispumpe 3
{0x053D0AA7,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         8791,  STR8791,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Heizkreismischer 3 Auf
{0x053D0AA8,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         8792,  STR8792,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Heizkreismischer 3 Zu
{0x233D04A7,  CAT_DIAG_VERBRAUCHER, VT_PERCENT,       8795,  STR8795,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Heizkreispumpe P
{0x2F3D051E,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8800,  STR8800,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Raumtemperatur P
{0x2F3D0593,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8801,  STR8801,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Raumsollwert P
{0x2F3D05E9,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8802,  STR8802,  0,                    NULL,         FL_OEM,       DEV_ALL}, // [°C ] - Diagnose Verbraucher - Raumtemperatur P Modell
{0x233D0667,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8803,  STR8803,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsol wert P
{0x233D0518,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8804,  STR8804,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsol wert P
{0x073D0C7D,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         8809,  STR8809,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Raumthermostat 3
{0x053D09A3,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         8820,  STR8820,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Trinkwasserpumpe Q3
{0x053D09AE,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         8821,  STR8821,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Elektroeinsatz TWW K6 //FUJITSU ("Elektrischer Widerstand TWW")
{0x253D04A4,  CAT_DIAG_VERBRAUCHER, VT_PERCENT,       8825,  STR8825,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Trinkwasserpumpe
{0x253D0B27,  CAT_DIAG_VERBRAUCHER, VT_PERCENT,       8826,  STR8826,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl TWW Zw'kreispumpe
{0x053D0B2A,  CAT_DIAG_VERBRAUCHER, VT_PERCENT,       8827,  STR8827,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Drehzahl Dl'erhitzerpumpe
{0x313D052F,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8830,  STR8830,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Trinkwassertemperatur 1
{0x313D074B,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8831,  STR8831,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Trinkwassersollwert
{0x313D0532,  CAT_DIAG_VERBRAUCHER, VT_TEMP_WORD5_US, 8831,  STR8831,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [°C ] - Diagnose Verbraucher - Trinkwassersollwert - logged on OCI700 via LPB
{0x313D0530,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8832,  STR8832,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Trinkwassertemperatur 2
{0x253D0C80,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8832,  STR8832,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [°C ] - Diagnose Verbraucher - Trinkwassertemperatur 2 - logged on OCI700 via LPB
{0x253D077D,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8835,  STR8835,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - TWW Zirkulationstemperatur
{0x253D0B33,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8836,  STR8836,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // TWW Ladetemperatur
{0x253D0B25,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8836,  STR8836,  0,                    NULL,         FL_RONLY,     DEV_090_ALL}, // TWW Ladetemperatur
{0x253D0B25,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8836,  STR8836,  0,                    NULL,         FL_RONLY,     DEV_103_ALL}, // TWW Ladetemperatur
{0x253D0B25,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8836,  STR8836,  0,                    NULL,         FL_RONLY,     DEV_107_ALL}, // TWW Ladetemperatur
{0x253D0B25,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8836,  STR8836,  0,                    NULL,         FL_RONLY,     DEV_108_ALL}, // TWW Ladetemperatur
{0x253D0B25,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8836,  STR8836,  0,                    NULL,         FL_RONLY,     DEV_116_ALL}, // TWW Ladetemperatur
{0x253D0B25,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8836,  STR8836,  0,                    NULL,         FL_RONLY,     DEV_119_ALL}, // TWW Ladetemperatur
{0x253D0B25,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8836,  STR8836,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // TWW Ladetemperatur
{0x253D0B25,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8836,  STR8836,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // TWW Ladetemperatur
{0x253D0B25,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8836,  STR8836,  0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // TWW Ladetemperatur
{0x253D0B25,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8836,  STR8836,  0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // TWW Ladetemperatur
{0x253D0B25,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8836,  STR8836,  0,                    NULL,         FL_RONLY,     DEV_205_ALL}, // TWW Ladetemperatur
{0x253D0B25,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8836,  STR8836,  0,                    NULL,         FL_RONLY,     DEV_211_ALL}, // TWW Ladetemperatur
{0x253D06C2,  CAT_DIAG_VERBRAUCHER, VT_HOURS,         8840,  STR8840,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Betr’stunden TWW-Pumpe //FUJITSU
{0x253D06BD,  CAT_DIAG_VERBRAUCHER, VT_DWORD,         8841,  STR8841,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Startzähler TWW-Pumpe //FUJITSU
{0x253D06C3,  CAT_DIAG_VERBRAUCHER, VT_HOURS,         8842,  STR8842,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Betr’stunden Elektro TWW //FUJITSU
{0x253D06BE,  CAT_DIAG_VERBRAUCHER, VT_DWORD,         8843,  STR8843,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Startzähler Elektro TWW //FUJITSU
{0x253D0B18,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8850,  STR8850,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // TWW Vorreglertemperatur
{0x253D0B36,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8851,  STR8851,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // TWW Vorreglersollwert
{0x313D0B24,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8852,  STR8852,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // TWW Durchl'erhitzertemp
{0x313D0B37,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8853,  STR8853,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // TWW Durchl'erhitzersollwert
{0x053D080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8875,  STR8875,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Vorlaufsollwert VK1
{0x063D080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8885,  STR8885,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Vorlaufsollwert VK2
{0x073D080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8895,  STR8895,  0,                    NULL,         FL_RONLY,     DEV_170_ALL}, // Vorlaufsollwert Schwimmbad //FUJITSU
{0x053D0AF9,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8900,  STR8900,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Schwimmbadtemperatur
{0x053D0AF2,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8901,  STR8901,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Schwimmbadsollwert
{0x053D08C7,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8930,  STR8930,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Vorreglertemperatur
{0x053D08C8,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8931,  STR8931,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Vorreglersollwert
{0x053D051F,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8950,  STR8950,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Schienenvorlauftemperatur
{0x053D021D,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8950,  STR8950,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // [°C ] - Diagnose Verbraucher - Schienenvorlauftemperatur - logged on OCI700 via LPB
{0x053D0783,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8951,  STR8951,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Schienenvorlaufsollwert
{0x053D0AF8,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8952,  STR8952,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Schienenrücklauftemperatur
{0x0505021E,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8952,  STR8952,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // Schienenrücklauftemperatur - logged on OCI700 via LPB
{0x053D0D28,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8957,  STR8957,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Schienenvorl'sollwert Kälte //FUJITSU
{0x053D0B61,  CAT_DIAG_VERBRAUCHER, VT_PERCENT,       8962,  STR8962,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Leistungssollwert Schiene
{CMD_UNKNOWN, CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       8970,  STR8970,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Elektroeinsatz Puffer
{0x053D0534,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8980,  STR8980,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Pufferspeichertemperatur 1
{0x053D0883,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8981,  STR8981,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Pufferspeichersollwert
{0x053D0535,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8982,  STR8982,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Pufferspeichertemperatur 2
{0x053D0536,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          8983,  STR8983,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Pufferspeichertemperatur 3
{0x053D06B7,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       8981,  STR8981,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Pufferspeichersollwert Reset?
{CMD_UNKNOWN, CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       8990,  STR8990,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Betr’stunden Elektro Puffer
{CMD_UNKNOWN, CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       8991,  STR8991,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Startzähler Elektro Puffer
{0x053D0576,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9000,  STR9000,  0,                    NULL,         FL_RONLY,     DEV_096_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H1
{0x053D080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9000,  STR9000,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H1
{0x053D0577,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9001,  STR9001,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H2
{0x0605080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9001,  STR9001,  0,                    NULL,         FL_RONLY,     DEV_090_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H2
{0x0605080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9001,  STR9001,  0,                    NULL,         FL_RONLY,     DEV_103_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H2
{0x0605080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9001,  STR9001,  0,                    NULL,         FL_RONLY,     DEV_107_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H2
{0x0605080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9001,  STR9001,  0,                    NULL,         FL_RONLY,     DEV_108_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H2
{0x0605080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9001,  STR9001,  0,                    NULL,         FL_RONLY,     DEV_119_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H2
{0x0605080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9001,  STR9001,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H2
{0x0605080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9001,  STR9001,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H2
{0x0605080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9001,  STR9001,  0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H2
{0x0605080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9001,  STR9001,  0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H2
{0x0605080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9001,  STR9001,  0,                    NULL,         FL_RONLY,     DEV_205_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H2
{0x0605080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9001,  STR9001,  0,                    NULL,         FL_RONLY,     DEV_211_ALL}, // [°C ] - Diagnose Verbraucher - Vorlaufsollwert H2
{0x073D080C,  CAT_DIAG_VERBRAUCHER, VT_TEMP,          9004,  STR9004,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Vorlaufsollwert H3
{0x053D0805,  CAT_DIAG_VERBRAUCHER, VT_PRESSURE_WORD, 9005,  STR9005,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [bar ] - Diagnose Verbraucher - Wasserdruck H1
{0x063D0805,  CAT_DIAG_VERBRAUCHER, VT_PRESSURE_WORD, 9006,  STR9006,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [bar ] - Diagnose Verbraucher - Wasserdruck H2
{0x073D0805,  CAT_DIAG_VERBRAUCHER, VT_PRESSURE_WORD, 9009,  STR9009,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [bar ] - Diagnose Verbraucher - Wasserdruck H3
{0x053D09BA,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9031,  STR9031,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX1
{0x053D09BB,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9032,  STR9032,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX2
{0x053D09BC,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9033,  STR9033,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX3
{0x053D09BD,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9034,  STR9034,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Relaisausgang QX4
{0x053D0ABD,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9035,  STR9035,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Relaisausgang QX5 //FUJITSU
{0x053D082D,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9036,  STR9036,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Relaisausgang QX6
{0x053D0D5E,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9037,  STR9037,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Relaisausgang QX7
{CMD_UNKNOWN, CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9038,  STR9038,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Relaisausgang QX8
{0x053D09F6,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9050,  STR9050,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX21 Modul 1
{0x053D09F7,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9051,  STR9051,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX22 Modul 1
{0x053D09F8,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9052,  STR9052,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX23 Modul 1
{0x053D09F9,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9053,  STR9053,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX21 Modul 2
{0x053D09FA,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9054,  STR9054,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX22 Modul 2
{0x053D09FB,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9055,  STR9055,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX23 Modul 2
{0x053D1225,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9071,  STR9071,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX31 //FUJITSU
{0x053D1226,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9072,  STR9072,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX32 //FUJITSU
{0x053D1227,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9073,  STR9073,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX33 //FUJITSU
{0x053D1228,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9074,  STR9074,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX34 //FUJITSU
{0x053D1229,  CAT_DIAG_VERBRAUCHER, VT_ONOFF,         9075,  STR9075,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // [0] - Diagnose Verbraucher - Relaisausgang QX35 //FUJITSU
// Following are virtual parameters extracted from communication betwen OCU700 and Brötje ZR1
{0x053D09B1,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9400,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 // Zustand 2. Stufe Heizkreispumpe (Q21)
{0x053D04C3,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9401,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222 // Betriebsartumschaltung Heizkreis 1 (00 = Inaktiv)
{0x053D09B2,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9402,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 // Zustand 2. Stufe Heizkreispumpe (Q22)
{0x063D04C3,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9403,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // logged from ACS700 diagnosis software: Betriebsartumschaltung Heizkreis 2 (00 = Inaktiv)
{0x053D09B3,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9404,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 // Zustand 2. Heizkreispumpe (Q23)
{0x073D04C3,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9405,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // logged from ACS700 diagnosis software: Betriebsartumschaltung Heizkreis 3/P (00 = Inaktiv)
{0x053D04B8,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9406,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // logged from ACS700 diagnosis software: Betriebsartumschaltung Trinkwasser (00 = Aus)
{0x053D09AD,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9407,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 // Zustand H1-Pumpe (Q15)
{0x053D09B4,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9408,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 // Zustand H2-Pumpe (Q18)
{0x053D09BF,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9409,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 // Zustand Zubringerpumpe (Q14)
{0x053D08BF,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9410,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // logged from ACS700 diagnosis software: Zustand Vorreglermischer Auf (Y19)
{0x053D08C0,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9411,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // logged from ACS700 diagnosis software: Zustand Vorreglermischer Zu (Y20)
{0x053D0AD7,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9412,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // logged from ACS700 diagnosis software: Zustand Zeitprogramm 5 Relais (K13)
{0x053D0B02,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9413,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // logged from ACS700 diagnosis software: Zustand Wärmeanforderung (K27)
{0x053D0B03,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9414,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // logged from ACS700 diagnosis software: Zustand Kälteanforderung (K28)
{0x053D0B04,  CAT_DIAG_VERBRAUCHER, VT_UNKNOWN,       9415,  STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // logged from ACS700 diagnosis software: Zustand Luftentfeuchter (K29)

// Feuerungsautomat
{0x2D3D3037,  CAT_FEUERUNGSAUTOMAT, VT_SECONDS_WORD5, 9500,  STR9500,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Vorlüftzeit
{0x093D10FE,  CAT_FEUERUNGSAUTOMAT, VT_SECONDS_SHORT5,9500,  STR9500,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // Vorlüftzeit
{0x093D10FE,  CAT_FEUERUNGSAUTOMAT, VT_SECONDS_SHORT5,9500,  STR9500,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // Vorlüftzeit
{0x093D10FE,  CAT_FEUERUNGSAUTOMAT, VT_SECONDS_SHORT5,9500,  STR9500,  0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // Vorlüftzeit
{0x093D10FE,  CAT_FEUERUNGSAUTOMAT, VT_SECONDS_SHORT5,9500,  STR9500,  0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // Vorlüftzeit
{0x213D3038,  CAT_FEUERUNGSAUTOMAT, VT_PERCENT_WORD,  9502,  STR9502,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gebl'ansteuerung Vorlüftung [%]
{0x223D300E,  CAT_FEUERUNGSAUTOMAT, VT_PERCENT,       9502,  STR9502,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // Gebl'ansteuerung Vorlüftung [%] - logged on OCI700 via LPB
{0x213D300F,  CAT_FEUERUNGSAUTOMAT, VT_SPEED,         9504,  STR9504,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Solldrehzahl Vorlüftung [rpm]
{0x223D300F,  CAT_FEUERUNGSAUTOMAT, VT_SPEED,         9504,  STR9504,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // Solldrehzahl Vorlüftung [rpm] - logged on OCI700 via LPB
{0x093D120B,  CAT_FEUERUNGSAUTOMAT, VT_POWER_WORD,    9504,  STR9504_2,0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // Sollleistung Vorlüftung
{0x093D120B,  CAT_FEUERUNGSAUTOMAT, VT_POWER_WORD,    9504,  STR9504_2,0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // Sollleistung Vorlüftung
{0x093D120B,  CAT_FEUERUNGSAUTOMAT, VT_POWER_WORD,    9504,  STR9504_2,0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // Sollleistung Vorlüftung
{0x093D120B,  CAT_FEUERUNGSAUTOMAT, VT_POWER_WORD,    9504,  STR9504_2,0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // Sollleistung Vorlüftung
{0x0D3D3048,  CAT_FEUERUNGSAUTOMAT, VT_PERCENT_WORD,  9510,  STR9510,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gebl'ansteuerung Zündung [%]
{0x0D3D2FC6,  CAT_FEUERUNGSAUTOMAT, VT_PERCENT,       9510,  STR9510,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // Gebl'ansteuerung Zündung [%] - logged on OCI700 via LPB
{0x0D3D2FC9,  CAT_FEUERUNGSAUTOMAT, VT_SPEED,         9512,  STR9512,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Solldrehzahl Zündung [rpm]
{0x093D120C,  CAT_FEUERUNGSAUTOMAT, VT_POWER_WORD,    9512,  STR9512,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // Sollleistung Zündlast
{0x093D120C,  CAT_FEUERUNGSAUTOMAT, VT_POWER_WORD,    9512,  STR9512_2,0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // Sollleistung Zündlast
{0x093D120C,  CAT_FEUERUNGSAUTOMAT, VT_POWER_WORD,    9512,  STR9512_2,0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // Sollleistung Zündlast
{0x093D120C,  CAT_FEUERUNGSAUTOMAT, VT_POWER_WORD,    9512,  STR9512_2,0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // Sollleistung Zündlast
{0x0D3D3049,  CAT_FEUERUNGSAUTOMAT, VT_PERCENT_WORD,  9520,  STR9520,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gebl'ansteuerung Betrieb. Min [%]
{0x0D3D2FC7,  CAT_FEUERUNGSAUTOMAT, VT_PERCENT,       9520,  STR9520,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // Gebl'ansteuerung Betrieb. Min [%] - logged on OCI700 via LPB
{0x0D3D304A,  CAT_FEUERUNGSAUTOMAT, VT_PERCENT_WORD,  9522,  STR9522,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gebl'ansteuerung Betrieb. Max [%]
{0x0D3D2FC8,  CAT_FEUERUNGSAUTOMAT, VT_PERCENT,       9522,  STR9522,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // Gebl'ansteuerung Betrieb. Max [%] - logged on OCI700 via LPB
{0x0D3D2FCA,  CAT_FEUERUNGSAUTOMAT, VT_SPEED,         9524,  STR9524,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Solldrehzahl Betrieb Min [rpm]
{0x093D120D,  CAT_FEUERUNGSAUTOMAT, VT_POWER_WORD,    9524,  STR9524_2,0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // Sollleistung Teillast
{0x093D120D,  CAT_FEUERUNGSAUTOMAT, VT_POWER_WORD,    9524,  STR9524_2,0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // Sollleistung Teillast
{0x093D120D,  CAT_FEUERUNGSAUTOMAT, VT_POWER_WORD,    9524,  STR9524_2,0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // Sollleistung Teillast
{0x093D120D,  CAT_FEUERUNGSAUTOMAT, VT_POWER_WORD,    9524,  STR9524_2,0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // Sollleistung Teillast
{0x0D3D2FCB,  CAT_FEUERUNGSAUTOMAT, VT_SPEED,         9527,  STR9527,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Solldrehzahl Betrieb Max [rpm]
{0x093D120E,  CAT_FEUERUNGSAUTOMAT, VT_POWER_WORD,    9529,  STR9529,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Sollleistung Vollast
{0x2D3D304C,  CAT_FEUERUNGSAUTOMAT, VT_SECONDS_WORD5, 9540,  STR9540,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Nachlüftzeit
{0x2E3D304C,  CAT_FEUERUNGSAUTOMAT, VT_SECONDS_WORD5, 9540,  STR9540,  0,                    NULL,         FL_RONLY,     DEV_064_ALL},  // logged from ACS700 diagnosis software, but (seemingly) not working
{0x093D10FD,  CAT_FEUERUNGSAUTOMAT, VT_SECONDS_SHORT5,9540,  STR9540,  0,                    NULL,         FL_RONLY,     DEV_123_ALL}, // Nachlüftzeit
{0x093D10FD,  CAT_FEUERUNGSAUTOMAT, VT_SECONDS_SHORT5,9540,  STR9540,  0,                    NULL,         FL_RONLY,     DEV_162_ALL}, // Nachlüftzeit
{0x093D10FD,  CAT_FEUERUNGSAUTOMAT, VT_SECONDS_SHORT5,9540,  STR9540,  0,                    NULL,         FL_RONLY,     DEV_163_ALL}, // Nachlüftzeit
{0x093D10FD,  CAT_FEUERUNGSAUTOMAT, VT_SECONDS_SHORT5,9540,  STR9540,  0,                    NULL,         FL_RONLY,     DEV_195_ALL}, // Nachlüftzeit
{0x0D3D304D,  CAT_FEUERUNGSAUTOMAT, VT_PERCENT_WORD,  9550,  STR9550,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Thision 9550 Gebl'ansteuerung Stillstand [%]
{0x253D2FE8,  CAT_FEUERUNGSAUTOMAT, VT_PERCENT_WORD,  9560,  STR9560,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gebl'ansteuerung Durchlad [%]
{0x253D2FE8,  CAT_FEUERUNGSAUTOMAT, VT_PERCENT_WORD1, 9560,  STR9560,  0,                    NULL,         FL_RONLY,     DEV_064_ALL}, // Gebl'ansteuerung Durchlad [%] - logged on OCI700 via LPB
{0x253D2FE9,  CAT_FEUERUNGSAUTOMAT, VT_SPEED,         9563,  STR9563,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Solldrehzahl Durchladung [rpm]
{0x093D12AF,  CAT_FEUERUNGSAUTOMAT, VT_UINT10,        9626,  STR9626,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gebl'Leist/Drehz Steigerung
{0x093D12B0,  CAT_FEUERUNGSAUTOMAT, VT_UINT10,        9627,  STR9627,  0,                    NULL,         FL_RONLY,     DEV_ALL}, // Gebl'Leist/Drehl Y-Abschn

//*** virtuelle Zeilen ***
// * There are a number of telegrams which need to get an "official" ProgNr assigned. Until then ProgNrs GE 10,000
// * have been assigned to those observed command codes.
// * The following command codes and function descriptions have been taken from Internet sources I don't remember
// * and should be taken with a grain of salt; they are therefore commented out.
// * Some of the command codes may be listed here with their first two bytes reversed, like the 10109 was. My
// * telegram analysis software warns about these discrepancies between the real world and the command table.
// * SET and GET commands reverse the first two bytes. If it is not a SET or GET command but the command CODE
// * matches the command TABLE "as is", then the command table has the first two bytes swapped (which is an error).
// * I have observed the 10109 (or 10000 or whatever ..) command code as 0x3d2d0215 in my own installation, see
// * the TYPE_INF telegram citation.

// Take your pick whether you assign 10000 (your choice) or 10109 (as in other sources) to this telegram
// dc 86 00 0e 02 3d 2d 02 15 05 76 00 b0 e0   Note the command code! The command table must match it.
{0x2D3D0215,  CAT_USER_DEFINED,     VT_TEMP,          10000, STR10000, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Raumtemperatur 1 (kann als INF geschickt werden)
{0x2E3D0215,  CAT_USER_DEFINED,     VT_TEMP,          10001, STR10001, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Raumtemperatur 2 (kann als INF geschickt werden)
{0x2F3D0215,  CAT_USER_DEFINED,     VT_TEMP,          10002, STR10002, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Raumtemperatur 3/P (kann als INF geschickt werden)

// Lines below seem to have found an explanation.
{0x05000213,  CAT_USER_DEFINED,     VT_UNKNOWN,       10100, STR10100, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // INFO Brenner broadcast 00 to 7F
{0x053D0213,  CAT_USER_DEFINED,     VT_UNKNOWN,       10100, STR10100, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // INFO Brenner broadcast 00 to 7F
{0x2D000211,  CAT_USER_DEFINED,     VT_UNKNOWN,       10102, STR10102, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // INFO HK1
{0x2D3D0211,  CAT_USER_DEFINED,     VT_UNKNOWN,       10102, STR10102, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // INFO HK1
{0x2E000211,  CAT_USER_DEFINED,     VT_UNKNOWN,       10103, STR10103, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // INFO HK2 broadcast 00 to 7F
{0x2E3D0211,  CAT_USER_DEFINED,     VT_UNKNOWN,       10103, STR10103, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // INFO HK2 broadcast 00 to 7F
{0x2F000211,  CAT_USER_DEFINED,     VT_UNKNOWN,       10104, STR10104, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // INFO HK3/P broadcast 00 to 7F ???
{0x2F3D0211,  CAT_USER_DEFINED,     VT_UNKNOWN,       10104, STR10104, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // INFO HK3/P broadcast 00 to 7F ???
//{0x053D0099,  CAT_USER_DEFINED,     VT_UINT,          10105, STR10105, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // SW Diagnosecode
//{0x2D3D0574,  CAT_USER_DEFINED,     VT_BYTE,          10110, STR10110, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Setzen RGT HK1
//{0x313D0571,  CAT_USER_DEFINED,     VT_BYTE,          10111, STR10111, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Trinkwasserbereitung
//{0x2E3E0574,  CAT_USER_DEFINED,     VT_BYTE,          10112, STR10112, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Heizbetrieb

// Command IDs retrieved through brute-force queries:

// 0x053D.... (größtenteils Regelung HK1)

{0x053D0006,  CAT_USER_DEFINED,     VT_UNKNOWN,       10200, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 FF
{0x053D0007,  CAT_USER_DEFINED,     VT_UNKNOWN,       10201, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x053D0010,  CAT_USER_DEFINED,     VT_UNKNOWN,       10202, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 53 FD 02 63 (seems to be subset of follwing Command ID) / on RVS43.222: 00 00 00 7A A6
{0x053D0064,  CAT_USER_DEFINED,     VT_UNKNOWN,       10203, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 61 00 88 00 04 53 FD 02 63 / on RVS43.222: 00 0A 00 00 7A A6 // last four bytes are "Herstellernummer"
{0x053D0066,  CAT_USER_DEFINED,     VT_UNKNOWN,       10204, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 31 2D 25 21 19 15 11 0D 00 00 00 00 00 00 00 00
{0x053D0068,  CAT_USER_DEFINED,     VT_UNKNOWN,       10205, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 41 30 30 36 31 30 33 00 // "Anlagenbild" (ASCII: "A006103") / on RVS43.222: (ASCII: "A0060Z2") / on ZR1: (ASCII: "A006BZ2")
{0x053D0069,  CAT_USER_DEFINED,     VT_UNKNOWN,       10206, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / on RVS43.222: 10 00
{0x053D0076,  CAT_USER_DEFINED,     VT_UNKNOWN,       10208, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // QINF message sent out by ACS700 diagnosis software
{0x053D0091,  CAT_USER_DEFINED,     VT_UNKNOWN,       10209, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x053D0094,  CAT_USER_DEFINED,     VT_UNKNOWN,       10210, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 30 30 00 00 00 00 00 00 00 00 00 00 00 00 00 00 (ASCII: "00") // "Anlagebildbeschreibung 1"
{0x053D0095,  CAT_USER_DEFINED,     VT_UNKNOWN,       10211, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 33 32 31 37 34 32 00 00 00 00 00 00 00 00 00 00 (ASCII: "321742") // "Anlagebildbeschreibung 2"
{0x053D0096,  CAT_USER_DEFINED,     VT_UNKNOWN,       10212, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 // "Anlagebildbeschreibung 3"
{0x053D0097,  CAT_USER_DEFINED,     VT_UNKNOWN,       10213, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // "Anlagebildbeschreibung 4"
{0x053D009B,  CAT_USER_DEFINED,     VT_UNKNOWN,       10214, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x053D009D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10215, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 FF 0A 19 FF FF FF FF 16 / same on RVS43.222
{0x053D009E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10216, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 FF 03 19 FF FF FF FF 16 / same on RVS43.222
{0x053D03F9,  CAT_USER_DEFINED,     VT_UNKNOWN,       10217, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 FF
{0x053D0416,  CAT_USER_DEFINED,     VT_UNKNOWN,       10218, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x053D045F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10219, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 00
{0x053D0461,  CAT_USER_DEFINED,     VT_UNKNOWN,       10220, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 00
{0x053D0465,  CAT_USER_DEFINED,     VT_UNKNOWN,       10221, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 00
{0x053D0466,  CAT_USER_DEFINED,     VT_UNKNOWN,       10222, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 00
{0x053D046D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10223, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 00
{0x053D046F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10224, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 03 E8    // dec. 1000
{0x053D0471,  CAT_USER_DEFINED,     VT_UNKNOWN,       10225, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 00
{0x053D0473,  CAT_USER_DEFINED,     VT_UNKNOWN,       10226, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 03 E8    // dec. 1000
{0x053D047F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10227, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 00 00 FF FF 00 00 00 00 00 00 00 00 00 00
{0x053D0489,  CAT_USER_DEFINED,     VT_UNKNOWN,       10228, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 00 FF 00 FF 00 00 00 00 00 00 00 00 00 00
{0x053D04B2,  CAT_USER_DEFINED,     VT_UNKNOWN,       10229, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 FF 0A 19 FF FF FF FF 16 / same on RVS43.222
{0x053D04B3,  CAT_USER_DEFINED,     VT_UNKNOWN,       10230, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 FF 03 19 FF FF FF FF 16 / same on RVS43.222
{0x053D04BB,  CAT_USER_DEFINED,     VT_UNKNOWN,       10231, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x053D0569,  CAT_USER_DEFINED,     VT_UNKNOWN,       10233, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 00
{0x053D0578,  CAT_USER_DEFINED,     VT_UNKNOWN,       10234, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 64
{0x053D058D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10235, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 01
{0x053D05D8,  CAT_USER_DEFINED,     VT_UNKNOWN,       10236, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 23 / on RVS43.222: 01 1E
{0x053D05DA,  CAT_USER_DEFINED,     VT_UNKNOWN,       10237, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 02 / on RVS43.222: 01 05
{0x053D05DD,  CAT_USER_DEFINED,     VT_UNKNOWN,       10238, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 03 / same on RVS43.222
{0x053D05A9,  CAT_USER_DEFINED,     VT_UNKNOWN,       10239, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x053D063E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10241, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 01
{0x053D0655,  CAT_USER_DEFINED,     VT_UNKNOWN,       10242, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x053D06A9,  CAT_USER_DEFINED,     VT_UNKNOWN,       10243, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x053D06AA,  CAT_USER_DEFINED,     VT_UNKNOWN,       10244, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 01
{0x053D06B0,  CAT_USER_DEFINED,     VT_UNKNOWN,       10245, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 02
{0x053D077B,  CAT_USER_DEFINED,     VT_UNKNOWN,       10246, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 00
{0x053D078D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10247, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00
{0x053D078E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10248, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 00
{0x053D079D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10249, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 02 00
{0x053D07BC,  CAT_USER_DEFINED,     VT_UNKNOWN,       10250, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 14 00
{0x053D07BD,  CAT_USER_DEFINED,     VT_UNKNOWN,       10251, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x053D07EA,  CAT_USER_DEFINED,     VT_UNKNOWN,       10253, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 01
{0x053D083E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10254, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x053D08F2,  CAT_USER_DEFINED,     VT_UNKNOWN,       10255, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 FF
{0x053D08FC,  CAT_USER_DEFINED,     VT_UNKNOWN,       10256, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 0A
{0x053D0904,  CAT_USER_DEFINED,     VT_UNKNOWN,       10257, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 78
{0x053D0905,  CAT_USER_DEFINED,     VT_UNKNOWN,       10258, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 14
{0x053D0906,  CAT_USER_DEFINED,     VT_UNKNOWN,       10259, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x053D090B,  CAT_USER_DEFINED,     VT_UNKNOWN,       10260, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 78
{0x053D0951,  CAT_USER_DEFINED,     VT_UNKNOWN,       10261, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 1E 00 / on RVS43.222: 00 00 F0
{0x053D0956,  CAT_USER_DEFINED,     VT_UNKNOWN,       10262, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 02
{0x053D0959,  CAT_USER_DEFINED,     VT_UNKNOWN,       10263, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 14
{0x053D095A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10264, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 05
{0x053D0960,  CAT_USER_DEFINED,     VT_UNKNOWN,       10265, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00
{0x053D0992,  CAT_USER_DEFINED,     VT_UNKNOWN,       10266, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00
{0x053D09A4,  CAT_USER_DEFINED,     VT_UNKNOWN,       10267, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00
{0x053D09AC,  CAT_USER_DEFINED,     VT_UNKNOWN,       10268, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00
{0x053D09AF,  CAT_USER_DEFINED,     VT_UNKNOWN,       10270, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00
{0x053D09C0,  CAT_USER_DEFINED,     VT_UNKNOWN,       10276, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00
{0x053D09C1,  CAT_USER_DEFINED,     VT_UNKNOWN,       10277, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00
{0x053D09C2,  CAT_USER_DEFINED,     VT_UNKNOWN,       10278, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00
{0x053D09C3,  CAT_USER_DEFINED,     VT_UNKNOWN,       10279, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00
{0x053D0AD3,  CAT_USER_DEFINED,     VT_UNKNOWN,       10280, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 00
{0x053D0AD4,  CAT_USER_DEFINED,     VT_UNKNOWN,       10281, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 00
{0x053D0BC4,  CAT_USER_DEFINED,     VT_UNKNOWN,       10282, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x053D306A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10284, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 FF
{0x053D306B,  CAT_USER_DEFINED,     VT_UNKNOWN,       10285, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x053D306C,  CAT_USER_DEFINED,     VT_UNKNOWN,       10286, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x053D306D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10287, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x053D306F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10288, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x053D3070,  CAT_USER_DEFINED,     VT_UNKNOWN,       10289, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x053D3071,  CAT_USER_DEFINED,     VT_UNKNOWN,       10290, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00

// 0x063D.... (größtenteils Regelung HK2)

{0x063D0799,  CAT_USER_DEFINED,     VT_UNKNOWN,       10291, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 06 B3
{0x063D306F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10292, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 FF
/*
0x063D000B and 0x053D000B have same payload
0x063D006C and 0x053D006C have same payload
0x063D0000 and 0x053D0000 have same payload
0x063D0001 and 0x053D0001 have same payload
0x063D0002 and 0x053D0002 have same payload
0x063D0003 and 0x053D0003 have same payload
0x063D0004 and 0x053D0004 have same payload
0x063D0006 and 0x053D0006 have same payload
0x063D0007 and 0x053D0007 have same payload
0x063D000C and 0x0500000C have same payload
0x063D000E and 0x053D000E have same payload
0x063D0010 and 0x053D0010 have same payload
0x063D0011 and 0x053D0011 have same payload
0x063D0064 and 0x053D0064 have same payload
0x063D0066 and 0x053D0066 have same payload
0x063D0068 and 0x053D0068 have same payload
0x063D0069 and 0x053D0069 have same payload
0x063D006A and 0x053D006A have same payload
0x063D006B and 0x053D006B have same payload
0x063D006D and 0x053D006D have same payload
0x063D0071 and 0x053D0071 have same payload
0x063D0072 and 0x053D0072 have same payload
0x063D0073 and 0x053D0073 have same payload
0x063D0075 and 0x053D0075 have same payload
0x063D0090 and 0x053D0090 have same payload
0x063D0091 and 0x053D0091 have same payload
0x063D0094 and 0x053D0094 have same payload
0x063D0095 and 0x053D0095 have same payload
0x063D0096 and 0x053D0096 have same payload
0x063D0099 and 0x053D0099 have same payload
0x063D009A and 0x053D009A have same payload
0x063D009B and 0x053D009B have same payload
0x063D009C and 0x053D009C have same payload
0x063D009D and 0x053D009D have same payload
0x063D009E and 0x053D009E have same payload
0x063D009F and 0x053D009F have same payload
0x063D00C9 and 0x053D00C9 have same payload
0x063D00CA and 0x053D00CA have same payload
0x063D0213 and 0x053D0213 have same payload
0x063D021D and 0x0500021D have same payload
0x063D021F and 0x0500021F have same payload
0x063D03F1 and 0x053D03F1 have same payload
0x063D03F3 and 0x053D03F3 have same payload
0x063D03F5 and 0x053D03F5 have same payload
0x063D03F6 and 0x053D03F6 have same payload
0x063D03F7 and 0x053D03F7 have same payload
0x063D03F9 and 0x053D03F9 have same payload
0x063D03FA and 0x053D03FA have same payload
0x063D0416 and 0x053D0416 have same payload
0x063D0437 and 0x053D0437 have same payload
0x063D0455 and 0x053D0455 have same payload
0x063D045D and 0x053D045D have same payload
0x063D045F and 0x053D045F have same payload
0x063D0461 and 0x053D0461 have same payload
0x063D0462 and 0x053D0462 have same payload
0x063D0465 and 0x053D0465 have same payload
0x063D0466 and 0x053D0466 have same payload
0x063D0468 and 0x053D0468 have same payload
0x063D046D and 0x053D046D have same payload
0x063D046F and 0x053D046F have same payload
0x063D0470 and 0x053D0470 have same payload
0x063D0471 and 0x053D0471 have same payload
0x063D0473 and 0x053D0473 have same payload
0x063D047F and 0x053D047F have same payload
0x063D0483 and 0x053D0483 have same payload
0x063D0484 and 0x053D0484 have same payload
0x063D0487 and 0x053D0487 have same payload
0x063D0489 and 0x053D0489 have same payload
0x063D0497 and 0x053D0497 have same payload
0x063D04B2 and 0x053D04B2 have same payload
0x063D04B3 and 0x053D04B3 have same payload
0x063D04B8 and 0x053D04B8 have same payload
0x063D04C3 and 0x053D04C3 have same payload
0x063D051D and 0x053D051D have same payload
0x063D051F and 0x053D051F have same payload
0x063D0521 and 0x053D0521 have same payload
0x063D0528 and 0x053D0528 have same payload
0x063D0534 and 0x053D0534 have same payload
0x063D0549 and 0x053D0549 have same payload
0x063D0569 and 0x053D0569 have same payload
0x063D056E and 0x053D056E have same payload
0x063D056F and 0x053D056F have same payload
0x063D0575 and 0x053D0575 have same payload
0x063D0576 and 0x053D0576 have same payload
0x063D0577 and 0x053D0577 have same payload
0x063D0578 and 0x053D0578 have same payload
0x063D0579 and 0x053D0579 have same payload
0x063D057A and 0x053D057A have same payload
0x063D058D and 0x053D058D have same payload
0x063D05B3 and 0x053D05B3 have same payload
0x063D05D4 and 0x053D05D4 have same payload
0x063D05D5 and 0x053D05D5 have same payload
0x063D05D6 and 0x053D05D6 have same payload
0x063D05D8 and 0x053D05D8 have same payload
0x063D05D9 and 0x053D05D9 have same payload
0x063D05DA and 0x053D05DA have same payload
0x063D05DC and 0x053D05DC have same payload
0x063D05DD and 0x053D05DD have same payload
0x063D05DF and 0x053D05DF have same payload
0x063D05E0 and 0x053D05E0 have same payload
0x063D05E1 and 0x053D05E1 have same payload
0x063D05E2 and 0x053D05E2 have same payload
0x063D05F0 and 0x053D05F0 have same payload
0x063D05F1 and 0x053D05F1 have same payload
0x063D05F2 and 0x053D05F2 have same payload
0x063D05FE and 0x053D05FE have same payload
0x063D0600 and 0x053D0600 have same payload
0x063D061F and 0x053D061F have same payload
0x063D063E and 0x053D063E have same payload
0x063D0655 and 0x053D0655 have same payload
0x063D06A9 and 0x053D06A9 have same payload
0x063D06AA and 0x053D06AA have same payload
0x063D06AB and 0x053D06AB have same payload
0x063D06B0 and 0x053D06B0 have same payload
0x063D06D3 and 0x053D06D3 have same payload
0x063D06D4 and 0x053D06D4 have same payload
0x063D06D5 and 0x053D06D5 have same payload
0x063D06D6 and 0x053D06D6 have same payload
0x063D06D7 and 0x053D06D7 have same payload
0x063D06D8 and 0x053D06D8 have same payload
0x063D06D9 and 0x053D06D9 have same payload
0x063D06DA and 0x053D06DA have same payload
0x063D06DB and 0x053D06DB have same payload
0x063D06DC and 0x053D06DC have same payload
0x063D06DD and 0x053D06DD have same payload
0x063D06DE and 0x053D06DE have same payload
0x063D06DF and 0x053D06DF have same payload
0x063D06E0 and 0x053D06E0 have same payload
0x063D06E1 and 0x053D06E1 have same payload
0x063D06E2 and 0x053D06E2 have same payload
0x063D06E3 and 0x053D06E3 have same payload
0x063D06E4 and 0x053D06E4 have same payload
0x063D06E5 and 0x053D06E5 have same payload
0x063D06E6 and 0x053D06E6 have same payload
0x063D06E7 and 0x053D06E7 have same payload
0x063D06E8 and 0x053D06E8 have same payload
0x063D0727 and 0x053D0727 have same payload
0x063D077F and 0x053D077F have same payload
0x063D0783 and 0x053D0783 have same payload
0x063D0784 and 0x053D0784 have same payload
0x063D0785 and 0x053D0785 have same payload
0x063D0786 and 0x053D0786 have same payload
0x063D0787 and 0x053D0787 have same payload
0x063D0788 and 0x053D0788 have same payload
0x063D0789 and 0x053D0789 have same payload
0x063D078D and 0x053D078D have same payload
0x063D078E and 0x053D078E have same payload
0x063D078F and 0x053D078F have same payload
0x063D0793 and 0x053D0793 have same payload
0x063D079A and 0x053D079A have same payload
0x063D079B and 0x053D079B have same payload
0x063D079C and 0x053D079C have same payload
0x063D079D and 0x053D079D have same payload
0x063D07A1 and 0x053D07A1 have same payload
0x063D07A2 and 0x053D07A2 have same payload
0x063D07A3 and 0x053D07A3 have same payload
0x063D07A4 and 0x053D07A4 have same payload
0x063D07A5 and 0x053D07A5 have same payload
0x063D07A6 and 0x053D07A6 have same payload
0x063D07A7 and 0x053D07A7 have same payload
0x063D07A8 and 0x053D07A8 have same payload
0x063D07A9 and 0x053D07A9 have same payload
0x063D07AA and 0x053D07AA have same payload
0x063D07AD and 0x053D07AD have same payload
0x063D07AE and 0x053D07AE have same payload
0x063D07BC and 0x053D07BC have same payload
0x063D07BD and 0x053D07BD have same payload
0x063D07BF and 0x053D07BF have same payload
0x063D07C0 and 0x053D07C0 have same payload
0x063D07EA and 0x053D07EA have same payload
0x063D0839 and 0x053D0839 have same payload
0x063D083E and 0x053D083E have same payload
0x063D0851 and 0x053D0851 have same payload
0x063D0857 and 0x053D0857 have same payload
0x063D0858 and 0x053D0858 have same payload
0x063D08A5 and 0x053D08A5 have same payload
0x063D08A6 and 0x053D08A6 have same payload
0x063D08F2 and 0x053D08F2 have same payload
0x063D08F3 and 0x053D08F3 have same payload
0x063D08FC and 0x053D08FC have same payload
0x063D08FD and 0x053D08FD have same payload
0x063D08FE and 0x053D08FE have same payload
0x063D0904 and 0x053D0904 have same payload
0x063D0905 and 0x053D0905 have same payload
0x063D0906 and 0x053D0906 have same payload
0x063D0908 and 0x053D0908 have same payload
0x063D090A and 0x053D090A have same payload
0x063D090B and 0x053D090B have same payload
0x063D090C and 0x053D090C have same payload
0x063D0951 and 0x053D0951 have same payload
0x063D0956 and 0x053D0956 have same payload
0x063D0959 and 0x053D0959 have same payload
0x063D095A and 0x053D095A have same payload
0x063D0960 and 0x053D0960 have same payload
0x063D0992 and 0x053D0992 have same payload
0x063D09A0 and 0x053D09A0 have same payload
0x063D09A1 and 0x053D09A1 have same payload
0x063D09A2 and 0x053D09A2 have same payload
0x063D09A3 and 0x053D09A3 have same payload
0x063D09A4 and 0x053D09A4 have same payload
0x063D09A5 and 0x053D09A5 have same payload
0x063D09A8 and 0x053D09A8 have same payload
0x063D09A9 and 0x053D09A9 have same payload
0x063D09AA and 0x053D09AA have same payload
0x063D09AB and 0x053D09AB have same payload
0x063D09AC and 0x053D09AC have same payload
0x063D09AD and 0x053D09AD have same payload
0x063D09AE and 0x053D09AE have same payload
0x063D09AF and 0x053D09AF have same payload
0x063D09B0 and 0x053D09B0 have same payload
0x063D09B1 and 0x053D09B1 have same payload
0x063D09B2 and 0x053D09B2 have same payload
0x063D09B3 and 0x053D09B3 have same payload
0x063D09B4 and 0x053D09B4 have same payload
0x063D09BA and 0x053D09BA have same payload
0x063D09BF and 0x053D09BF have same payload
0x063D09C0 and 0x053D09C0 have same payload
0x063D09C1 and 0x053D09C1 have same payload
0x063D09C2 and 0x053D09C2 have same payload
0x063D09C3 and 0x053D09C3 have same payload
0x063D09F6 and 0x053D09F6 have same payload
0x063D09F7 and 0x053D09F7 have same payload
0x063D09F8 and 0x053D09F8 have same payload
0x063D09F9 and 0x053D09F9 have same payload
0x063D09FA and 0x053D09FA have same payload
0x063D09FB and 0x053D09FB have same payload
0x063D0AA0 and 0x053D0AA0 have same payload
0x063D0AA1 and 0x053D0AA1 have same payload
0x063D0AA2 and 0x053D0AA2 have same payload
0x063D0AA3 and 0x053D0AA3 have same payload
0x063D0AA4 and 0x053D0AA4 have same payload
0x063D0AA5 and 0x053D0AA5 have same payload
0x063D0AA6 and 0x053D0AA6 have same payload
0x063D0AD3 and 0x053D0AD3 have same payload
0x063D0AD4 and 0x053D0AD4 have same payload
0x063D0BBF and 0x053D0BBF have same payload
0x063D0BC4 and 0x053D0BC4 have same payload
0x063D0BD0 and 0x053D0BD0 have same payload
0x063D0BD2 and 0x053D0BD2 have same payload
0x063D0BD3 and 0x053D0BD3 have same payload
0x063D2FF1 and 0x053D2FF1 have same payload
0x063D2FF2 and 0x053D2FF2 have same payload
0x063D2FF3 and 0x053D2FF3 have same payload
0x063D2FF5 and 0x053D2FF5 have same payload
0x063D2FF6 and 0x053D2FF6 have same payload
0x063D2FF7 and 0x053D2FF7 have same payload
0x063D2FF9 and 0x053D2FF9 have same payload
0x063D2FFA and 0x053D2FFA have same payload
0x063D2FFB and 0x053D2FFB have same payload
0x063D2FFD and 0x053D2FFD have same payload
0x063D2FFE and 0x053D2FFE have same payload
0x063D2FFF and 0x053D2FFF have same payload
0x063D3001 and 0x053D3001 have same payload
0x063D3002 and 0x053D3002 have same payload
0x063D3003 and 0x053D3003 have same payload
0x063D3046 and 0x053D3046 have same payload
0x063D3050 and 0x053D3050 have same payload
0x063D3052 and 0x053D3052 have same payload
0x063D3053 and 0x053D3053 have same payload
0x063D306A and 0x053D306A have same payload
0x063D306B and 0x053D306B have same payload
0x063D306C and 0x053D306C have same payload
0x063D306D and 0x053D306D have same payload
0x063D3070 and 0x053D3070 have same payload
0x063D3071 and 0x053D3071 have same payload
0x063D3076 and 0x053D3076 have same payload
0x063D3078 and 0x053D3078 have same payload
*/

// 0x073D.... (größtenteils Regelung HK3)
/*
0x073D0000 and 0x053D0000 have same payload
0x073D0001 and 0x053D0001 have same payload
0x073D0002 and 0x053D0002 have same payload
0x073D0003 and 0x053D0003 have same payload
0x073D0004 and 0x053D0004 have same payload
0x073D0006 and 0x053D0006 have same payload
0x073D0007 and 0x053D0007 have same payload
0x073D000B and 0x053D000B have same payload
0x073D000C and 0x0500000C have same payload
0x073D000E and 0x053D000E have same payload
0x073D0010 and 0x053D0010 have same payload
0x073D0011 and 0x053D0011 have same payload
0x073D0064 and 0x053D0064 have same payload
0x073D0066 and 0x053D0066 have same payload
0x073D0068 and 0x053D0068 have same payload
0x073D0069 and 0x053D0069 have same payload
0x073D006A and 0x053D006A have same payload
0x073D006B and 0x053D006B have same payload
0x073D006C and 0x053D006C have same payload
0x073D006D and 0x053D006D have same payload
0x073D0071 and 0x053D0071 have same payload
0x073D0072 and 0x053D0072 have same payload
0x073D0073 and 0x053D0073 have same payload
0x073D0075 and 0x053D0075 have same payload
0x073D0090 and 0x053D0090 have same payload
0x073D0091 and 0x053D0091 have same payload
0x073D0094 and 0x053D0094 have same payload
0x073D0095 and 0x053D0095 have same payload
0x073D0096 and 0x053D0096 have same payload
0x073D0099 and 0x053D0099 have same payload
0x073D009A and 0x053D009A have same payload
0x073D009B and 0x053D009B have same payload
0x073D009C and 0x053D009C have same payload
0x073D009D and 0x053D009D have same payload
0x073D009E and 0x053D009E have same payload
0x073D009F and 0x053D009F have same payload
0x073D00C9 and 0x053D00C9 have same payload
0x073D00CA and 0x053D00CA have same payload
0x073D0213 and 0x053D0213 have same payload
0x073D021D and 0x0500021D have same payload
0x073D021F and 0x0500021F have same payload
0x073D03F1 and 0x053D03F1 have same payload
0x073D03F3 and 0x053D03F3 have same payload
0x073D03F5 and 0x053D03F5 have same payload
0x073D03F6 and 0x053D03F6 have same payload
0x073D03F7 and 0x053D03F7 have same payload
0x073D03F9 and 0x053D03F9 have same payload
0x073D03FA and 0x053D03FA have same payload
0x073D0416 and 0x053D0416 have same payload
0x073D0437 and 0x053D0437 have same payload
0x073D0455 and 0x053D0455 have same payload
0x073D045D and 0x053D045D have same payload
0x073D045F and 0x053D045F have same payload
0x073D0461 and 0x053D0461 have same payload
0x073D0462 and 0x053D0462 have same payload
0x073D0465 and 0x053D0465 have same payload
0x073D0466 and 0x053D0466 have same payload
0x073D0468 and 0x053D0468 have same payload
0x073D046D and 0x053D046D have same payload
0x073D046F and 0x053D046F have same payload
0x073D0470 and 0x053D0470 have same payload
0x073D0471 and 0x053D0471 have same payload
0x073D0473 and 0x053D0473 have same payload
0x073D047F and 0x053D047F have same payload
0x073D0483 and 0x053D0483 have same payload
0x073D0484 and 0x053D0484 have same payload
0x073D0487 and 0x053D0487 have same payload
0x073D0489 and 0x053D0489 have same payload
0x073D0497 and 0x053D0497 have same payload
0x073D04A2 and 0x053D04A2 have same payload
0x073D04B2 and 0x053D04B2 have same payload
0x073D04B3 and 0x053D04B3 have same payload
0x073D04B8 and 0x053D04B8 have same payload
0x073D04C3 and 0x053D04C3 have same payload
0x073D051D and 0x053D051D have same payload
0x073D051F and 0x053D051F have same payload
0x073D0521 and 0x053D0521 have same payload
0x073D0528 and 0x053D0528 have same payload
0x073D0534 and 0x053D0534 have same payload
0x073D0549 and 0x053D0549 have same payload
0x073D0569 and 0x053D0569 have same payload
0x073D056E and 0x053D056E have same payload
0x073D056F and 0x053D056F have same payload
0x073D0575 and 0x053D0575 have same payload
0x073D0576 and 0x053D0576 have same payload
0x073D0577 and 0x053D0577 have same payload
0x073D0578 and 0x053D0578 have same payload
0x073D0579 and 0x053D0579 have same payload
0x073D057A and 0x053D057A have same payload
0x073D058D and 0x053D058D have same payload
0x073D05B3 and 0x053D05B3 have same payload
0x073D05D4 and 0x053D05D4 have same payload
0x073D05D5 and 0x053D05D5 have same payload
0x073D05D6 and 0x053D05D6 have same payload
0x073D05D8 and 0x053D05D8 have same payload
0x073D05D9 and 0x053D05D9 have same payload
0x073D05DA and 0x053D05DA have same payload
0x073D05DD and 0x053D05DD have same payload
0x073D05DF and 0x053D05DF have same payload
0x073D05E0 and 0x053D05E0 have same payload
0x073D05E1 and 0x053D05E1 have same payload
0x073D05E2 and 0x053D05E2 have same payload
0x073D05F0 and 0x053D05F0 have same payload
0x073D05F1 and 0x053D05F1 have same payload
0x073D05F2 and 0x053D05F2 have same payload
0x073D05FE and 0x053D05FE have same payload
0x073D0600 and 0x053D0600 have same payload
0x073D061F and 0x053D061F have same payload
0x073D063E and 0x053D063E have same payload
0x073D0655 and 0x053D0655 have same payload
0x073D06A9 and 0x053D06A9 have same payload
0x073D06AA and 0x053D06AA have same payload
0x073D06AB and 0x053D06AB have same payload
0x073D06B0 and 0x053D06B0 have same payload
0x073D06D3 and 0x053D06D3 have same payload
0x073D06D4 and 0x053D06D4 have same payload
0x073D06D5 and 0x053D06D5 have same payload
0x073D06D6 and 0x053D06D6 have same payload
0x073D06D7 and 0x053D06D7 have same payload
0x073D06D8 and 0x053D06D8 have same payload
0x073D06D9 and 0x053D06D9 have same payload
0x073D06DA and 0x053D06DA have same payload
0x073D06DB and 0x053D06DB have same payload
0x073D06DC and 0x053D06DC have same payload
0x073D06DD and 0x053D06DD have same payload
0x073D06DE and 0x053D06DE have same payload
0x073D06DF and 0x053D06DF have same payload
0x073D06E0 and 0x053D06E0 have same payload
0x073D06E1 and 0x053D06E1 have same payload
0x073D06E2 and 0x053D06E2 have same payload
0x073D06E3 and 0x053D06E3 have same payload
0x073D06E4 and 0x053D06E4 have same payload
0x073D06E5 and 0x053D06E5 have same payload
0x073D06E6 and 0x053D06E6 have same payload
0x073D06E7 and 0x053D06E7 have same payload
0x073D06E8 and 0x053D06E8 have same payload
0x073D0727 and 0x053D0727 have same payload
0x073D077B and 0x053D077B have same payload
0x073D077F and 0x053D077F have same payload
0x073D0783 and 0x053D0783 have same payload
0x073D0784 and 0x053D0784 have same payload
0x073D0785 and 0x053D0785 have same payload
0x073D0786 and 0x053D0786 have same payload
0x073D0787 and 0x053D0787 have same payload
0x073D0788 and 0x053D0788 have same payload
0x073D0789 and 0x053D0789 have same payload
0x073D078D and 0x053D078D have same payload
0x073D078E and 0x053D078E have same payload
0x073D078F and 0x053D078F have same payload
0x073D0793 and 0x053D0793 have same payload
0x073D0799 and 0x053D0799 have same payload
0x073D079A and 0x053D079A have same payload
0x073D079B and 0x053D079B have same payload
0x073D079C and 0x053D079C have same payload
0x073D079D and 0x053D079D have same payload
0x073D07A1 and 0x053D07A1 have same payload
0x073D07A2 and 0x053D07A2 have same payload
0x073D07A3 and 0x053D07A3 have same payload
0x073D07A4 and 0x053D07A4 have same payload
0x073D07A5 and 0x053D07A5 have same payload
0x073D07A6 and 0x053D07A6 have same payload
0x073D07A7 and 0x053D07A7 have same payload
0x073D07A8 and 0x053D07A8 have same payload
0x073D07A9 and 0x053D07A9 have same payload
0x073D07AA and 0x053D07AA have same payload
0x073D07AD and 0x053D07AD have same payload
0x073D07AE and 0x053D07AE have same payload
0x073D07BC and 0x053D07BC have same payload
0x073D07BD and 0x053D07BD have same payload
0x073D07BF and 0x053D07BF have same payload
0x073D07C0 and 0x053D07C0 have same payload
0x073D07EA and 0x053D07EA have same payload
0x073D0839 and 0x053D0839 have same payload
0x073D083E and 0x053D083E have same payload
0x073D0851 and 0x053D0851 have same payload
0x073D0857 and 0x053D0857 have same payload
0x073D0858 and 0x053D0858 have same payload
0x073D08A5 and 0x053D08A5 have same payload
0x073D08A6 and 0x053D08A6 have same payload
0x073D08F2 and 0x053D08F2 have same payload
0x073D08F3 and 0x053D08F3 have same payload
0x073D08FC and 0x053D08FC have same payload
0x073D08FD and 0x053D08FD have same payload
0x073D08FE and 0x053D08FE have same payload
0x073D0904 and 0x053D0904 have same payload
0x073D0905 and 0x053D0905 have same payload
0x073D0906 and 0x053D0906 have same payload
0x073D0908 and 0x053D0908 have same payload
0x073D090A and 0x053D090A have same payload
0x073D090B and 0x053D090B have same payload
0x073D090C and 0x053D090C have same payload
0x073D0951 and 0x053D0951 have same payload
0x073D0956 and 0x053D0956 have same payload
0x073D0959 and 0x053D0959 have same payload
0x073D095A and 0x053D095A have same payload
0x073D0960 and 0x053D0960 have same payload
0x073D0992 and 0x053D0992 have same payload
0x073D09A0 and 0x053D09A0 have same payload
0x073D09A1 and 0x053D09A1 have same payload
0x073D09A2 and 0x053D09A2 have same payload
0x073D09A3 and 0x053D09A3 have same payload
0x073D09A4 and 0x053D09A4 have same payload
0x073D09A5 and 0x053D09A5 have same payload
0x073D09A8 and 0x053D09A8 have same payload
0x073D09A9 and 0x053D09A9 have same payload
0x073D09AA and 0x053D09AA have same payload
0x073D09AB and 0x053D09AB have same payload
0x073D09AC and 0x053D09AC have same payload
0x073D09AD and 0x053D09AD have same payload
0x073D09AE and 0x053D09AE have same payload
0x073D09AF and 0x053D09AF have same payload
0x073D09B0 and 0x053D09B0 have same payload
0x073D09B1 and 0x053D09B1 have same payload
0x073D09B2 and 0x053D09B2 have same payload
0x073D09B3 and 0x053D09B3 have same payload
0x073D09B4 and 0x053D09B4 have same payload
0x073D09BA and 0x053D09BA have same payload
0x073D09BF and 0x053D09BF have same payload
0x073D09C0 and 0x053D09C0 have same payload
0x073D09C1 and 0x053D09C1 have same payload
0x073D09C2 and 0x053D09C2 have same payload
0x073D09C3 and 0x053D09C3 have same payload
0x073D0AA0 and 0x053D0AA0 have same payload
0x073D0AA1 and 0x053D0AA1 have same payload
0x073D0AA2 and 0x053D0AA2 have same payload
0x073D0AA3 and 0x053D0AA3 have same payload
0x073D0AA4 and 0x053D0AA4 have same payload
0x073D0AA5 and 0x053D0AA5 have same payload
0x073D0AA6 and 0x053D0AA6 have same payload
0x073D0AD3 and 0x053D0AD3 have same payload
0x073D0AD4 and 0x053D0AD4 have same payload
0x073D0BBF and 0x053D0BBF have same payload
0x073D0BC4 and 0x053D0BC4 have same payload
0x073D0BD0 and 0x053D0BD0 have same payload
0x073D0BD2 and 0x053D0BD2 have same payload
0x073D0BD3 and 0x053D0BD3 have same payload
0x073D2FF1 and 0x053D2FF1 have same payload
0x073D2FF2 and 0x053D2FF2 have same payload
0x073D2FF3 and 0x053D2FF3 have same payload
0x073D2FF5 and 0x053D2FF5 have same payload
0x073D2FF6 and 0x053D2FF6 have same payload
0x073D2FF7 and 0x053D2FF7 have same payload
0x073D2FF9 and 0x053D2FF9 have same payload
0x073D2FFA and 0x053D2FFA have same payload
0x073D2FFB and 0x053D2FFB have same payload
0x073D2FFD and 0x053D2FFD have same payload
0x073D2FFE and 0x053D2FFE have same payload
0x073D2FFF and 0x053D2FFF have same payload
0x073D3001 and 0x053D3001 have same payload
0x073D3002 and 0x053D3002 have same payload
0x073D3003 and 0x053D3003 have same payload
0x073D3046 and 0x053D3046 have same payload
0x073D3050 and 0x053D3050 have same payload
0x073D3052 and 0x053D3052 have same payload
0x073D3053 and 0x053D3053 have same payload
0x073D306A and 0x053D306A have same payload
0x073D306B and 0x053D306B have same payload
0x073D306C and 0x053D306C have same payload
0x073D306D and 0x053D306D have same payload
0x073D306F and 0x053D306F have same payload
0x073D3070 and 0x053D3070 have same payload
0x073D3071 and 0x053D3071 have same payload
0x073D3076 and 0x053D3076 have same payload
0x073D3078 and 0x053D3078 have same payload
*/

// 0x093D....

{0x093D2FB6,  CAT_USER_DEFINED,     VT_UNKNOWN,       10293, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 63
{0x093D3016,  CAT_USER_DEFINED,     VT_UNKNOWN,       10294, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 28
{0x093D301D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10295, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D3020,  CAT_USER_DEFINED,     VT_UNKNOWN,       10296, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D3023,  CAT_USER_DEFINED,     VT_UNKNOWN,       10297, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D3024,  CAT_USER_DEFINED,     VT_UNKNOWN,       10298, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D3025,  CAT_USER_DEFINED,     VT_UNKNOWN,       10299, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D3026,  CAT_USER_DEFINED,     VT_UNKNOWN,       10300, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D3027,  CAT_USER_DEFINED,     VT_UNKNOWN,       10301, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D3028,  CAT_USER_DEFINED,     VT_UNKNOWN,       10302, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D3029,  CAT_USER_DEFINED,     VT_UNKNOWN,       10303, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D302A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10304, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D302B,  CAT_USER_DEFINED,     VT_UNKNOWN,       10305, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D302C,  CAT_USER_DEFINED,     VT_UNKNOWN,       10306, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D302D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10307, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D302E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10308, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D302F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10309, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D3030,  CAT_USER_DEFINED,     VT_UNKNOWN,       10310, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D3031,  CAT_USER_DEFINED,     VT_UNKNOWN,       10311, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D3032,  CAT_USER_DEFINED,     VT_UNKNOWN,       10312, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x093D303D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10313, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x093D303E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10314, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x093D303F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10315, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x093D3040,  CAT_USER_DEFINED,     VT_UNKNOWN,       10316, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x093D3041,  CAT_USER_DEFINED,     VT_UNKNOWN,       10317, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 01
{0x093D3047,  CAT_USER_DEFINED,     VT_UNKNOWN,       10318, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 5E
{0x093D3055,  CAT_USER_DEFINED,     VT_UNKNOWN,       10319, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 03 E8    // dec. 1000
{0x093D3056,  CAT_USER_DEFINED,     VT_UNKNOWN,       10320, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x093D3057,  CAT_USER_DEFINED,     VT_UNKNOWN,       10321, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 09 C4    // dec. 2500
{0x093D3058,  CAT_USER_DEFINED,     VT_UNKNOWN,       10322, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 05 DC    // dec. 1500

// 0x0D3D....

{0x0D3D01F6,  CAT_USER_DEFINED,     VT_UNKNOWN,       10323, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 00 00 00
{0x0D3D01F7,  CAT_USER_DEFINED,     VT_UNKNOWN,       10324, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x0D3D01FA,  CAT_USER_DEFINED,     VT_UNKNOWN,       10325, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 32 00
{0x0D3D0930,  CAT_USER_DEFINED,     VT_UNKNOWN,       10326, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 FF
{0x0D3D0936,  CAT_USER_DEFINED,     VT_UNKNOWN,       10327, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x0D3D0944,  CAT_USER_DEFINED,     VT_UNKNOWN,       10328, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 02 00
{0x0D3D0945,  CAT_USER_DEFINED,     VT_UNKNOWN,       10329, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 07 80
{0x0D3D2F9C,  CAT_USER_DEFINED,     VT_UNKNOWN,       10330, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 0A
{0x0D3D2FB8,  CAT_USER_DEFINED,     VT_UNKNOWN,       10331, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 0A
{0x0D3D2FB9,  CAT_USER_DEFINED,     VT_UNKNOWN,       10332, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 05
{0x0D3D2FBB,  CAT_USER_DEFINED,     VT_UNKNOWN,       10333, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 55
{0x0D3D300A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10334, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 11
{0x0D3D304E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10335, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 FF
{0x0D3D3060,  CAT_USER_DEFINED,     VT_UNKNOWN,       10336, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x0D3D3067,  CAT_USER_DEFINED,     VT_UNKNOWN,       10337, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00

// 0x113D....

{0x113D01F7,  CAT_USER_DEFINED,     VT_UNKNOWN,       10338, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x113D01FA,  CAT_USER_DEFINED,     VT_UNKNOWN,       10339, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 32 00
{0x113D0209,  CAT_USER_DEFINED,     VT_UNKNOWN,       10340, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 02 81 00 01 F4 02 F1 E1 C0
{0x113D042A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10341, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x113D0642,  CAT_USER_DEFINED,     VT_UNKNOWN,       10343, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x113D0775,  CAT_USER_DEFINED,     VT_UNKNOWN,       10344, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x113D07C8,  CAT_USER_DEFINED,     VT_UNKNOWN,       10345, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x113D0938,  CAT_USER_DEFINED,     VT_UNKNOWN,       10346, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 FF
{0x113D09FC,  CAT_USER_DEFINED,     VT_UNKNOWN,       10347, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 32
{0x113D0CC3,  CAT_USER_DEFINED,     VT_UNKNOWN,       10348, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x113D2FE2,  CAT_USER_DEFINED,     VT_UNKNOWN,       10349, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 54
{0x113D304B,  CAT_USER_DEFINED,     VT_UNKNOWN,       10350, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 05
{0x113D3059,  CAT_USER_DEFINED,     VT_UNKNOWN,       10351, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x113D305A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10352, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 4B
{0x113D305B,  CAT_USER_DEFINED,     VT_UNKNOWN,       10353, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x113D305C,  CAT_USER_DEFINED,     VT_UNKNOWN,       10354, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 4B
{0x113D305E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10355, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 1A
{0x113D3061,  CAT_USER_DEFINED,     VT_UNKNOWN,       10356, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 58
{0x113D3062,  CAT_USER_DEFINED,     VT_UNKNOWN,       10357, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 B8
{0x113D3068,  CAT_USER_DEFINED,     VT_UNKNOWN,       10358, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x113D3069,  CAT_USER_DEFINED,     VT_UNKNOWN,       10359, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 FA
{0x113D3079,  CAT_USER_DEFINED,     VT_UNKNOWN,       10360, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 1E
{0x113D307A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10361, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 1E
{0x113D307B,  CAT_USER_DEFINED,     VT_UNKNOWN,       10362, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 03

// 0x153D....

{0x153D01F5,  CAT_USER_DEFINED,     VT_UNKNOWN,       10363, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 00 00
{0x153D01F8,  CAT_USER_DEFINED,     VT_UNKNOWN,       10364, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x153D01FB,  CAT_USER_DEFINED,     VT_UNKNOWN,       10365, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 32 00
{0x153D01FC,  CAT_USER_DEFINED,     VT_UNKNOWN,       10366, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 00 00 01 64 00 00
{0x153D022D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10368, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 0D EF

// 0x193D....

{0x193D01F4,  CAT_USER_DEFINED,     VT_UNKNOWN,       10369, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 00 00
{0x193D01F9,  CAT_USER_DEFINED,     VT_UNKNOWN,       10370, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x193D01FD,  CAT_USER_DEFINED,     VT_UNKNOWN,       10371, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 01
{0x193D01FE,  CAT_USER_DEFINED,     VT_UNKNOWN,       10372, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 00
{0x193D022C,  CAT_USER_DEFINED,     VT_UNKNOWN,       10373, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 00
{0x193D022E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10374, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 00 00
{0x193D07D4,  CAT_USER_DEFINED,     VT_UNKNOWN,       10375, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x193D2FEE,  CAT_USER_DEFINED,     VT_UNKNOWN,       10376, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00

// 0x213D....

{0x213D01F4,  CAT_USER_DEFINED,     VT_UNKNOWN,       10378, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 08 02
{0x213D063A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10380, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / on RVS43.222:  00 01
{0x213D064F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10381, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x213D0666,  CAT_USER_DEFINED,     VT_UNKNOWN,       10382, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 F0 / on RVS43.222:  00 78
{0x213D066A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10383, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x213D066B,  CAT_USER_DEFINED,     VT_UNKNOWN,       10384, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x213D066C,  CAT_USER_DEFINED,     VT_UNKNOWN,       10385, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x213D0683,  CAT_USER_DEFINED,     VT_UNKNOWN,       10386, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x213D0684,  CAT_USER_DEFINED,     VT_UNKNOWN,       10387, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 15 40 / on RVS43.222:  00 17 C0  // Temperaturwächter Sollwert HK1
{0x213D2FAE,  CAT_USER_DEFINED,     VT_UNKNOWN,       10388, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 05
{0x213D3044,  CAT_USER_DEFINED,     VT_UNKNOWN,       10389, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 06
{0x213D3075,  CAT_USER_DEFINED,     VT_UNKNOWN,       10390, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00

// 0x223D....

{0x223D01F4,  CAT_USER_DEFINED,     VT_UNKNOWN,       10391, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 00 00
{0x223D063A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10393, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 01 / same on RVS43.222
{0x223D064F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10394, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x223D0658,  CAT_USER_DEFINED,     VT_UNKNOWN,       10395, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 06 00 / on RVS43.222:  00 08 00
{0x223D0659,  CAT_USER_DEFINED,     VT_UNKNOWN,       10396, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 5A / on RVS43.222:  00 00 78
{0x223D065C,  CAT_USER_DEFINED,     VT_UNKNOWN,       10397, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 80
{0x223D065E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10398, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 64
{0x223D0666,  CAT_USER_DEFINED,     VT_UNKNOWN,       10399, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 F0 / on RVS43.222:  00 78
{0x223D066A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10400, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x223D066B,  CAT_USER_DEFINED,     VT_UNKNOWN,       10401, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x223D066C,  CAT_USER_DEFINED,     VT_UNKNOWN,       10402, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x223D0683,  CAT_USER_DEFINED,     VT_UNKNOWN,       10403, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x223D0684,  CAT_USER_DEFINED,     VT_UNKNOWN,       10404, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 15 40 / on RVS43.222:  00 17 C0  // Temperaturwächter Sollwert HK2
{0x223D2FAE,  CAT_USER_DEFINED,     VT_UNKNOWN,       10408, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 05
{0x223D3038,  CAT_USER_DEFINED,     VT_UNKNOWN,       10410, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 32
{0x223D3044,  CAT_USER_DEFINED,     VT_UNKNOWN,       10411, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 06
{0x223D3075,  CAT_USER_DEFINED,     VT_UNKNOWN,       10412, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00

// 0x233D....

{0x233D01F4,  CAT_USER_DEFINED,     VT_UNKNOWN,       10413, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 00 00
{0x233D063A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10415, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / on RVS43.222:  00 01
{0x233D064F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10416, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x233D0658,  CAT_USER_DEFINED,     VT_UNKNOWN,       10417, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 06 00 / on RVS43.222:  00 08 00
{0x233D0659,  CAT_USER_DEFINED,     VT_UNKNOWN,       10418, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 5A / on RVS43.222:  00 00 78
{0x233D065C,  CAT_USER_DEFINED,     VT_UNKNOWN,       10419, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 80
{0x233D065E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10420, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 64
{0x233D0666,  CAT_USER_DEFINED,     VT_UNKNOWN,       10421, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 FF / on RVS43.222:  00 78
{0x233D066A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10422, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x233D066B,  CAT_USER_DEFINED,     VT_UNKNOWN,       10423, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x233D066C,  CAT_USER_DEFINED,     VT_UNKNOWN,       10424, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x233D0683,  CAT_USER_DEFINED,     VT_UNKNOWN,       10425, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x233D0684,  CAT_USER_DEFINED,     VT_UNKNOWN,       10426, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 15 40 / on RVS43.222:  00 17 C0
{0x233D2F8C,  CAT_USER_DEFINED,     VT_UNKNOWN,       10427, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 06
{0x233D2F8D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10428, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 08
{0x233D2F8E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10429, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 10
{0x233D2F8F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10430, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 0A
{0x233D2F90,  CAT_USER_DEFINED,     VT_UNKNOWN,       10431, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 02
{0x233D2F91,  CAT_USER_DEFINED,     VT_UNKNOWN,       10432, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 02
{0x233D2F92,  CAT_USER_DEFINED,     VT_UNKNOWN,       10433, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 06
{0x233D2F93,  CAT_USER_DEFINED,     VT_UNKNOWN,       10434, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 0C
{0x233D2FAE,  CAT_USER_DEFINED,     VT_UNKNOWN,       10435, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 05
{0x233D2FD5,  CAT_USER_DEFINED,     VT_UNKNOWN,       10436, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x233D300F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10437, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 32
{0x233D3038,  CAT_USER_DEFINED,     VT_UNKNOWN,       10438, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 32
{0x233D3044,  CAT_USER_DEFINED,     VT_UNKNOWN,       10439, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 06
{0x233D3075,  CAT_USER_DEFINED,     VT_UNKNOWN,       10440, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00

// 0x253D....

{0x253D01F4,  CAT_USER_DEFINED,     VT_UNKNOWN,       10441, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on on LMU74.100A136: 0E 40 00 00 / on RVS43.222: 03 C0 08 56
{0x253D068B,  CAT_USER_DEFINED,     VT_UNKNOWN,       10443, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x253D068F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10444, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 14 00
{0x253D0726,  CAT_USER_DEFINED,     VT_UNKNOWN,       10445, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x253D0735,  CAT_USER_DEFINED,     VT_UNKNOWN,       10446, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x253D0736,  CAT_USER_DEFINED,     VT_UNKNOWN,       10447, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x253D2FAF,  CAT_USER_DEFINED,     VT_UNKNOWN,       10448, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 05
{0x253D2FE0,  CAT_USER_DEFINED,     VT_UNKNOWN,       10449, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00

// 0x293D....

{0x293D01F4,  CAT_USER_DEFINED,     VT_UNKNOWN,       10450, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 00 00
{0x293D0421,  CAT_USER_DEFINED,     VT_UNKNOWN,       10451, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x293D0641,  CAT_USER_DEFINED,     VT_UNKNOWN,       10452, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 01
{0x293D07C7,  CAT_USER_DEFINED,     VT_UNKNOWN,       10453, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 FF

// 0x2A3D....

{0x2A3D01F4,  CAT_USER_DEFINED,     VT_UNKNOWN,       10454, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 00 00
{0x2A3D0421,  CAT_USER_DEFINED,     VT_UNKNOWN,       10455, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x2A3D0641,  CAT_USER_DEFINED,     VT_UNKNOWN,       10456, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 01
{0x2A3D07C7,  CAT_USER_DEFINED,     VT_UNKNOWN,       10457, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 FF

// 0x2D3D.... (größtenteils Steuerung HK1)

{0x2D3D0231,  CAT_USER_DEFINED,     VT_UNKNOWN,       10458, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 BF 04 02 01 0D / on RVS43.222: 00 00 63 24 02 01 0D
{0x2D3D04B7,  CAT_USER_DEFINED,     VT_UNKNOWN,       10459, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x2D3D04BB,  CAT_USER_DEFINED,     VT_UNKNOWN,       10460, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 02
{0x2D3D056A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10461, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 05 04
{0x2D3D05F3,  CAT_USER_DEFINED,     VT_UNKNOWN,       10462, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 FF 85 / on RVS43.222: 00 00 00
{0x2D3D05FB,  CAT_USER_DEFINED,     VT_UNKNOWN,       10463, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 05
{0x2D3D060D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10464, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 0F
{0x2D3D060E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10465, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 0F
{0x2D3D0613,  CAT_USER_DEFINED,     VT_UNKNOWN,       10466, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / on RVS43.222: 00 FF
{0x2D3D0615,  CAT_USER_DEFINED,     VT_UNKNOWN,       10467, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x2D3D071A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10468, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 01
{0x2D3D2FAB,  CAT_USER_DEFINED,     VT_UNKNOWN,       10469, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 03
{0x2D3D2FAC,  CAT_USER_DEFINED,     VT_UNKNOWN,       10470, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x2D3D2FAD,  CAT_USER_DEFINED,     VT_UNKNOWN,       10471, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 4B
{0x2D3D2FD7,  CAT_USER_DEFINED,     VT_UNKNOWN,       10472, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x2D3D3045,  CAT_USER_DEFINED,     VT_UNKNOWN,       10473, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 34
{0x2D3D3074,  CAT_USER_DEFINED,     VT_UNKNOWN,       10474, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 FF

// 0x2E3D.... (größtenteils Steuerung HK2)

{0x2E3D0211,  CAT_USER_DEFINED,     VT_UNKNOWN,       10475, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 FF FF FF FF FF FF 00 00
{0x2E3D0231,  CAT_USER_DEFINED,     VT_UNKNOWN,       10476, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 02 4E A0 01 00 02 / same on RVS43.222
{0x2E3D04B7,  CAT_USER_DEFINED,     VT_UNKNOWN,       10477, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x2E3D04BB,  CAT_USER_DEFINED,     VT_UNKNOWN,       10478, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x2E3D056A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10479, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 0C 80
{0x2E3D05F3,  CAT_USER_DEFINED,     VT_UNKNOWN,       10480, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00 / same on RVS43.222
{0x2E3D05FB,  CAT_USER_DEFINED,     VT_UNKNOWN,       10481, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 05
{0x2E3D060D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10482, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 0F / same on RVS43.222
{0x2E3D060E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10483, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 0F / same on RVS43.222
{0x2E3D0613,  CAT_USER_DEFINED,     VT_UNKNOWN,       10484, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / on RVS43.222:  00 FF
{0x2E3D0615,  CAT_USER_DEFINED,     VT_UNKNOWN,       10485, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x2E3D071A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10486, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 01
{0x2E3D2FAB,  CAT_USER_DEFINED,     VT_UNKNOWN,       10487, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 03
{0x2E3D2FAC,  CAT_USER_DEFINED,     VT_UNKNOWN,       10488, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x2E3D2FAD,  CAT_USER_DEFINED,     VT_UNKNOWN,       10489, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 4B
{0x2E3D2FD7,  CAT_USER_DEFINED,     VT_UNKNOWN,       10490, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x2E3D3045,  CAT_USER_DEFINED,     VT_UNKNOWN,       10491, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 34
{0x2E3D3074,  CAT_USER_DEFINED,     VT_UNKNOWN,       10492, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 FF
/*
0x2E3D05E7 and 0x2D3D05E7 have same payload
0x2E3D0611 and 0x2D3D0611 have same payload
0x2E3D2F9B and 0x2D3D2F9B have same payload
0x2E3D2FD6 and 0x2D3D2FD6 have same payload
0x2E3D2FD8 and 0x2D3D2FD8 have same payload
0x2E3D2FD9 and 0x2D3D2FD9 have same payload
0x2E3D2FDA and 0x2D3D2FDA have same payload
0x2E3D2FEA and 0x2D3D2FEA have same payload
0x2E3D300C and 0x2D3D300C have same payload
0x2E3D3037 and 0x2D3D3037 have same payload
0x2E3D304C and 0x2D3D304C have same payload
*/

// 0x2F3D.... (größtenteils Steuerung HK3)

{0x2F3D0211,  CAT_USER_DEFINED,     VT_UNKNOWN,       10493, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 FF FF FF FF FF FF 00 00
{0x2F3D0231,  CAT_USER_DEFINED,     VT_UNKNOWN,       10494, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 5E EC 01 00 01 / on RVS43.222:  00 02 4E A0 01 00 02
{0x2F3D04B7,  CAT_USER_DEFINED,     VT_UNKNOWN,       10495, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 04 / on RVS43.222:  00 00
{0x2F3D04BB,  CAT_USER_DEFINED,     VT_UNKNOWN,       10496, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 31 / on RVS43.222:  00 00
{0x2F3D056A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10497, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 0C 80
{0x2F3D05F3,  CAT_USER_DEFINED,     VT_UNKNOWN,       10498, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 01 40 / on RVS43.222:  00 00 00
{0x2F3D05FB,  CAT_USER_DEFINED,     VT_UNKNOWN,       10499, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 05
{0x2F3D0603,  CAT_USER_DEFINED,     VT_UNKNOWN,       10500, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 FF / on RVS43.222:  01 14
{0x2F3D060D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10501, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 0F / same on RVS43.222
{0x2F3D060E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10502, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 03 / on RVS43.222:  00 0F
{0x2F3D0613,  CAT_USER_DEFINED,     VT_UNKNOWN,       10503, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 FF / same on RVS43.222
{0x2F3D0615,  CAT_USER_DEFINED,     VT_UNKNOWN,       10504, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 01 08 C0
{0x2F3D071A,  CAT_USER_DEFINED,     VT_UNKNOWN,       10505, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 01
{0x2F3D2FAB,  CAT_USER_DEFINED,     VT_UNKNOWN,       10506, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 03
{0x2F3D2FAC,  CAT_USER_DEFINED,     VT_UNKNOWN,       10507, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x2F3D2FAD,  CAT_USER_DEFINED,     VT_UNKNOWN,       10508, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 4B
{0x2F3D2FD7,  CAT_USER_DEFINED,     VT_UNKNOWN,       10509, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 00
{0x2F3D3045,  CAT_USER_DEFINED,     VT_UNKNOWN,       10510, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 34
{0x2F3D3073,  CAT_USER_DEFINED,     VT_UNKNOWN,       10511, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00
{0x2F3D3074,  CAT_USER_DEFINED,     VT_UNKNOWN,       10512, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 FF
/*
0x2F3D05E7 and 0x2D3D05E7 have same payload
0x2F3D0611 and 0x2D3D0611 have same payload
0x2F3D2F9B and 0x2D3D2F9B have same payload
0x2F3D2FD4 and 0x2D3D2FD4 have same payload
0x2F3D2FD6 and 0x2D3D2FD6 have same payload
0x2F3D2FD8 and 0x2D3D2FD8 have same payload
0x2F3D2FD9 and 0x2D3D2FD9 have same payload
0x2F3D2FDA and 0x2D3D2FDA have same payload
0x2F3D2FEA and 0x2D3D2FEA have same payload
0x2F3D300C and 0x2D3D300C have same payload
0x2F3D3037 and 0x2D3D3037 have same payload
0x2F3D304C and 0x2D3D304C have same payload
*/

// 0x313D....

{0x313D01F4,  CAT_USER_DEFINED,     VT_UNKNOWN,       10513, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 01 40 08 57
{0x313D0212,  CAT_USER_DEFINED,     VT_UNKNOWN,       10514, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 41
{0x313D0215,  CAT_USER_DEFINED,     VT_UNKNOWN,       10515, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 09 0B
{0x313D0216,  CAT_USER_DEFINED,     VT_UNKNOWN,       10516, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 09 0B
{0x313D0686,  CAT_USER_DEFINED,     VT_UNKNOWN,       10517, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 01
{0x313D0715,  CAT_USER_DEFINED,     VT_UNKNOWN,       10518, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00
{0x313D0757,  CAT_USER_DEFINED,     VT_UNKNOWN,       10519, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on RVS43.222: 00 00 00

// 0x493D....

{0x493D0422,  CAT_USER_DEFINED,     VT_UNKNOWN,       10520, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00 / same on RVS43.222
{0x493D0552,  CAT_USER_DEFINED,     VT_UNKNOWN,       10521, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 01 40 /  on RVS43.222: 00 03 C0
{0x493D0864,  CAT_USER_DEFINED,     VT_UNKNOWN,       10523, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 01 40 / same on RVS43.222
{0x493D306E,  CAT_USER_DEFINED,     VT_UNKNOWN,       10524, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Brute force detected Command ID, data payload on LMU74.100A136: 00 00

// no Command IDs found via brute force for major group 0x51 on LMU74.100A136 and RVS43.222
// no Command IDs found via brute force for major group 0x59 on LMU74.100A136 and RVS43.222
// no Command IDs found via brute force for major group 0x65 on LMU74.100A136 and RVS43.222
// no Command IDs found via brute force for major group 0x69 on LMU74.100A136 and RVS43.222

// CommandIDs logged from OCI700/ACS700 diagnosis tool

{0x2E3D051D,  CAT_USER_DEFINED,     VT_UNKNOWN,       10526, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // logged from ACS700 diagnosis software

{0x653D0B71,  CAT_USER_DEFINED,     VT_UNKNOWN,       10527, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Beginn Vorlaufanhebung bei rel. Raumfeuchte KK1
{0x653D0B70,  CAT_USER_DEFINED,     VT_UNKNOWN,       10528, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL}, // Ende Vorlaufanhebung bei rel. Raumfeuchte KK1
{0x153D2FA0,  CAT_USER_DEFINED,     VT_UNKNOWN,       10529, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL},  // logged from ACS700 diagnosis software, but (seemingly) not working  // Reglerkonfiguration 3
{0x113D2FA7,  CAT_USER_DEFINED,     VT_PERCENT_WORD1, 10530, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL},  // logged from ACS700 diagnosis software, but (seemingly) not working  // Maximale Förderhöhe der modulierenden Pumpe
{0x113D2FA8,  CAT_USER_DEFINED,     VT_PERCENT_WORD1, 10531, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL},  // logged from ACS700 diagnosis software, but (seemingly) not working  // Minimale Förderhöhe der modulierenden Pumpe
{0x2D3D3023,  CAT_USER_DEFINED,     VT_UNKNOWN,       10532, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL},  // logged from ACS700 diagnosis software, but (seemingly) not working
{0x2E3D302F,  CAT_USER_DEFINED,     VT_UNKNOWN,       10533, STR10200, 0,                    NULL,         FL_RONLY, DEV_ALL},  // logged from ACS700 diagnosis software, but (seemingly) not working

//PPS-Bus commands

{0x2D290000,  CAT_PPS,              VT_TEMP,          15000, STR8700,  0,                    NULL,         FL_RONLY, DEV_ALL},     // Außentemperatur
{0x2D570001,  CAT_PPS,              VT_TEMP,          15001, STR8704,  0,                    NULL,         FL_RONLY, DEV_ALL},     // Außentemperatur gemischt
{0x2D2E0002,  CAT_PPS,              VT_TEMP,          15002, STR8743,  0,                    NULL,         FL_RONLY, DEV_ALL},     // Kesselvorlauftemperatur
{0x2D0E0003,  CAT_PPS,              VT_TEMP,          15003, STR8744,  0,                    NULL,         FL_RONLY, DEV_ALL},     // Kesselvorlauftemperatur Soll
{0x2D2C0004,  CAT_PPS,              VT_TEMP,          15004, STR15004, 0,                    NULL,         FL_RONLY, DEV_ALL},     // Mischervorlauftemperatur
{0x2D570005,  CAT_PPS,              VT_ONOFF,         15005, STR5010,  0,                    NULL,         FL_RONLY, DEV_ALL},     // Trinkwasserladung
{0x2D2B0006,  CAT_PPS,              VT_TEMP,          15006, STR8830,  0,                    NULL,         FL_RONLY, DEV_ALL},     // Trinkwassertemperatur Ist
{0x2D1E0007,  CAT_PPS,              VT_TEMP,          15007, STR1612,  0,                    NULL,         FL_RONLY, DEV_ALL},     // Trinkwassertemperatur Reduziert Soll
{0x2D0B0008,  CAT_PPS,              VT_TEMP,          15008, STR1610,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Trinkwassertemperatur Soll
{0x2D180009,  CAT_PPS,              VT_TEMP,          15009, STR15009, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Position Drehknopf
{0x2D49000A,  CAT_PPS,              VT_ENUM,          15010, STR700,   sizeof(ENUM15010),    ENUM15010,    DEFAULT_FLAG, DEV_ALL}, // Betriebsart
{0x2D4C000B,  CAT_PPS,              VT_ONOFF,         15011, STR15011, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Anwesenheit
{0x2D7C000C,  CAT_PPS,              VT_BYTE,          15012, STR15012, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Verbleibende Feriendauer in Tagen
{0x2D08000E,  CAT_PPS,              VT_TEMP,          15014, STR710,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Raumtemperatur Soll
{0x2D09000F,  CAT_PPS,              VT_TEMP,          15015, STR712,   0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Raumtemperatur Abwesenheit Soll
{0x2D1B0010,  CAT_PPS,              VT_TEMP,          15016, STR714,   0,                    NULL,         FL_RONLY, DEV_ALL}, // Frostschutz-Sollwert
{0x2D1B0011,  CAT_PPS,              VT_TEMP,          15017, STR2212,  0,                    NULL,         FL_RONLY, DEV_ALL}, // Sollwert-Maximum
{0x2D280012,  CAT_PPS,              VT_TEMP,          15018, STR8721,  0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Raumtemperatur Ist
{0x2D600013,  CAT_PPS,              VT_HOUR_MINUTES,  15019, STR15019, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Montag Start
{0x2D600014,  CAT_PPS,              VT_HOUR_MINUTES,  15020, STR15020, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Montag Ende
{0x2D600015,  CAT_PPS,              VT_HOUR_MINUTES,  15021, STR15021, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Montag Start
{0x2D600016,  CAT_PPS,              VT_HOUR_MINUTES,  15022, STR15022, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Montag Ende
{0x2D600017,  CAT_PPS,              VT_HOUR_MINUTES,  15023, STR15023, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Montag Start
{0x2D600018,  CAT_PPS,              VT_HOUR_MINUTES,  15024, STR15024, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Montag Ende
{0x2D610019,  CAT_PPS,              VT_HOUR_MINUTES,  15025, STR15025, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Dienstag Start
{0x2D61001A,  CAT_PPS,              VT_HOUR_MINUTES,  15026, STR15026, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Dienstag Ende
{0x2D61001B,  CAT_PPS,              VT_HOUR_MINUTES,  15027, STR15027, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Dienstag Start
{0x2D61001C,  CAT_PPS,              VT_HOUR_MINUTES,  15028, STR15028, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Dienstag Ende
{0x2D61001D,  CAT_PPS,              VT_HOUR_MINUTES,  15029, STR15029, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Dienstag Start
{0x2D61001E,  CAT_PPS,              VT_HOUR_MINUTES,  15030, STR15030, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Dienstag Ende
{0x2D62001F,  CAT_PPS,              VT_HOUR_MINUTES,  15031, STR15031, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Mittwoch Start
{0x2D620020,  CAT_PPS,              VT_HOUR_MINUTES,  15032, STR15032, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Mittwoch Ende
{0x2D620021,  CAT_PPS,              VT_HOUR_MINUTES,  15033, STR15033, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Mittwoch Start
{0x2D620022,  CAT_PPS,              VT_HOUR_MINUTES,  15034, STR15034, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Mittwoch Ende
{0x2D620023,  CAT_PPS,              VT_HOUR_MINUTES,  15035, STR15035, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Mittwoch Start
{0x2D620024,  CAT_PPS,              VT_HOUR_MINUTES,  15036, STR15036, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Mittwoch Ende
{0x2D630025,  CAT_PPS,              VT_HOUR_MINUTES,  15037, STR15037, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Donnerstag Start
{0x2D630026,  CAT_PPS,              VT_HOUR_MINUTES,  15038, STR15038, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Donnerstag Ende
{0x2D630027,  CAT_PPS,              VT_HOUR_MINUTES,  15039, STR15039, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Donnerstag Start
{0x2D630028,  CAT_PPS,              VT_HOUR_MINUTES,  15040, STR15040, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Donnerstag Ende
{0x2D630029,  CAT_PPS,              VT_HOUR_MINUTES,  15041, STR15041, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Donnerstag Start
{0x2D63002A,  CAT_PPS,              VT_HOUR_MINUTES,  15042, STR15042, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Donnerstag Ende
{0x2D64002B,  CAT_PPS,              VT_HOUR_MINUTES,  15043, STR15043, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Freitag Start
{0x2D64002C,  CAT_PPS,              VT_HOUR_MINUTES,  15044, STR15044, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Freitag Ende
{0x2D64002D,  CAT_PPS,              VT_HOUR_MINUTES,  15045, STR15045, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Freitag Start
{0x2D64002E,  CAT_PPS,              VT_HOUR_MINUTES,  15046, STR15046, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Freitag Ende
{0x2D64002F,  CAT_PPS,              VT_HOUR_MINUTES,  15047, STR15047, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Freitag Start
{0x2D640030,  CAT_PPS,              VT_HOUR_MINUTES,  15048, STR15048, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Freitag Ende
{0x2D650031,  CAT_PPS,              VT_HOUR_MINUTES,  15049, STR15049, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Samstag Start
{0x2D650032,  CAT_PPS,              VT_HOUR_MINUTES,  15050, STR15050, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Samstag Ende
{0x2D650033,  CAT_PPS,              VT_HOUR_MINUTES,  15051, STR15051, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Samstag Start
{0x2D650034,  CAT_PPS,              VT_HOUR_MINUTES,  15052, STR15052, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Samstag Ende
{0x2D650035,  CAT_PPS,              VT_HOUR_MINUTES,  15053, STR15053, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Samstag Start
{0x2D650036,  CAT_PPS,              VT_HOUR_MINUTES,  15054, STR15054, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Samstag Ende
{0x2D660037,  CAT_PPS,              VT_HOUR_MINUTES,  15055, STR15055, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Sonntag Start
{0x2D660038,  CAT_PPS,              VT_HOUR_MINUTES,  15056, STR15056, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 1 Sonntag Ende
{0x2D660039,  CAT_PPS,              VT_HOUR_MINUTES,  15057, STR15057, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Sonntag Start
{0x2D66003A,  CAT_PPS,              VT_HOUR_MINUTES,  15058, STR15058, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 2 Sonntag Ende
{0x2D66003B,  CAT_PPS,              VT_HOUR_MINUTES,  15059, STR15059, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Sonntag Start
{0x2D66003C,  CAT_PPS,              VT_HOUR_MINUTES,  15060, STR15060, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, // Zeitfenster 3 Sonntag Ende
{0x2D79003D,  CAT_PPS,              VT_PPS_TIME,      15061, STR15061, 0,                    NULL,         FL_RONLY, DEV_ALL},     // Heater time and day of week
{0x2D38003E,  CAT_PPS,              VT_ENUM,          15062, STR15062, sizeof(ENUM15062),    ENUM15062,    DEFAULT_FLAG, DEV_ALL}, // QAA Type (0x52 = QAA 50 / 0x53 = QAA 70)
{0x2D4D003F,  CAT_PPS,              VT_BYTE,          15063, STR8009,  0,                    NULL,         FL_RONLY, DEV_ALL},     // Brennerstatus (Mögliche Werte: 0x07 = Brenner ein, 0x0D = Brenner aus, 0x03/0x09/0xFF)
{0x2D190040,  CAT_PPS,              VT_TEMP,          15064, STR15064, 0,                    NULL,         FL_RONLY, DEV_ALL},     // Zieltemperatur (entweder Absenktemperatur oder Komforttemperatur zzgl. Drehknopfposition)
{0x2D690041,  CAT_PPS,              VT_TEMP,          15065, STR15065, 0,                    NULL,         FL_NO_CMD, DEV_ALL},    // Nächstes Heizprogramm
{0x2D480042,  CAT_PPS,              VT_ONOFF,         15066, STR15066, 0,                    NULL,         FL_RONLY, DEV_ALL},     // Manuelles Heizen (0 = Heizprogramm, 1 = Manuell)
{0x2D4F0043,  CAT_PPS,              VT_ONOFF,         15067, STR15067, 0,                    NULL,         FL_RONLY, DEV_ALL},     // Verbindung erkannt (0 = ja, 1 = nein)
#define PPS_AT  0
#define PPS_ATG 1
#define PPS_KVT 2
#define PPS_KVS 3
#define PPS_MVT 4
#define PPS_TWB 5
#define PPS_TWI 6
#define PPS_TWR 7
#define PPS_TWS 8
#define PPS_PDK 9
#define PPS_BA  10
#define PPS_AW  11
#define PPS_FDT 12
#define PPS_MOD 99
#define PPS_RTS 14
#define PPS_RTA 15
#define PPS_FRS 16
#define PPS_SMX 17
#define PPS_RTI 18
#define PPS_S11 19
#define PPS_E11 20
#define PPS_S12 21
#define PPS_E12 22
#define PPS_S13 23
#define PPS_E13 24
#define PPS_S21 25
#define PPS_E21 26
#define PPS_S22 27
#define PPS_E22 28
#define PPS_S23 29
#define PPS_E23 30
#define PPS_S31 31
#define PPS_E31 32
#define PPS_S32 33
#define PPS_E32 34
#define PPS_S33 35
#define PPS_E33 36
#define PPS_S41 37
#define PPS_E41 38
#define PPS_S42 39
#define PPS_E42 40
#define PPS_S43 41
#define PPS_E43 42
#define PPS_S51 43
#define PPS_E51 44
#define PPS_S52 45
#define PPS_E52 46
#define PPS_S53 47
#define PPS_E53 48
#define PPS_S61 49
#define PPS_E61 50
#define PPS_S62 51
#define PPS_E62 52
#define PPS_S63 53
#define PPS_E63 54
#define PPS_S71 55
#define PPS_E71 56
#define PPS_S72 57
#define PPS_E72 58
#define PPS_S73 59
#define PPS_E73 60
#define PPS_TIM 61
#define PPS_QTP 62
#define PPS_BRS 63
#define PPS_RTZ 64
#define PPS_NHP 65
#define PPS_HP 66
#define PPS_CON 67

#define PPS_ANZ 68
#define LAST_ENUM_NR 15062
#define LAST_ENUM ENUM15062

//PPS-Bus commands end

/*
// ProgNrs 10900 to 10999 can be assigned to unrecognised command codes until
// we find a better explanation for them. !Assign STR99999 to all of them.!
*/
// Placeholder to keep the compiler happy with STR99999:
{0xDEADBEEF,  CAT_UNKNOWN,          VT_UNKNOWN,       19999, STR99999, 0,                    NULL,         DEFAULT_FLAG, DEV_ALL}, //

{CMD_END,     CAT_UNKNOWN,          VT_UNKNOWN,       65535, "",       0,                    NULL,         DEFAULT_FLAG, DEV_ALL}
};
