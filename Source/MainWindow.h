/*
 * Copyright 2015 Przemysław Buczkowski <przemub@przemub.pl>
 * Copyright 2014 George White
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <Bitmap.h>
#include <Button.h>
#include <Deskbar.h>
#include <GridLayout.h>
#include <GridView.h>
#include <GroupView.h>
#include <MenuBar.h>
#include <Resources.h>
#include <String.h>
#include <StringView.h>
#include <View.h>
#include <Window.h>

#include "ForecastDayView.h"
#include "ForecastDeskbarView.h"
#include "ForecastView.h"
#include "PreferencesWindow.h"
#include "CitiesListSelectionWindow.h"

const BRect kDefaultMainWindowRect = BRect(150, 150, 500, 500);
const uint32 kCitySelectionMessage = 'SelC';
const uint32 kOpenPreferencesMessage = 'OPrf';
const uint32 kToggleDeskbarReplicantMessage = 'TDkB';

const uint32 kCitiesListMessage = 'lstC';
const uint32 kDataMessage = 'Data';
const uint32 kForecastDataMessage = 'FDta';
const uint32 kFailureMessage = 'Fail';
const uint32 kUpdateCityName = 'UpCN';
const uint32 kUpdateTTLMessage = 'TTLm';

class MainWindow : public BWindow
{
public:
					MainWindow(void);
	virtual void	MessageReceived(BMessage* msg);

	virtual bool	QuitRequested();
	virtual void	AboutRequested();
	virtual void	MenusBeginning();

private:
	status_t		_SaveSettings();
	BMenuBar*		_PrepareMenuBar(void);
	ForecastView*	fForecastView;

	bool			fShowForecast;

	BRect			fMainWindowRect;
	CitiesListSelectionWindow*	fSelectionWindow;
	PreferencesWindow* fPreferencesWindow;

	BMenuItem*		fShowForecastMenuItem;
	BMenuItem*		fReplicantMenuItem;
};

#endif // _MAINWINDOW_H_
