/*
 * This software is developed by Microchip Technology Inc. and its subsidiaries ("Microchip").
 * 
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 * 
 *     1. Redistributions of source code must retain the above copyright notice, this list of
 *        conditions and the following disclaimer.
 *     2. Redistributions in binary form must reproduce the above copyright notice, this list
 *        of conditions and the following disclaimer in the documentation and/or other
 *        materials provided with the distribution.
 *     3. All advertising materials mentioning features or use of this software must display
 *        the following acknowledgement: "This product includes software developed by
 *        Microchip Technology Inc. and its subsidiaries."
 *     4. Microchip's name may not be used to endorse or promote products derived from this
 *        software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _PIC16F688_H_
#define _PIC16F688_H_

/*
 * C Header file for the Microchip PIC Microcontroller
 * PIC16F688
 */
#ifndef _HTC_H_
#warning Header file pic16f688.h included directly. Use #include <htc.h> instead.
#endif

/*
 * Configuration Mask Definitions
 */

// Config Register: CONFIG
#define CONFIG                                              0x2007
// Oscillator Selection bits
// EXTRC oscillator: External RC on RA5/OSC1/CLKIN, CLKOUT function on RA4/OSC2/CLKOUT pin
#define FOSC_EXTRCCLK                                       0xFFFF
// EXTRCIO oscillator: External RC on RA5/OSC1/CLKIN, I/O function on RA4/OSC2/CLKOUT pin
#define FOSC_EXTRCIO                                        0xFFFE
// INTOSC oscillator: CLKOUT function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN
#define FOSC_INTOSCCLK                                      0xFFFD
// INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN
#define FOSC_INTOSCIO                                       0xFFFC
// EC: I/O function on RA4/OSC2/CLKOUT pin, CLKIN on RA5/OSC1/CLKIN
#define FOSC_EC                                             0xFFFB
// HS oscillator: High-speed crystal/resonator on RA4/OSC2/CLKOUT and RA5/OSC1/CLKIN
#define FOSC_HS                                             0xFFFA
// XT oscillator: Crystal/resonator on RA4/OSC2/CLKOUT and RA5/OSC1/CLKINT
#define FOSC_XT                                             0xFFF9
// LP oscillator: Low-power crystal on RA4/OSC2/CLKOUT and RA5/OSC1/CLKIN
#define FOSC_LP                                             0xFFF8
// Watchdog Timer Enable bit
// WDT enabled
#define WDTE_ON                                             0xFFFF
// WDT disabled
#define WDTE_OFF                                            0xFFF7
// Power-up Timer Enable bit
// PWRT disabled
#define PWRTE_OFF                                           0xFFFF
// PWRT enabled
#define PWRTE_ON                                            0xFFEF
// MCLR Pin Function Select bit
// MCLR pin function is MCLR
#define MCLRE_ON                                            0xFFFF
// MCLR pin function is digital input, MCLR internally tied to VDD
#define MCLRE_OFF                                           0xFFDF
// Code Protection bit
// Program memory code protection is disabled
#define CP_OFF                                              0xFFFF
// Program memory code protection is enabled
#define CP_ON                                               0xFFBF
// Data Code Protection bit
// Data memory code protection is disabled
#define CPD_OFF                                             0xFFFF
// Data memory code protection is enabled
#define CPD_ON                                              0xFF7F
// Brown Out Detect
// BOR enabled
#define BOREN_ON                                            0xFFFF
// BOR enabled during operation and disabled in Sleep
#define BOREN_NSLEEP                                        0xFEFF
// BOR controlled by SBOREN bit of the PCON register
#define BOREN_SBODEN                                        0xFDFF
// BOR disabled
#define BOREN_OFF                                           0xFCFF
// Internal External Switchover bit
// Internal External Switchover mode is enabled
#define IESO_ON                                             0xFFFF
// Internal External Switchover mode is disabled
#define IESO_OFF                                            0xFBFF
// Fail-Safe Clock Monitor Enabled bit
// Fail-Safe Clock Monitor is enabled
#define FCMEN_ON                                            0xFFFF
// Fail-Safe Clock Monitor is disabled
#define FCMEN_OFF                                           0xF7FF

/*
 * Register Definitions
 */

// Register: INDF
extern volatile unsigned char           INDF                @ 0x000;
// bitfield definitions
extern volatile union {
    struct {
        unsigned INDF                   :8;
    };
} INDFbits @ 0x000;

// Register: TMR0
extern volatile unsigned char           TMR0                @ 0x001;
// bitfield definitions
extern volatile union {
    struct {
        unsigned TMR0                   :8;
    };
} TMR0bits @ 0x001;

// Register: PCL
extern volatile unsigned char           PCL                 @ 0x002;
// bitfield definitions
extern volatile union {
    struct {
        unsigned PCL                    :8;
    };
} PCLbits @ 0x002;

// Register: STATUS
extern volatile unsigned char           STATUS              @ 0x003;
// bitfield definitions
extern volatile union {
    struct {
        unsigned C                      :1;
        unsigned DC                     :1;
        unsigned Z                      :1;
        unsigned nPD                    :1;
        unsigned nTO                    :1;
        unsigned RP                     :2;
        unsigned IRP                    :1;
    };
    struct {
        unsigned                        :5;
        unsigned RP0                    :1;
        unsigned RP1                    :1;
    };
    struct {
        unsigned CARRY                  :1;
    };
    struct {
        unsigned                        :2;
        unsigned ZERO                   :1;
    };
} STATUSbits @ 0x003;

