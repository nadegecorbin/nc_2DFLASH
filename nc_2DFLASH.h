//    -----------------------------------------------------------------------------
//      Copyright (C) Siemens AG 1998  All Rights Reserved.
//    -----------------------------------------------------------------------------
//
//     Project: NUMARIS/4
//        File: \n4_servers1\pkg\MrServers\MrImaging\seq\nc_2DFLASH\nc_2DFLASH.h
//     Version: \main\10
//      Author: Clinical
//        Date: 2013-09-24 12:39:02 +02:00
//
//        Lang: C++
//
//     Descrip: Declarations for nc_2DFLASH.cpp
//
//     Remarks: This is the demo sequence nc_2DFLASH.
//              DO NOT base any diagnosis on images generated by this sequence.
//
//    -----------------------------------------------------------------------------


// Make sure that this header is read only once:
#ifndef nc_2DFLASH_h
#define nc_2DFLASH_h 1


//------------------------------
// Includes
//------------------------------

#include "MrServers/MrImaging/libSBB/StdSeqIF.h"                   // Standard Sequence interface
#include "MrServers/MrImaging/libSeqUtil/libSeqUtil.h"             // Support functions

#include "MrServers/MrMeasSrv/SeqFW/libGSL/libGSL.h"               // fGSL... prototypes
#include "MrServers/MrMeasSrv/SeqFW/libSSL/libSSL.h"               // fSSL... prototypes
#include "MrServers/MrImaging/libSBB/libSBBmsg.h"                  // SBB_... error codes

#include "MrServers/MrProtSrv/MrProt/KSpace/MrKSpace.h"            // For KSpace
#include "MrServers/MrProtSrv/MrProt/MeasParameter/MrSysSpec.h"    // For GradSpec
#include "MrServers/MrProtSrv/MrProt/MeasParameter/MrRXSpec.h"     // For MrRXSpec

#include "MrServers/MrProtSrv/MrProt/MrProt.h"                     // MrProt
#include "ProtBasic/Interfaces/SeqLim.h"                           // SeqLim
#include "MrServers/MrProtSrv/MrProt/SeqIF/SeqExpo.h"              // SeqExpo

#include "MrServers/MrMeasSrv/SeqIF/libRT/sREADOUT.h"              // sREADOUT
#include "MrServers/MrMeasSrv/SeqIF/libRT/sGRAD_PULSE.h"           // sGRAD_PULSE
#include "MrServers/MrMeasSrv/SeqIF/libRT/sRF_PULSE.h"             // sRF_PULSE
#include "MrServers/MrMeasSrv/SeqIF/libRT/sFREQ_PHASE.h"           // sFREQ_PHASE

#include "MrCommon/MrGlobalDefinitions/MrResult.h"                 // Messages
#include "MrServers/MrMeasSrv/SeqIF/Sequence/sequmsg.h"            // Messages

#ifdef WIN32
#include "TCHAR.h"
#endif

#ifdef BUILD_SEQU
#define __OWNER
#endif

// The following include is necessary for the DLL generation
#include "MrCommon/MrGlobalDefinitions/ImpExpCtrl.h"

//------------------------------
// Forward declarations
//------------------------------

class MrProt;
class SeqLim;
class SeqExpo;
class Sequence;

namespace SEQ_NAMESPACE
{
    // forward declaration
    class nc_2DFLASHUI;

    /**
    * @brief The nc_2DFLASH sequence class is intended as a demo implementation for teaching purposes. 
    * Therefore, all functions are implemented in a "minimalistic" fashion.
    */
    class __IMP_EXP nc_2DFLASH : public StdSeqIF
    {
    public:

        //  -------------------------------------------------------------------------- 
        //                                                                     
        //  Name        :  nc_2DFLASH::nc_2DFLASH                                
        //                                                                     
        //  Description :  
        /// \brief         Initialization of class members                     
        //                                                                     
        //  Return      :  void                                                
        //                                                                     
        //  -------------------------------------------------------------------------- 
        nc_2DFLASH();

        //  -------------------------------------------------------------------------- 
        //                                                                     
        //  Name        :  nc_2DFLASH::~nc_2DFLASH                               
        //  
        //  Description :  
        /// \brief         Destructor. Deletes existing nc_2DFLASHUI instances.
        //                                                                     
        //  Return      :  void                                                
        //
        //  -------------------------------------------------------------------------- 
        virtual ~nc_2DFLASH();

