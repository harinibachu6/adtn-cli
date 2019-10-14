LIB_BIN  = libont-cli.so
LIB_SRCS = $(wildcard resources/raptorPlugin/*.c) \
           $(wildcard resources/userExtensions/src/*.c)

CFLAGS +=  -I./resources/raptorPlugin/ \
           -I./resources/userExtensions/inc/ \

CFLAGS += -W -Wall -Wextra

CFLAGS  += -D__LITTLE_ENDIAN__ -fPIC -DPIC

LDFLAGS += -lrt -lpthread -lubus -lubox

LIBS += -lubus -lubox

OUTPUT_DIR = .output

#Makefile share part
LIB_OBJS  = $(addprefix $(OUTPUT_DIR)/,$(patsubst %.c,%.o,$(LIB_SRCS)))

all: $(LIB_BIN)

library_install:
	mkdir -p ${DEST}
	cp ${LIB_BIN} ${DEST}

headers_install:
	mkdir -p ${DEST}
	cp -rf resources/raptorPlugin/*.h ${DEST}
	cp -rf resources/userExtensions/inc/* ${DEST}

$(OUTPUT_DIR)/%.o:%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB_BIN):$(LIB_OBJS)
	$(CC) -shared  -fPIC -DPIC $^ $(LDFLAGS)  -O2   -Wl,-soname -Wl,$@ -o $@
 
clean: 
	$(RM) $(LIB_BIN)
	$(RM) -r $(OUTPUT_DIR)