// Register: FSR
extern volatile unsigned char           FSR                 @ 0x004;
// bitfield definitions
extern volatile union {
    struct {
        unsigned FSR                    :8;
    };
} FSRbits @ 0x004;

// Register: PORTA
extern volatile unsigned char           PORTA               @ 0x005;
// bitfield definitions
extern volatile union {
    struct {
        unsigned RA0                    :1;
        unsigned RA1                    :1;
        unsigned RA2                    :1;
        unsigned RA3                    :1;
        unsigned RA4                    :1;
        unsigned RA5                    :1;
    };
    struct {
        unsigned RA                     :8;
    };
} PORTAbits @ 0x005;

// Register: PORTC
extern volatile unsigned char           PORTC               @ 0x007;
// bitfield definitions
extern volatile union {
    struct {
        unsigned RC0                    :1;
        unsigned RC1                    :1;
        unsigned RC2                    :1;
        unsigned RC3                    :1;
        unsigned RC4                    :1;
        unsigned RC5                    :1;
    };
    struct {
        unsigned RC                     :8;
    };
} PORTCbits @ 0x007;

// Register: PCLATH
extern volatile unsigned char           PCLATH              @ 0x00A;
// bitfield definitions
extern volatile union {
    struct {
        unsigned PCLATH                 :5;
    };
} PCLATHbits @ 0x00A;

// Register: INTCON
extern volatile unsigned char           INTCON              @ 0x00B;
// bitfield definitions
extern volatile union {
    struct {
        unsigned RAIF                   :1;
        unsigned INTF                   :1;
        unsigned T0IF                   :1;
        unsigned RAIE                   :1;
        unsigned INTE                   :1;
        unsigned T0IE                   :1;
        unsigned PEIE                   :1;
        unsigned GIE                    :1;
    };
    struct {
        unsigned                        :2;
        unsigned TMR0IF                 :1;
        unsigned                        :2;
        unsigned TMR0IE                 :1;
    };
} INTCONbits @ 0x00B;

// Register: PIR1
extern volatile unsigned char           PIR1                @ 0x00C;
// bitfield definitions
extern volatile union {
    struct {
        unsigned TMR1IF                 :1;
        unsigned TXIF                   :1;
        unsigned OSFIF                  :1;
        unsigned C1IF                   :1;
        unsigned C2IF                   :1;
        unsigned RCIF                   :1;
        unsigned ADIF                   :1;
        unsigned EEIF                   :1;
    };
    struct {
        unsigned T1IF                   :1;
    };
} PIR1bits @ 0x00C;

// Register: TMR1
extern volatile unsigned short          TMR1                @ 0x00E;
// bitfield definitions
extern volatile union {
    struct {
        unsigned TMR1                   :16;
    };
} TMR1bits @ 0x00E;

// Register: TMR1L
extern volatile unsigned char           TMR1L               @ 0x00E;
// bitfield definitions
extern volatile union {
    struct {
        unsigned TMR1L                  :8;
    };
} TMR1Lbits @ 0x00E;

// Register: TMR1H
extern volatile unsigned char           TMR1H               @ 0x00F;
// bitfield definitions
extern volatile union {
    struct {
        unsigned TMR1H                  :8;
    };
} TMR1Hbits @ 0x00F;

// Register: T1CON
extern volatile unsigned char           T1CON               @ 0x010;
// bitfield definitions
extern volatile union {
    struct {
        unsigned TMR1ON                 :1;
        unsigned TMR1CS                 :1;
        unsigned nT1SYNC                :1;
        unsigned T1OSCEN                :1;
        unsigned T1CKPS                 :2;
        unsigned TMR1GE                 :1;
        unsigned T1GINV                 :1;
    };
    struct {
        unsigned                        :4;
        unsigned T1CKPS0                :1;
        unsigned T1CKPS1                :1;
    };
} T1CONbits @ 0x010;

// Register: BAUDCTL
extern volatile unsigned char           BAUDCTL             @ 0x011;
// bitfield definitions
extern volatile union {
    struct {
        unsigned ABDEN                  :1;
        unsigned WUE                    :1;
        unsigned                        :1;
        unsigned BRG16                  :1;
        unsigned SCKP                   :1;
        unsigned                        :1;
        unsigned RCIDL                  :1;
        unsigned ABDOVF                 :1;
    };
} BAUDCTLbits @ 0x011;

// Register: SPBRGH
extern volatile unsigned char           SPBRGH              @ 0x012;
// bitfield definitions
extern volatile union {
    struct {
        unsigned SPBRGH                 :8;
    };
} SPBRGHbits @ 0x012;

// Register: SPBRG
extern volatile unsigned char           SPBRG               @ 0x013;
// bitfield definitions
extern volatile union {
    struct {
        unsigned SPBRG                  :8;
    };
} SPBRGbits @ 0x013;

