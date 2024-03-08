DEVICE      = cortex-m0
# PORT depends on OS:
# For Linux:
PORT        = /dev/ttyUSB0
BAUD        = 57600
ISPCLK      = 12000
FILENAME    = teambits
GCC         = arm-none-eabi-gcc
LD			= arm-none-eabi-ld
OBJCP		= arm-none-eabi-objcopy
OPT			= -Wall -Os -O0 -std=gnu99 -specs=nosys.specs -DUSE_OLD_STYLE_DATA_BSS_INIT -mcpu=$(DEVICE) -mthumb -Wl,-Map,$(FILENAME).map
LPCLIBS		= ../TBARM/src/
BINS		= ../TBARM/obj

INC			= $(LPCLIBS)
DEF			= -DCORE_M0 -DENABLE_UNTESTED_CODE
# This is already defined in sys_config:
#-DCHIP_LPC11CXX 

SRC  		 = $(LPCLIBS)main.c
SRC			+= $(LPCLIBS)cr_startup_lpc11xx.c
# Add other source files

#copy all $(SRC) files into $(OBJS) and rename them to .o 
OBJS  		= $(SRC:.c=.o)

# Define linker script file here
LINKER_SCRIPT = LPC11C24.ld

all: clean $(OBJS) $(FILENAME).elf $(FILENAME).bin move

%.o: %.c
	$(GCC) -c $(OPT) -I$(INC) $(DEF) $< -o $@
	
%.elf: $(OBJS)
	$(GCC) $(OPT) $(LIBS) -T$(LINKER_SCRIPT) $(OBJS) -o $@

%bin: %elf
	$(OBJCP) -O binary -S $< $@

move:
	mv $(LPCLIBS)*.o $(BINS)

flash:
	lpc21isp -control -bin $(FILENAME).bin $(PORT) $(BAUD) $(ISPCLK)

clean:
	rm -f $(BINS)/*.o

