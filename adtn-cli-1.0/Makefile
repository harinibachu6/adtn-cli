LIB_BIN  = libont-cli.so
LIB_SRCS = $(wildcard resources/raptorPlugin/*.cpp) \
           $(wildcard resources/userExtensions/src/)

CXXFLAGS += -std=c++11 \
            -I./resources/raptorPlugin/ \
            -I./resources/userExtensions/inc/ \

CXXFLAGS  += -D__LITTLE_ENDIAN__ -fPIC -DPIC

LDFLAGS += -lrt -lpthread -lubus

OUTPUT_DIR = .output

#Makefile share part
LIB_OBJS  = $(addprefix $(OUTPUT_DIR)/,$(patsubst %.cpp,%.o,$(LIB_SRCS)))
LIB_DEPS  = $(addprefix $(OUTPUT_DIR)/,$(patsubst %.cpp,%.d,$(LIB_SRCS)))

all: $(LIB_BIN) $(LIB_DEPS) 

library_install:
	mkdir -p ${DEST}
	cp ${LIB_BIN} ${DEST}

headers_install:
	mkdir -p ${DEST}
	cp -rf resources/raptorPlugin/*.h ${DEST}
	cp -rf resources/userExtensions/inc/* ${DEST}

$(OUTPUT_DIR)/%.o:%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(LIB_BIN):$(LIB_OBJS)
	$(CXX) -shared  -fPIC -DPIC $^ $(LDFLAGS)  -O2   -Wl,-soname -Wl,$@ -o $@
 
clean: 
	$(RM) $(LIB_BIN)
	$(RM) -r $(OUTPUT_DIR)

