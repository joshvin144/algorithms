
# Project Directories
PARENT_DIR:=..
CURRENT_DIR:=.

# Output Directories
OBJECT_DIR:=$(CURRENT_DIR)/obj
OUTPUT_DIR:=$(CURRENT_DIR)/bin

# Source Files
C_SOURCE+=$(CURRENT_DIR)/utilities/utilities.c
C_SOURCE+=$(CURRENT_DIR)/utilities/utilities_user.c
C_SOURCE+=$(CURRENT_DIR)/math_helpers/math_helpers.c

# Header Files
C_INCLUDE+=-iquote $(CURRENT_DIR)/utilities/utilities.h
C_INCLUDE+=-iquote $(CURRENT_DIR)/utilities/utilities_user.h
C_INCLUDE+=-iquote $(CURRENT_DIR)/adc/adc.h
C_INCLUDE+=-iquote $(CURRENT_DIR)/adc/adc_user.h
C_INCLUDE+=-iquote $(CURRENT_DIR)/math_helpers/math_helpers.h
C_INCLUDE+=-iquote $(CURRENT_DIR)/math_helpers/math_helpers_user.h

# Unit Tests
TEST_SOURCE+=$(CURRENT_DIR)/unit_testing/test_math_helpers.c
TEST_EXECUTABLE+=$(OUTPUT_DIR)/test_math_helpers.exe

# GCC arguments
CFLAGS+=-std=gnu99

test_for_echo:
	echo "\nVideo... vertigo... video vertigo... test for echo...\n"

clean:
	rm -rf $(OBJECT_DIR)
	rm -rf $(OUTPUT_DIR)

compile_and_link: $(C_SOURCE)
	gcc $(CFLAGS) $(C_INCLUDE) $(C_SOURCE) $(TEST_SOURCE) -o $(TEST_EXECUTABLE)

run_unit_tests:
	$(TEST_EXECUTABLE)
