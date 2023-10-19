#!/bin/bash

##############################################################################
# SET SOME CONFIG VARIABLES
##############################################################################
# Constants and Configurations
CONFIG_DIR = "/tmp"
CONFIG_FILES = ("command", "status", "output",
"error_output", "valgrind_output", "ltrace_output")
COMMANDS = ("which", "sleep", "ltrace", "echo", "cat",
"grep", "wc", "rm", "touch", "chmod", "pidof", "killall",
"kill", "valgrind", "sed", "diff", "head",
"tail", "cut", "ps", "cp", "env")

# Flags
VALGRIND_FLAGS = 0
LTRACE_FLAG = 0
DIFF_FLAG = 0

# Functions Definitions
function initialize(void)
{
# Initialization of variables and cleanup
for cmd in "${COMMANDS[@]}"; do
upper_cmd = $(echo "$cmd" | tr 'a-z' 'A-Z')
declare "$upper_cmd=$(which "$cmd")"
done
RANDOM_SUFFIX = "$RANDOM"
for file in "${CONFIG_FILES[@]}"; do
declare "${file^^}=$CONFIG_DIR/${file}_$RANDOM_SUFFIX"
done
}

function cleanup(void)
{
# Removing temporary files and stopping related processes
for file in "${CONFIG_FILES[@]}"; do
eval file_path = "${!file}"
rm - f "$file_path"
done
}

function create_script_file(void)
{
# Preparing the script file with the given commands
local file = "$1"
local commands = "$2"
echo - e "$commands" > "$file"
chmod + x "$file"
}

function execute_script(void)
{
# Executing the script and managing background processes
local script_file = "$1"
. "$script_file" &
sleep 2
pidof "$HSHELL" | xargs kill - 9 2 > / dev / null
}

function validate_args(void)
{
# Validating and parsing script arguments
while ["$#" - gt 0]; do
case "$1" in
(--valgrind_error) VALGRIND_FLAGS = 1;
shift;
(--valgrind_leak) VALGRIND_FLAGS = 2;
shift;
(--valgrind) VALGRIND_FLAGS = 3;
shift;
(--ltrace) LTRACE_FLAG = 1;
shift;
(--diff) DIFF_FLAG = 1;
shift;
(--help) show_usage;
exit 0;
(*) break;
esac done
(["$#" - lt 2]) && show_usage && exit 1
}

function show_usage(void)
{
# Displaying script usage instructions
cat << EOF
Usage : $0 shell test_file[options]

Options :
--valgrind_error            Check for valgrind errors
--valgrind_leak             Check for valgrind memory leaks
--valgrind                  Check for both valgrind errors and leaks
--ltrace                    Check for forbidden system / library calls
--diff                      Force to display output differences
--help                      Display this help and exit
EOF
}

# Main Script Execution
initialize
validate_args "$@"

HSHELL = "$1"
TEST_FILE = "$2"

cleanup

