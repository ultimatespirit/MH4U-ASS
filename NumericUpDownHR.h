#pragma once
#include "Common.h"

namespace MH4GASS 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;

	public ref class NumericUpDownHR : public NumericUpDown
	{
	public:
		NumericUpDownHR() {}

		virtual void UpdateEditText() override
		{
			if( !StringTable::text )
				Text = Value.ToString();
			else if( (int)Value <= 8 )
				Text = FormatString1( HRNum, Value.ToString() );
			else if( (int)Value < 12 )
				Text = FormatString1( HRGNum, Decimal(Value-8).ToString() );
			else
				Text = StaticString( HRAll );
		}
	};

	public ref class NumericUpDownVE : public NumericUpDown
	{
	public:
		NumericUpDownVE() {}
	
		virtual void UpdateEditText() override
		{
			if( !StringTable::text )
				Text = Value.ToString();
			else
				Text = FormatString1( VEStar, Value.ToString() );
		}
	};
}