// Register: RCREG
extern volatile unsigned char           RCREG               @ 0x014;
// bitfield definitions
extern volatile union {
    struct {
        unsigned RCREG                  :8;
    };
} RCREGbits @ 0x014;

// Register: TXREG
extern volatile unsigned char           TXREG               @ 0x015;
// bitfield definitions
extern volatile union {
    struct {
        unsigned TXREG                  :8;
    };
} TXREGbits @ 0x015;

// Register: TXSTA
extern volatile unsigned char           TXSTA               @ 0x016;
// bitfield definitions
extern volatile union {
    struct {
        unsigned TX9D                   :1;
        unsigned TRMT                   :1;
        unsigned BRGH                   :1;
        unsigned SENDB                  :1;
        unsigned SYNC                   :1;
        unsigned TXEN                   :1;
        unsigned TX9                    :1;
        unsigned CSRC                   :1;
    };
} TXSTAbits @ 0x016;

// Register: RCSTA
extern volatile unsigned char           RCSTA               @ 0x017;
// bitfield definitions
extern volatile union {
    struct {
        unsigned RX9D                   :1;
        unsigned OERR                   :1;
        unsigned FERR                   :1;
        unsigned ADDEN                  :1;
        unsigned CREN                   :1;
        unsigned SREN                   :1;
        unsigned RX9                    :1;
        unsigned SPEN                   :1;
    };
} RCSTAbits @ 0x017;

// Register: WDTCON
extern volatile unsigned char           WDTCON              @ 0x018;
// bitfield definitions
extern volatile union {
    struct {
        unsigned SWDTEN                 :1;
        unsigned WDTPS                  :4;
    };
    struct {
        unsigned                        :1;
        unsigned WDTPS0                 :1;
        unsigned WDTPS1                 :1;
        unsigned WDTPS2                 :1;
        unsigned WDTPS3                 :1;
    };
} WDTCONbits @ 0x018;

// Register: CMCON0
extern volatile unsigned char           CMCON0              @ 0x019;
// bitfield definitions
extern volatile union {
    struct {
        unsigned CM                     :3;
        unsigned CIS                    :1;
        unsigned C1INV                  :1;
        unsigned C2INV                  :1;
        unsigned C1OUT                  :1;
        unsigned C2OUT                  :1;
    };
    struct {
        unsigned CM0                    :1;
        unsigned CM1                    :1;
        unsigned CM2                    :1;
    };
} CMCON0bits @ 0x019;

// Register: CMCON1
extern volatile unsigned char           CMCON1              @ 0x01A;
// bitfield definitions
extern volatile union {
    struct {
        unsigned C2SYNC                 :1;
        unsigned T1GSS                  :1;
    };
} CMCON1bits @ 0x01A;

// Register: ADRESH
extern volatile unsigned char           ADRESH              @ 0x01E;
// bitfield definitions
extern volatile union {
    struct {
        unsigned ADRESH                 :8;
    };
} ADRESHbits @ 0x01E;

// Register: ADCON0
extern volatile unsigned char           ADCON0              @ 0x01F;
// bitfield definitions
extern volatile union {
    struct {
        unsigned ADON                   :1;
        unsigned GO_nDONE               :1;
        unsigned CHS                    :3;
        unsigned                        :1;
        unsigned VCFG                   :1;
        unsigned ADFM                   :1;
    };
    struct {
        unsigned ADON                   :1;
        unsigned GO_nDONE               :1;
        unsigned CHS                    :3;
        unsigned                        :1;
        unsigned VCFG                   :1;
        unsigned ADFM                   :1;
    };
    struct {
        unsigned                        :1;
        unsigned GO                     :1;
        unsigned CHS0                   :1;
        unsigned CHS1                   :1;
        unsigned CHS2                   :1;
    };
    struct {
        unsigned                        :1;
        unsigned nDONE                  :1;
    };
    struct {
        unsigned                        :1;
        unsigned GO_DONE                :1;
    };
} ADCON0bits @ 0x01F;

// Register: OPTION_REG
extern volatile unsigned char           OPTION_REG          @ 0x081;
// bitfield definitions
extern volatile union {
    struct {
        unsigned PS                     :3;
        unsigned PSA                    :1;
        unsigned T0SE                   :1;
        unsigned T0CS                   :1;
        unsigned INTEDG                 :1;
        unsigned nRAPU                  :1;
    };
    struct {
        unsigned PS0                    :1;
        unsigned PS1                    :1;
        unsigned PS2                    :1;
    };
} OPTION_REGbits @ 0x081;

// Register: TRISA
extern volatile unsigned char           TRISA               @ 0x085;
// bitfield definitions
extern volatile union {
    struct {
        unsigned TRISA0                 :1;
        unsigned TRISA1                 :1;
        unsigned TRISA2                 :1;
        unsigned TRISA3                 :1;
        unsigned TRISA4                 :1;
        unsigned TRISA5                 :1;
    };
    struct {
        unsigned TRISA                  :8;
    };
} TRISAbits @ 0x085;

