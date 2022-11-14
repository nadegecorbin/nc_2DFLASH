//    -----------------------------------------------------------------------------
//      Copyright (C) Siemens AG 1998  All Rights Reserved.
//    -----------------------------------------------------------------------------
//
//     Project: NUMARIS/4
//        File: \n4_servers1\pkg\MrServers\MrImaging\seq\nc_2DFLASH\nc_2DFLASH_UI.cpp
//     Version: \main\6
//      Author: Clinical
//        Date: 2013-09-24 12:39:03 +02:00
//
//        Lang: C++
//
//     Descrip: Declarations for nc_2DFLASH.cpp
//
//     Classes:
//
//    -----------------------------------------------------------------------------

// --------------------------------------------------------------------------
// General Includes
// --------------------------------------------------------------------------
#include "MrServers/MrMeasSrv/SeqIF/Sequence/Sequence.h"
#ifdef WIN32
#include "MrServers/MrProtSrv/MrProtocol/UILink/MrStdNameTags.h"
#endif

//  --------------------------------------------------------------------------
//  Application includes
//  --------------------------------------------------------------------------
#include "MrServers/MrImaging/seq/nc_2DFLASH/nc_2DFLASH.h"
#include "MrServers/MrImaging/seq/nc_2DFLASH/nc_2DFLASH_UI.h"

#ifndef SEQ_NAMESPACE
#error SEQ_NAMESPACE not defined
#endif

using namespace SEQ_NAMESPACE;
#ifdef WIN32


//  ----------------------------------------------------------------------
//
//  Name        :  getSeq
//
//  Description :
/// \brief         Returns the pointer to the sequence nc_2DFLASH
//
//  Return      :  nc_2DFLASH*
//
//  ----------------------------------------------------------------------
nc_2DFLASH* getSeq (MrUILinkBase* const pThis)
{
    return ( static_cast<nc_2DFLASH*>(pThis->sequence().getSeq()) );
}


//  ----------------------------------------------------------------------
//
//  Name        :  getUI
//
//  Description :
/// \brief         Returns the pointer to the UI class of the nc_2DFLASH
///                 sequence
//
//  Return      :  nc_2DFLASHUI*
//
//  ----------------------------------------------------------------------
const nc_2DFLASHUI* getUI (MrUILinkBase* const pThis)
{
    return ( static_cast<nc_2DFLASH*>(pThis->sequence().getSeq())->getUI() );
}


// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
//
//                    Definition of set value handler
//
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------


//  --------------------------------------------------------------------------
//
//  Name        : fLSetContrast
//
//  Description :
/// \brief        Example of a set-value handler calling the original set-value
///                handler first
///
///               This handler is called, when the contrast UI element is modified.
///               In that case, it checks and modifies the following parameters:
///               - Bandwidth
///               - Whatever
///
///               The original handler is called, if rContrast.getOrigSetValueHandler() is set.
///
///               It returns the desired value.
///
//  Return      : long
//
//  --------------------------------------------------------------------------


//  --------------------------------------------------------------------------
//  --------------------------------------------------------------------------
//
//                         Definition of solve handler
//
//  --------------------------------------------------------------------------
//  --------------------------------------------------------------------------


//  --------------------------------------------------------------------------
//
//  Name        : fSSolveGradMode
//
//  Description :
/// \brief        Example of a solve handler calling the standard fUICSolveSelectionConflict
///
///               This handler is called, when the gradient mode UI element is modified, but
///               leads to an inconsistent protocol.
///               In that case, modifies the following parameters:
///               - TE
///               - TR
///
///               This is done by calling fUICSolveSelectionConflict
///
///               It returns the confirmation message.
///
//  Return      : long
//
//  --------------------------------------------------------------------------


///  \brief Constructor
///
nc_2DFLASHUI::nc_2DFLASHUI(){}


///  \brief Destructor
///
nc_2DFLASHUI::~nc_2DFLASHUI(){}




//  --------------------------------------------------------------------------
//
//  Name        : registerUI
//
//  Description :
/// \brief        This method registers all given set / get / Solve - handlers
///
///               It can be executed on the measuement system, too, but is empty there.
///
///
///               It returns an NLS status
///
//  Return      : long
//
//  --------------------------------------------------------------------------

NLS_STATUS nc_2DFLASHUI::registerUI (SeqLim & /*rSeqLim*/)
{

    static const char * const ptModule = {"nc_2DFLASHUI::registerUI"};

#ifdef WIN32

    // ----------------------------------------------------------------------------------
    // Registration of set handler methods
    //
    //                                           parameter tag     new handler function
    // ----------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------
    // Registration of solve handler methods
    //
    //                                        parameter tag         new handler function
    // ----------------------------------------------------------------------------------

#endif

    return ( SEQU__NORMAL );

};      // end of registerUI

#endif  // end of WIN32