        //  -------------------------------------------------------------------------- 
        //                                                                  
        //   Name        :  nc_2DFLASH::initialize                             
        //                                                               
        //   Description :  
        ///  \brief         Initialization of the sequence       </b>  
        /// 
        ///                 The "hard limits" for the protocol parameters are set.
        ///                 The hard limits define the maximum allowed range for each parameter. 
        ///                 Also, any parameters that are not dependent on MrProt are defined.
        ///                 On the host, the nc_2DFLASHUI object (m_pUI) will actually contain sensible data after nc_2DFLASH::initialize.
        ///                 On the measurement system, it is basically an empty object. 
        ///                                                                              
        //   Return      :  NLS status
        //                  If running on a Windows-32-machine, the status will indicate if the creation of nc_2DFLASHUI was successful.
        //                  If not running on a Windows-32-machine, the return value is always "SEQU__NORMAL"
        //                                                                               
        //   --------------------------------------------------------------------------  
        virtual NLSStatus initialize(SeqLim &rSeqLim);


        //  -------------------------------------------------------------------------- 
        //
        //  Name        :  nc_2DFLASH::prepare                                          
        //                                                                             
        //  Description :  
        ///  \brief <b>     Preparation of the sequence during binary search and prior to sequence execution  </b>
        ///
        ///                 This method verifies that the current protocol is valid 
        ///                 (i.e. a sequence run with the given parameters is possible).
        ///
        ///                 The method is called during the binary search (graphical user interface of EXAM or POET)
        ///                 and prior to executing a sequence.
        ///
        //  Return      :  NLS status                                                  
        //                                                                             
        //  -------------------------------------------------------------------------- 
        virtual NLSStatus prepare(MrProt &rMrProt, SeqLim &rSeqLim, MrProtocolData::SeqExpo &rSeqExpo);

        //  -------------------------------------------------------------------------- 
        //                                                                             
        //  Name        :  nc_2DFLASH::check                                            
        //                                                                             
        //  Description :  
        /// \brief  <b>    Check of the sequence for gradient stimulation </b>     
        /// 
        ///                This method is called on the host by the framework prior to a measurement to ensure that 
        ///                 - no gradient amplitude or slew rate overflow occurs 
        ///                 - the stimulation will not exceed the threshold  
        ///
        //  Return      :  NLS status                                                  
        //                                                                             
        //  -------------------------------------------------------------------------- 
        virtual NLSStatus check(MrProt &rMrProt, SeqLim &rSeqLim, MrProtocolData::SeqExpo &rSeqExpo, SEQCheckMode *  pSEQCheckMode);


        //  -------------------------------------------------------------------------- 
        //                                                                             
        //  Name        :  nc_2DFLASH::run                                              
        //                                                                             
        //  Description :                                                              
        ///     \brief     Execution of the sequence                                   
        ///
        ///                This method executes the sequence.
        ///                On the scanner, it is performed only on the MARS (linux-64).
        ///		           It normally performs the looping over K space.
        ///
        //  Return      :  NLS status                                                  
        //                                                                             
        //  -------------------------------------------------------------------------- 
        virtual NLSStatus run(MrProt &rMrProt, SeqLim &rSeqLim, MrProtocolData::SeqExpo &rSeqExpo);


        //   -------------------------------------------------------------------------- 
        //                                                                              
        //   Name        :  nc_2DFLASH::runKernel                                            
        //                                                                              
        //   Description :  
        ///  \brief <b>     Executes the basic timing of the real-time sequence.   </b>     
        ///                                                                              
        ///                 This method is the fundamental repeat unit of the sequence. 
        ///                 It is called by the run method and typically acquires one or more lines in k-Space.
        ///                                                                              
        //   Return      :  NLS status                                                  
        //                                                                              
        //   -------------------------------------------------------------------------- 
        virtual NLS_STATUS runKernel(MrProt &rMrProt,SeqLim &rSeqLim, MrProtocolData::SeqExpo &rSeqExpo, long lKernelMode, long lSlice, long lPartition, long lLine);


        //  --------------------------------------------------------------
        //
        //  Name        :  getUI
        //
        //  Description :
        /// \brief <b>     Returns the pointer to the nc_2DFLASHUI class  </b>
        ///
        ///                This method is only sensible on the host.
        ///                On the measurement system, it will return an almost empty object.
        ///
        //  Return      :  nc_2DFLASHUI*
        //
        //  --------------------------------------------------------------
        const nc_2DFLASHUI* getUI (void) const;


    protected:
        // * ---------------------------------------------------------------------- *
        // * RF spoiling phase                                                      *
        // * ---------------------------------------------------------------------- *
        double m_dRFSpoilPhase;


        // * ---------------------------------------------------------------------- *
        // * Increment of the Rf spoiling phase                                     *
        // * ---------------------------------------------------------------------- *
        double m_dRFSpoilIncrement;


        // * ---------------------------------------------------------------------- *
        // * Index of the k-space center line                                       *
        // * ---------------------------------------------------------------------- *
        int32_t m_lCenterLine;