// Register: TRISC
extern volatile unsigned char           TRISC               @ 0x087;
// bitfield definitions
extern volatile union {
    struct {
        unsigned TRISC0                 :1;
        unsigned TRISC1                 :1;
        unsigned TRISC2                 :1;
        unsigned TRISC3                 :1;
        unsigned TRISC4                 :1;
        unsigned TRISC5                 :1;
    };
    struct {
        unsigned TRISC                  :8;
    };
} TRISCbits @ 0x087;

// Register: PIE1
extern volatile unsigned char           PIE1                @ 0x08C;
// bitfield definitions
extern volatile union {
    struct {
        unsigned TMR1IE                 :1;
        unsigned TXIE                   :1;
        unsigned OSFIE                  :1;
        unsigned C1IE                   :1;
        unsigned C2IE                   :1;
        unsigned RCIE                   :1;
        unsigned ADIE                   :1;
        unsigned EEIE                   :1;
    };
    struct {
        unsigned T1IE                   :1;
    };
} PIE1bits @ 0x08C;

// Register: PCON
extern volatile unsigned char           PCON                @ 0x08E;
// bitfield definitions
extern volatile union {
    struct {
        unsigned nBOR                   :1;
        unsigned nPOR                   :1;
        unsigned                        :2;
        unsigned SBODEN                 :1;
        unsigned ULPWUE                 :1;
    };
    struct {
        unsigned nBOD                   :1;
    };
} PCONbits @ 0x08E;

// Register: OSCCON
extern volatile unsigned char           OSCCON              @ 0x08F;
// bitfield definitions
extern volatile union {
    struct {
        unsigned SCS                    :1;
        unsigned LTS                    :1;
        unsigned HTS                    :1;
        unsigned OSTS                   :1;
        unsigned IOSCF                  :3;
    };
    struct {
        unsigned                        :4;
        unsigned IRCF0                  :1;
        unsigned IRCF1                  :1;
        unsigned IRCF2                  :1;
    };
} OSCCONbits @ 0x08F;

// Register: OSCTUNE
extern volatile unsigned char           OSCTUNE             @ 0x090;
// bitfield definitions
extern volatile union {
    struct {
        unsigned TUN                    :5;
    };
    struct {
        unsigned TUN0                   :1;
        unsigned TUN1                   :1;
        unsigned TUN2                   :1;
        unsigned TUN3                   :1;
        unsigned TUN4                   :1;
    };
} OSCTUNEbits @ 0x090;

// Register: ANSEL
extern volatile unsigned char           ANSEL               @ 0x091;
// bitfield definitions
extern volatile union {
    struct {
        unsigned ANS0                   :1;
        unsigned ANS1                   :1;
        unsigned ANS2                   :1;
        unsigned ANS3                   :1;
        unsigned ANS4                   :1;
        unsigned ANS5                   :1;
        unsigned ANS6                   :1;
        unsigned ANS7                   :1;
    };
} ANSELbits @ 0x091;

// Register: WPUA
extern volatile unsigned char           WPUA                @ 0x095;
// aliases
extern volatile unsigned char           WPU                 @ 0x095;
// bitfield definitions
extern volatile union {
    struct {
        unsigned WPUA0                  :1;
        unsigned WPUA1                  :1;
        unsigned WPUA2                  :1;
        unsigned                        :1;
        unsigned WPUA4                  :1;
        unsigned WPUA5                  :1;
    };
    struct {
        unsigned WPU0                   :1;
        unsigned WPU1                   :1;
        unsigned WPU2                   :1;
        unsigned                        :1;
        unsigned WPU4                   :1;
        unsigned WPU5                   :1;
    };
} WPUAbits @ 0x095;
// alias bitfield definitions
extern volatile union {
    struct {
        unsigned WPUA0                  :1;
        unsigned WPUA1                  :1;
        unsigned WPUA2                  :1;
        unsigned                        :1;
        unsigned WPUA4                  :1;
        unsigned WPUA5                  :1;
    };
    struct {
        unsigned WPU0                   :1;
        unsigned WPU1                   :1;
        unsigned WPU2                   :1;
        unsigned                        :1;
        unsigned WPU4                   :1;
        unsigned WPU5                   :1;
    };
} WPUbits @ 0x095;

// Register: IOCA
extern volatile unsigned char           IOCA                @ 0x096;
// aliases
extern volatile unsigned char           IOC                 @ 0x096;
// bitfield definitions
extern volatile union {
    struct {
        unsigned IOCA0                  :1;
        unsigned IOCA1                  :1;
        unsigned IOCA2                  :1;
        unsigned IOCA3                  :1;
        unsigned IOCA4                  :1;
        unsigned IOCA5                  :1;
    };
    struct {
        unsigned IOC0                   :1;
        unsigned IOC1                   :1;
        unsigned IOC2                   :1;
        unsigned IOC3                   :1;
        unsigned IOC4                   :1;
        unsigned IOC5                   :1;
    };
} IOCAbits @ 0x096;
// alias bitfield definitions
extern volatile union {
    struct {
        unsigned IOCA0                  :1;
        unsigned IOCA1                  :1;
        unsigned IOCA2                  :1;
        unsigned IOCA3                  :1;
        unsigned IOCA4                  :1;
        unsigned IOCA5                  :1;
    };
    struct {
        unsigned IOC0                   :1;
        unsigned IOC1                   :1;
        unsigned IOC2                   :1;
        unsigned IOC3                   :1;
        unsigned IOC4                   :1;
        unsigned IOC5                   :1;
    };
} IOCbits @ 0x096;

