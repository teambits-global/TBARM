/* MIT License

Copyright (c) 2017 catch22eu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

MEMORY
{
    flash (rx)  : org = 0x00000000, len = 32k
    ram   (xrw) : org = 0x10000000, len = 8k
}
  
SECTIONS
{
        
	. = ORIGIN(flash);
        .text : 
        {
        	FILL(0xff)
			KEEP (*(.isr_vector));
/* note: https://stackoverflow.com/questions/28647688/address-of-interrupt-handler-in-interrupt-vector-is-1-of-actual-address */
			KEEP (*(.after_vectors));
			*(.text);
        } >flash        
        _etext = .;
        
	. = ORIGIN(ram);
        .data : 
        {
	  		_data = .;
	    	*(.data);
	  		_edata = .;
        } >ram AT>flash

		.bss : 
		{
			__bss_start__ = .;
			_bss = .;
	    	*(.bss);
	    	__bss_end__ = .;
	    	_ebss = .;	  
		} > ram

	_vStackTop = 0x10000000 + 0x2000 -16;

}
