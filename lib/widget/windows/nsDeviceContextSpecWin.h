/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef nsDeviceContextSpecWin_h___
#define nsDeviceContextSpecWin_h___

#include "nsCOMPtr.h"
#include "nsIDeviceContextSpec.h"
#include "nsIPrinterEnumerator.h"
#include "nsIPrintSettings.h"
#include "nsISupportsPrimitives.h"
#include <windows.h>
#include "mozilla/Attributes.h"
#include "mozilla/RefPtr.h"

class nsIWidget;

class nsDeviceContextSpecWin : public nsIDeviceContextSpec {
 public:
  nsDeviceContextSpecWin();

  NS_DECL_ISUPPORTS

  already_AddRefed<PrintTarget> MakePrintTarget() final;
  NS_IMETHOD BeginDocument(const nsAString& aTitle,
                           const nsAString& aPrintToFileName,
                           int32_t aStartPage, int32_t aEndPage) override {
    return NS_OK;
  }
  NS_IMETHOD EndDocument() override { return NS_OK; }
  NS_IMETHOD BeginPage() override { return NS_OK; }
  NS_IMETHOD EndPage() override { return NS_OK; }

  NS_IMETHOD Init(nsIWidget* aWidget, nsIPrintSettings* aPS,
                  bool aIsPrintPreview) override;

  float GetDPI() final;

  float GetPrintingScale() final;
  gfxPoint GetPrintingTranslate() final;

  void GetDriverName(nsAString& aDriverName) const {
    aDriverName = mDriverName;
  }
  void GetDeviceName(nsAString& aDeviceName) const {
    aDeviceName = mDeviceName;
  }

  // The GetDevMode will return a pointer to a DevMode
  // whether it is from the Global memory handle or just the DevMode
  // To get the DevMode from the Global memory Handle it must lock it
  // So this call must be paired with a call to UnlockGlobalHandle
  void GetDevMode(LPDEVMODEW& aDevMode);

  // helper functions
  nsresult GetDataFromPrinter(const nsAString& aName,
                              nsIPrintSettings* aPS = nullptr);

 protected:
  void SetDeviceName(const nsAString& aDeviceName);
  void SetDriverName(const nsAString& aDriverName);
  void SetDevMode(LPDEVMODEW aDevMode);

  virtual ~nsDeviceContextSpecWin();

  nsString mDriverName;
  nsString mDeviceName;
  LPDEVMODEW mDevMode;

  nsCOMPtr<nsIPrintSettings> mPrintSettings;
  int16_t mOutputFormat = nsIPrintSettings::kOutputFormatNative;

#ifdef MOZ_ENABLE_SKIA_PDF

  // This variable is independant of nsIPrintSettings::kOutputFormatPDF.
  // It controls both whether normal printing is done via PDF using Skia and
  // whether print-to-PDF uses Skia.
  bool mPrintViaSkPDF;
#endif
};

//-------------------------------------------------------------------------
// Printer Enumerator
//-------------------------------------------------------------------------
class nsPrinterEnumeratorWin final : public nsIPrinterEnumerator {
  ~nsPrinterEnumeratorWin();

 public:
  nsPrinterEnumeratorWin();
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTERENUMERATOR
};

#endif