// Register: EEDATH
extern volatile unsigned char           EEDATH              @ 0x097;
// bitfield definitions
extern volatile union {
    struct {
        unsigned EEDATH                 :6;
    };
} EEDATHbits @ 0x097;

// Register: EEADRH
extern volatile unsigned char           EEADRH              @ 0x098;
// bitfield definitions
extern volatile union {
    struct {
        unsigned EEADRH                 :4;
    };
} EEADRHbits @ 0x098;

// Register: VRCON
extern volatile unsigned char           VRCON               @ 0x099;
// bitfield definitions
extern volatile union {
    struct {
        unsigned VR                     :4;
        unsigned                        :1;
        unsigned VRR                    :1;
        unsigned                        :1;
        unsigned VREN                   :1;
    };
    struct {
        unsigned VR0                    :1;
        unsigned VR1                    :1;
        unsigned VR2                    :1;
        unsigned VR3                    :1;
    };
} VRCONbits @ 0x099;

// Register: EEDAT
extern volatile unsigned char           EEDAT               @ 0x09A;
// aliases
extern volatile unsigned char           EEDATA              @ 0x09A;
// bitfield definitions
extern volatile union {
    struct {
        unsigned EEDAT                  :8;
    };
} EEDATbits @ 0x09A;
// alias bitfield definitions
extern volatile union {
    struct {
        unsigned EEDAT                  :8;
    };
} EEDATAbits @ 0x09A;

// Register: EEADR
extern volatile unsigned char           EEADR               @ 0x09B;
// bitfield definitions
extern volatile union {
    struct {
        unsigned EEADR                  :8;
    };
} EEADRbits @ 0x09B;

// Register: EECON1
extern volatile unsigned char           EECON1              @ 0x09C;
// bitfield definitions
extern volatile union {
    struct {
        unsigned RD                     :1;
        unsigned WR                     :1;
        unsigned WREN                   :1;
        unsigned WRERR                  :1;
        unsigned                        :3;
        unsigned EEPGD                  :1;
    };
} EECON1bits @ 0x09C;

// Register: EECON2
extern volatile unsigned char           EECON2              @ 0x09D;
// bitfield definitions
extern volatile union {
    struct {
        unsigned EECON2                 :8;
    };
} EECON2bits @ 0x09D;

// Register: ADRESL
extern volatile unsigned char           ADRESL              @ 0x09E;
// bitfield definitions
extern volatile union {
    struct {
        unsigned ADRESL                 :8;
    };
} ADRESLbits @ 0x09E;

// Register: ADCON1
extern volatile unsigned char           ADCON1              @ 0x09F;
// bitfield definitions
extern volatile union {
    struct {
        unsigned                        :4;
        unsigned ADCS                   :3;
    };
    struct {
        unsigned                        :4;
        unsigned ADCS0                  :1;
        unsigned ADCS1                  :1;
        unsigned ADCS2                  :1;
    };
} ADCON1bits @ 0x09F;

/*
 * Bit Definitions
 */
