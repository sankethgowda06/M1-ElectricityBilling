PROJECT_NAME = hospital Management System

TEST_PROJ_NAME = test_$(PROJECT_NAME)

BUILD = build
SRC = main.c\
src/hms.c\

TEST_SRC = src/hms.c\
test/test_hms.c\
unity/unity.c\

ifdef OS
   RM = rm -rf
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif


$(PROJECT_NAME):all

.PHONY: run clean test doc all

all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(call FixPath,$(BUILD)/$(PROJECT_NAME).$(EXEC)) -lm

	clean:
	$(RM) $(call FixPath,$(BUILD))
	$(RM) $(call FixPath,$(DOCUMENTATION_OUTPUT))
	$(RM) $(call FixPath,$(PROJECT_NAME),$(PROJECT_NAME).gcno)


dynamic: $(TEST_SRC) $(BUILD)
	gcc -fsanitize=address -fno-omit-frame-pointer $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD)/$(TEST_PROJ_NAME).$(EXEC))

# Static code analysis
cppcheck:
	cppcheck -i unity --enable=all .