        // * ---------------------------------------------------------------------- *
        // * Minimum Gradient Rise Time                                             *
        // * ---------------------------------------------------------------------- *
        double m_dMinRiseTime;


        // * ---------------------------------------------------------------------- *
        // * Maximum Gradient Amplitude                                             *
        // * ---------------------------------------------------------------------- *
        double m_dGradMaxAmpl;


        // * ---------------------------------------------------------------------- *
        // * Number of phase encoding lines measured per second                     *
        // * ---------------------------------------------------------------------- *
        int32_t m_lLinesPerSec;


        // * ---------------------------------------------------------------------- *
        // * Number of phase encoding lines with iPAT                               *
        // * m_lLinesToMeasure and m_lLinesToMeasureMax are identical if iPAT is    *
        // * disabled.                                                              *
        // * ---------------------------------------------------------------------- *
        int32_t m_lLinesToMeasure;


        // * ---------------------------------------------------------------------- *
        // * Slice position information (rotation matrices and shifts)              *
        // * ---------------------------------------------------------------------- *
        sSLICE_POS       m_asSLC[1];        // nc_2DFLASH is a single-slice sequence but
        // some utility functions require the use of
        // an array as most sequences are multislice

        // * ---------------------------------------------------------------------- *
        // * RF Pulses and NCO                                                      *
        // * ---------------------------------------------------------------------- *
        sRF_PULSE_SINC   m_sSRF01;          // RF transmit waveform envelope
        sFREQ_PHASE      m_sSRF01zSet;      // Set Frequency and phase offset for RF pulse
        sFREQ_PHASE      m_sSRF01zNeg;      // Reset synthesizer back to base


        // * ---------------------------------------------------------------------- *
        // * Read Out and NCO                                                       *
        // * ---------------------------------------------------------------------- *
        sREADOUT         m_sADC01;		    // Signal detection event
        sFREQ_PHASE      m_sADC01zSet;      // Set Frequency and phase offset for ADC
        sFREQ_PHASE      m_sADC01zNeg;      // Reset synthesizer back to base


        // * ---------------------------------------------------------------------- *
        // * Gradient Pulses                                                        *
        // * ---------------------------------------------------------------------- *
        sGRAD_PULSE      m_sGSliSel;        // Gradient during RF transmit for slice selection 
        sGRAD_PULSE      m_sGSliSelReph;    // Gradient to refocus slice selection gradient (after TE = 0)
        sGRAD_PULSE_RO   m_sGradRO;         // Gradient during echo detection
        sGRAD_PULSE      m_sGReadDeph;      // Gradient to preset readout
        sGRAD_PULSE_PE   m_sGPhasEnc;       // Gradient for phase encoding 
        sGRAD_PULSE_PE   m_sGPhasEncRew;    // Gradient for rewinding
        sGRAD_PULSE      m_sGSpoil;         // Gradient for incoherent steady-state in slice direction

        // * ---------------------------------------------------------------------- *
        // * Sync Objects                                                           *
        // * ---------------------------------------------------------------------- *

        sSYNC_OSC        m_sOscBit;         // Synchronization event for oscilloscope trigger

        //  --------------------------------------------------------------
        /// \brief <b> UI class for nc_2DFLASH
        ///
        ///         This class is basically empty on the measurement system
        //  --------------------------------------------------------------
        nc_2DFLASHUI* m_pUI;


        //  ------------------------------------------------------------------
        //
        //  Name        :  nc_2DFLASH::createUI
        //
        //  Description :
        /// \brief <b>     Instantiation of UI classes   </b>
        //
        //  Return      :  NLS status
        //
        //  ------------------------------------------------------------------
        virtual NLS_STATUS createUI (SeqLim &rSeqLim);


        //  ------------------------------------------------------------------
        //
        //  Name        :  nc_2DFLASH::UnusedArg
        //
        //  Description :
        /// \brief         Used to avoid compiler warnings
        //
        //  Return      :  void
        //
        //  ------------------------------------------------------------------
        template< class TYPE > void UnusedArg (TYPE Argument) const { if( false ) { TYPE Dummy; Dummy = Argument; } };

    private:

        // * ------------------------------------------------------------------ *
        // * Copy constructor not implemented                                   *
        // * ------------------------------------------------------------------ *
        nc_2DFLASH (const nc_2DFLASH &right);



        // * ------------------------------------------------------------------ *
        // * Assignment operator not implemented                                *
        // * ------------------------------------------------------------------ *
        nc_2DFLASH & operator=(const nc_2DFLASH &right);
    };
};       // end of SEQ_NAMESPACE

#endif   // end of nc_2DFLASH_h