#define _DEPRECATED __attribute__((__deprecated__))
extern volatile bit                     ABDEN               @ (((unsigned) &BAUDCTL)*8) + 0;
extern volatile bit                     ABDOVF              @ (((unsigned) &BAUDCTL)*8) + 7;
extern volatile bit                     ADCS0               @ (((unsigned) &ADCON1)*8) + 4;
extern volatile bit                     ADCS1               @ (((unsigned) &ADCON1)*8) + 5;
extern volatile bit                     ADCS2               @ (((unsigned) &ADCON1)*8) + 6;
extern volatile bit                     ADDEN               @ (((unsigned) &RCSTA)*8) + 3;
extern volatile bit                     ADFM                @ (((unsigned) &ADCON0)*8) + 7;
extern volatile bit                     ADIE                @ (((unsigned) &PIE1)*8) + 6;
extern volatile bit                     ADIF                @ (((unsigned) &PIR1)*8) + 6;
extern volatile bit                     ADON                @ (((unsigned) &ADCON0)*8) + 0;
extern volatile bit                     ANS0                @ (((unsigned) &ANSEL)*8) + 0;
extern volatile bit                     ANS1                @ (((unsigned) &ANSEL)*8) + 1;
extern volatile bit                     ANS2                @ (((unsigned) &ANSEL)*8) + 2;
extern volatile bit                     ANS3                @ (((unsigned) &ANSEL)*8) + 3;
extern volatile bit                     ANS4                @ (((unsigned) &ANSEL)*8) + 4;
extern volatile bit                     ANS5                @ (((unsigned) &ANSEL)*8) + 5;
extern volatile bit                     ANS6                @ (((unsigned) &ANSEL)*8) + 6;
extern volatile bit                     ANS7                @ (((unsigned) &ANSEL)*8) + 7;
extern volatile bit                     BRG16               @ (((unsigned) &BAUDCTL)*8) + 3;
extern volatile bit                     BRGH                @ (((unsigned) &TXSTA)*8) + 2;
extern volatile bit                     C1IE                @ (((unsigned) &PIE1)*8) + 3;
extern volatile bit                     C1IF                @ (((unsigned) &PIR1)*8) + 3;
extern volatile bit                     C1INV               @ (((unsigned) &CMCON0)*8) + 4;
extern volatile bit                     C1OUT               @ (((unsigned) &CMCON0)*8) + 6;
extern volatile bit                     C2IE                @ (((unsigned) &PIE1)*8) + 4;
extern volatile bit                     C2IF                @ (((unsigned) &PIR1)*8) + 4;
extern volatile bit                     C2INV               @ (((unsigned) &CMCON0)*8) + 5;
extern volatile bit                     C2OUT               @ (((unsigned) &CMCON0)*8) + 7;
extern volatile bit                     C2SYNC              @ (((unsigned) &CMCON1)*8) + 0;
extern volatile bit                     CARRY               @ (((unsigned) &STATUS)*8) + 0;
extern volatile bit                     CHS0                @ (((unsigned) &ADCON0)*8) + 2;
extern volatile bit                     CHS1                @ (((unsigned) &ADCON0)*8) + 3;
extern volatile bit                     CHS2                @ (((unsigned) &ADCON0)*8) + 4;
extern volatile bit                     CIS                 @ (((unsigned) &CMCON0)*8) + 3;
extern volatile bit                     CM0                 @ (((unsigned) &CMCON0)*8) + 0;
extern volatile bit                     CM1                 @ (((unsigned) &CMCON0)*8) + 1;
extern volatile bit                     CM2                 @ (((unsigned) &CMCON0)*8) + 2;
extern volatile bit                     CREN                @ (((unsigned) &RCSTA)*8) + 4;
extern volatile bit                     CSRC                @ (((unsigned) &TXSTA)*8) + 7;
extern volatile bit                     DC                  @ (((unsigned) &STATUS)*8) + 1;
extern volatile bit                     EEIE                @ (((unsigned) &PIE1)*8) + 7;
extern volatile bit                     EEIF                @ (((unsigned) &PIR1)*8) + 7;
extern volatile bit                     EEPGD               @ (((unsigned) &EECON1)*8) + 7;
extern volatile bit                     FERR                @ (((unsigned) &RCSTA)*8) + 2;
extern volatile bit                     GIE                 @ (((unsigned) &INTCON)*8) + 7;
extern volatile bit                     GO                  @ (((unsigned) &ADCON0)*8) + 1;
extern volatile bit                     GO_DONE             @ (((unsigned) &ADCON0)*8) + 1;
extern volatile bit                     GO_nDONE            @ (((unsigned) &ADCON0)*8) + 1;
extern volatile bit                     HTS                 @ (((unsigned) &OSCCON)*8) + 2;
extern volatile bit                     INTE                @ (((unsigned) &INTCON)*8) + 4;
extern volatile bit                     INTEDG              @ (((unsigned) &OPTION_REG)*8) + 6;
extern volatile bit                     INTF                @ (((unsigned) &INTCON)*8) + 1;
extern volatile bit                     IOC0                @ (((unsigned) &IOCA)*8) + 0;
extern volatile bit                     IOC1                @ (((unsigned) &IOCA)*8) + 1;
extern volatile bit                     IOC2                @ (((unsigned) &IOCA)*8) + 2;
extern volatile bit                     IOC3                @ (((unsigned) &IOCA)*8) + 3;
extern volatile bit                     IOC4                @ (((unsigned) &IOCA)*8) + 4;
extern volatile bit                     IOC5                @ (((unsigned) &IOCA)*8) + 5;
extern volatile bit                     IOCA0               @ (((unsigned) &IOCA)*8) + 0;
extern volatile bit                     IOCA1               @ (((unsigned) &IOCA)*8) + 1;
extern volatile bit                     IOCA2               @ (((unsigned) &IOCA)*8) + 2;
extern volatile bit                     IOCA3               @ (((unsigned) &IOCA)*8) + 3;
extern volatile bit                     IOCA4               @ (((unsigned) &IOCA)*8) + 4;
extern volatile bit                     IOCA5               @ (((unsigned) &IOCA)*8) + 5;
extern volatile bit                     IRCF0               @ (((unsigned) &OSCCON)*8) + 4;
extern volatile bit                     IRCF1               @ (((unsigned) &OSCCON)*8) + 5;
extern volatile bit                     IRCF2               @ (((unsigned) &OSCCON)*8) + 6;
extern volatile bit                     IRP                 @ (((unsigned) &STATUS)*8) + 7;
extern volatile bit                     LTS                 @ (((unsigned) &OSCCON)*8) + 1;
extern volatile bit                     OERR                @ (((unsigned) &RCSTA)*8) + 1;
extern volatile bit                     OSFIE               @ (((unsigned) &PIE1)*8) + 2;
extern volatile bit                     OSFIF               @ (((unsigned) &PIR1)*8) + 2;
extern volatile bit                     OSTS                @ (((unsigned) &OSCCON)*8) + 3;
extern volatile bit                     PEIE                @ (((unsigned) &INTCON)*8) + 6;
extern volatile bit                     PS0                 @ (((unsigned) &OPTION_REG)*8) + 0;
extern volatile bit                     PS1                 @ (((unsigned) &OPTION_REG)*8) + 1;
extern volatile bit                     PS2                 @ (((unsigned) &OPTION_REG)*8) + 2;
extern volatile bit                     PSA                 @ (((unsigned) &OPTION_REG)*8) + 3;
extern volatile bit                     RA0                 @ (((unsigned) &PORTA)*8) + 0;
extern volatile bit                     RA1                 @ (((unsigned) &PORTA)*8) + 1;
extern volatile bit                     RA2                 @ (((unsigned) &PORTA)*8) + 2;
extern volatile bit                     RA3                 @ (((unsigned) &PORTA)*8) + 3;
extern volatile bit                     RA4                 @ (((unsigned) &PORTA)*8) + 4;
extern volatile bit                     RA5                 @ (((unsigned) &PORTA)*8) + 5;
extern volatile bit                     RAIE                @ (((unsigned) &INTCON)*8) + 3;
extern volatile bit                     RAIF                @ (((unsigned) &INTCON)*8) + 0;
extern volatile bit                     RC0                 @ (((unsigned) &PORTC)*8) + 0;
extern volatile bit                     RC1                 @ (((unsigned) &PORTC)*8) + 1;
extern volatile bit                     RC2                 @ (((unsigned) &PORTC)*8) + 2;
extern volatile bit                     RC3                 @ (((unsigned) &PORTC)*8) + 3;
extern volatile bit                     RC4                 @ (((unsigned) &PORTC)*8) + 4;
extern volatile bit                     RC5                 @ (((unsigned) &PORTC)*8) + 5;
extern volatile bit                     RCIDL               @ (((unsigned) &BAUDCTL)*8) + 6;
extern volatile bit                     RCIE                @ (((unsigned) &PIE1)*8) + 5;
extern volatile bit                     RCIF                @ (((unsigned) &PIR1)*8) + 5;
extern volatile bit                     RD                  @ (((unsigned) &EECON1)*8) + 0;
extern volatile bit                     RP0                 @ (((unsigned) &STATUS)*8) + 5;
extern volatile bit                     RP1                 @ (((unsigned) &STATUS)*8) + 6;
extern volatile bit                     RX9                 @ (((unsigned) &RCSTA)*8) + 6;
extern volatile bit                     RX9D                @ (((unsigned) &RCSTA)*8) + 0;
extern volatile bit                     SBODEN              @ (((unsigned) &PCON)*8) + 4;
extern volatile bit                     SCKP                @ (((unsigned) &BAUDCTL)*8) + 4;
extern volatile bit                     SCS                 @ (((unsigned) &OSCCON)*8) + 0;
extern volatile bit                     SENDB               @ (((unsigned) &TXSTA)*8) + 3;
extern volatile bit                     SPEN                @ (((unsigned) &RCSTA)*8) + 7;
extern volatile bit                     SREN                @ (((unsigned) &RCSTA)*8) + 5;
extern volatile bit                     SWDTEN              @ (((unsigned) &WDTCON)*8) + 0;
extern volatile bit                     SYNC                @ (((unsigned) &TXSTA)*8) + 4;
extern volatile bit                     T0CS                @ (((unsigned) &OPTION_REG)*8) + 5;
extern volatile bit                     T0IE                @ (((unsigned) &INTCON)*8) + 5;
extern volatile bit                     T0IF                @ (((unsigned) &INTCON)*8) + 2;
extern volatile bit                     T0SE                @ (((unsigned) &OPTION_REG)*8) + 4;
extern volatile bit                     T1CKPS0             @ (((unsigned) &T1CON)*8) + 4;
extern volatile bit                     T1CKPS1             @ (((unsigned) &T1CON)*8) + 5;
extern volatile bit                     T1GINV              @ (((unsigned) &T1CON)*8) + 7;
extern volatile bit                     T1GSS               @ (((unsigned) &CMCON1)*8) + 1;
extern volatile bit                     T1IE                @ (((unsigned) &PIE1)*8) + 0;
extern volatile bit                     T1IF                @ (((unsigned) &PIR1)*8) + 0;
extern volatile bit                     T1OSCEN             @ (((unsigned) &T1CON)*8) + 3;
extern volatile bit                     TMR0IE              @ (((unsigned) &INTCON)*8) + 5;
extern volatile bit                     TMR0IF              @ (((unsigned) &INTCON)*8) + 2;
extern volatile bit                     TMR1CS              @ (((unsigned) &T1CON)*8) + 1;
extern volatile bit                     TMR1GE              @ (((unsigned) &T1CON)*8) + 6;
extern volatile bit                     TMR1IE              @ (((unsigned) &PIE1)*8) + 0;
extern volatile bit                     TMR1IF              @ (((unsigned) &PIR1)*8) + 0;
extern volatile bit                     TMR1ON              @ (((unsigned) &T1CON)*8) + 0;
extern volatile bit                     TRISA0              @ (((unsigned) &TRISA)*8) + 0;
extern volatile bit                     TRISA1              @ (((unsigned) &TRISA)*8) + 1;
extern volatile bit                     TRISA2              @ (((unsigned) &TRISA)*8) + 2;
extern volatile bit                     TRISA3              @ (((unsigned) &TRISA)*8) + 3;
extern volatile bit                     TRISA4              @ (((unsigned) &TRISA)*8) + 4;
extern volatile bit                     TRISA5              @ (((unsigned) &TRISA)*8) + 5;
extern volatile bit                     TRISC0              @ (((unsigned) &TRISC)*8) + 0;
extern volatile bit                     TRISC1              @ (((unsigned) &TRISC)*8) + 1;
extern volatile bit                     TRISC2              @ (((unsigned) &TRISC)*8) + 2;
extern volatile bit                     TRISC3              @ (((unsigned) &TRISC)*8) + 3;
extern volatile bit                     TRISC4              @ (((unsigned) &TRISC)*8) + 4;
extern volatile bit                     TRISC5              @ (((unsigned) &TRISC)*8) + 5;
extern volatile bit                     TRMT                @ (((unsigned) &TXSTA)*8) + 1;
extern volatile bit                     TUN0                @ (((unsigned) &OSCTUNE)*8) + 0;
extern volatile bit                     TUN1                @ (((unsigned) &OSCTUNE)*8) + 1;
extern volatile bit                     TUN2                @ (((unsigned) &OSCTUNE)*8) + 2;
extern volatile bit                     TUN3                @ (((unsigned) &OSCTUNE)*8) + 3;
extern volatile bit                     TUN4                @ (((unsigned) &OSCTUNE)*8) + 4;
extern volatile bit                     TX9                 @ (((unsigned) &TXSTA)*8) + 6;
extern volatile bit                     TX9D                @ (((unsigned) &TXSTA)*8) + 0;
extern volatile bit                     TXEN                @ (((unsigned) &TXSTA)*8) + 5;
extern volatile bit                     TXIE                @ (((unsigned) &PIE1)*8) + 1;
extern volatile bit                     TXIF                @ (((unsigned) &PIR1)*8) + 1;
extern volatile bit                     ULPWUE              @ (((unsigned) &PCON)*8) + 5;
extern volatile bit                     VCFG                @ (((unsigned) &ADCON0)*8) + 6;
extern volatile bit                     VR0                 @ (((unsigned) &VRCON)*8) + 0;
extern volatile bit                     VR1                 @ (((unsigned) &VRCON)*8) + 1;
extern volatile bit                     VR2                 @ (((unsigned) &VRCON)*8) + 2;
extern volatile bit                     VR3                 @ (((unsigned) &VRCON)*8) + 3;
extern volatile bit                     VREN                @ (((unsigned) &VRCON)*8) + 7;
extern volatile bit                     VRR                 @ (((unsigned) &VRCON)*8) + 5;
extern volatile bit                     WDTPS0              @ (((unsigned) &WDTCON)*8) + 1;
extern volatile bit                     WDTPS1              @ (((unsigned) &WDTCON)*8) + 2;
extern volatile bit                     WDTPS2              @ (((unsigned) &WDTCON)*8) + 3;
extern volatile bit                     WDTPS3              @ (((unsigned) &WDTCON)*8) + 4;
extern volatile bit                     WPU0                @ (((unsigned) &WPUA)*8) + 0;
extern volatile bit                     WPU1                @ (((unsigned) &WPUA)*8) + 1;
extern volatile bit                     WPU2                @ (((unsigned) &WPUA)*8) + 2;
extern volatile bit                     WPU4                @ (((unsigned) &WPUA)*8) + 4;
extern volatile bit                     WPU5                @ (((unsigned) &WPUA)*8) + 5;
extern volatile bit                     WPUA0               @ (((unsigned) &WPUA)*8) + 0;
extern volatile bit                     WPUA1               @ (((unsigned) &WPUA)*8) + 1;
extern volatile bit                     WPUA2               @ (((unsigned) &WPUA)*8) + 2;
extern volatile bit                     WPUA4               @ (((unsigned) &WPUA)*8) + 4;
extern volatile bit                     WPUA5               @ (((unsigned) &WPUA)*8) + 5;
extern volatile bit                     WR                  @ (((unsigned) &EECON1)*8) + 1;
extern volatile bit                     WREN                @ (((unsigned) &EECON1)*8) + 2;
extern volatile bit                     WRERR               @ (((unsigned) &EECON1)*8) + 3;
extern volatile bit                     WUE                 @ (((unsigned) &BAUDCTL)*8) + 1;
extern volatile bit                     ZERO                @ (((unsigned) &STATUS)*8) + 2;
extern volatile bit                     nBOD                @ (((unsigned) &PCON)*8) + 0;
extern volatile bit                     nBOR                @ (((unsigned) &PCON)*8) + 0;
extern volatile bit                     nDONE               @ (((unsigned) &ADCON0)*8) + 1;
extern volatile bit                     nPD                 @ (((unsigned) &STATUS)*8) + 3;
extern volatile bit                     nPOR                @ (((unsigned) &PCON)*8) + 1;
extern volatile bit                     nRAPU               @ (((unsigned) &OPTION_REG)*8) + 7;
extern volatile bit                     nT1SYNC             @ (((unsigned) &T1CON)*8) + 2;
extern volatile bit                     nTO                 @ (((unsigned) &STATUS)*8) + 4;

#endif // _PIC16F688_H_
