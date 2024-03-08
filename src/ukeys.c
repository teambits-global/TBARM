#include "ukeys.h"


int UserKeyCGetState(void)
{
	int keystate = RELEASE;
	
	if(LOW == GPIO2GetPinState(8))
	{
		keystate = TOUCH;
	}	

	return keystate;	
}	

int UserKeyLGetState(void)
{
	int keystate = RELEASE;
	
	if(LOW == GPIO2GetPinState(7))
	{
		keystate = TOUCH;
	}	

	return keystate;	
}	

int UserKeyRGetState(void)
{
	int keystate = RELEASE;
	
	if(LOW == GPIO1GetPinState(4))
	{
		keystate = TOUCH;
	}	

	return keystate;	
}	

int UserKeyUGetState(void)
{
	int keystate = RELEASE;
	
	if(LOW == GPIO0GetPinState(3))
	{
		keystate = TOUCH;
	}	

	return keystate;	
}	

int UserKeyDGetState(void)
{
	int keystate = RELEASE;
	
	if(LOW == GPIO2GetPinState(6))
	{
		keystate = TOUCH;
	}	

	return keystate;	
}	


void UserKeyCGetClicks(int *count)
{
	int ukeycurr;
	static int ukeyprev = RELEASE;
	
	ukeycurr = UserKeyCGetState();
	if(RELEASE == ukeycurr)
	{
		if(TOUCH == ukeyprev)
		{
			*count+=1;
		}
	}
	ukeyprev = ukeycurr;
	
}	

void UserKeyLGetClicks(int *count)
{
	int ukeycurr;
	static int ukeyprev = RELEASE;
	
	ukeycurr = UserKeyLGetState();
	if(RELEASE == ukeycurr)
	{
		if(TOUCH == ukeyprev)
		{
			*count+=1;
		}
	}
	ukeyprev = ukeycurr;
	
}	

void UserKeyRGetClicks(int *count)
{
	int ukeycurr;
	static int ukeyprev = RELEASE;
	
	ukeycurr = UserKeyRGetState();
	if(RELEASE == ukeycurr)
	{
		if(TOUCH == ukeyprev)
		{
			*count+=1;
		}
	}
	ukeyprev = ukeycurr;
	
}	

void UserKeyUGetClicks(int *count)
{
	int ukeycurr;
	static int ukeyprev = RELEASE;
	
	ukeycurr = UserKeyUGetState();
	if(RELEASE == ukeycurr)
	{
		if(TOUCH == ukeyprev)
		{
			*count+=1;
		}
	}
	ukeyprev = ukeycurr;
	
}	

void UserKeyDGetClicks(int *count)
{
	int ukeycurr;
	static int ukeyprev = RELEASE;
	
	ukeycurr = UserKeyDGetState();
	if(RELEASE == ukeycurr)
	{
		if(TOUCH == ukeyprev)
		{
			*count+=1;
		}
	}
	ukeyprev = ukeycurr;
	
}	

