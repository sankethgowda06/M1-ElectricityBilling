
PROJECT_NAME = hospital


TEST_PROJ_NAME = test_$(PROJECT_NAME)




# All source code files
SRC = main.c\
src/hms.c\



TEST_SRC = src/hms.c\
test/test_hms.c\
unity/unity.c\



COV_SRC = test_hms.c


INC	= -Iinc\
-Iunity\
 
INCLUDE_LIBS = -lcunit


PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out


DOCUMENTATION_OUTPUT = documentation/html

ifdef OS
   RM = rm -rf
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), OS)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif


$(PROJECT_NAME):all


.PHONY: run clean test doc all

all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(call FixPath,$(BUILD)/$(PROJECT_NAME).$(EXEC)) -lm


dev: all
	$(call FixPath,$(BUILD)/$(PROJECT_NAME).$(EXEC)) dev 

run:$(PROJECT_NAME)
	$(call FixPath,$(BUILD)/$(PROJECT_NAME).$(EXEC))


doc:
	make -C ./documentation

test:$(TEST_SRC) $(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD)/$(TEST_PROJ_NAME).$(EXEC))

clean:
	$(RM) $(call FixPath,$(BUILD))
	$(RM) $(call FixPath,$(DOCUMENTATION_OUTPUT))
	$(RM) $(call FixPath,$(PROJECT_NAME),$(PROJECT_NAME).gcno)


coverage:
	cp test/$(COV_SRC) .
	gcc -fprofile-arcs -ftest-coverage $(TEST_SRC) $(INC) -o $(call FixPath,./$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,./$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) *.DAT
	$(RM) $(COV_SRC)


$(BUILD):
	mkdir build

dynamic: $(TEST_SRC) $(BUILD)
	gcc -fsanitize=address -fno-omit-frame-pointer $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD)/$(TEST_PROJ_NAME).$(EXEC))


cppcheck:
	cppcheck -i unity --enable=all .