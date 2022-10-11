#ifndef _FORECASTDAYVIEW_H_
#define _FORECASTDAYVIEW_H_

#include "PreferencesWindow.h"
#include <Bitmap.h>
#include <String.h>
#include <View.h>


class ForecastDayView : public BView
{
public:
					ForecastDayView(BRect);
					~ForecastDayView(void);
					ForecastDayView(BMessage* archive);

	virtual void	FrameResized(float, float);
	virtual void	Draw(BRect);
	virtual void	AttachedToWindow();
virtual status_t	Archive(BMessage* into, bool deep = true) const;
static BArchivable*	Instantiate(BMessage* archive);
		status_t	SaveState(BMessage* into, bool deep = true) const;

			void	SetIcon(BBitmap* icon);
			void	SetDayLabel(BString& dayLabel);
			void	SetTemp(BString& temp);
			void	SetHighTemp(int32 high);
			void	SetLowTemp(int32 low);
			void	SetDisplayUnit(DisplayUnit unit);
			DisplayUnit		Unit();
			void	SetTextColor(rgb_color color);

private:
	DisplayUnit		fDisplayUnit;
	int32			fHigh;
	int32			fLow;
	BString			fDayLabel;
	BString			fTemp;
	BBitmap*		fIcon;
	rgb_color		fTextColor;
	float			fFontSize;
};

#endif // _FORECASTDAYVIEW_H_
