default: tests.log

include ../../src/config.inc
include ../../src/common

ifeq ($(BUILD_ENV_),MSVC)
test:
	@../test.pl -e -p -c ../../../src/goto-cc/goto-cl -X goto-link
	@cp ../../src/goto-cc/goto-cl.exe ../../src/goto-cc/goto-link.exe
	@chmod a+x ../../src/goto-cc/goto-link.exe
	@../test.pl -e -p -c ../../../src/goto-cc/goto-link -I goto-link

tests.log: ../test.pl
	@../test.pl -e -p -c ../../../src/goto-cc/goto-cl -X goto-link
	@cp ../../src/goto-cc/goto-cl.exe ../../src/goto-cc/goto-link.exe
	@chmod a+x ../../src/goto-cc/goto-link.exe
	@../test.pl -e -p -c ../../../src/goto-cc/goto-link -I goto-link

else
test:

tests.log: ../test.pl

endif

clean:
	find . -name '*.out' -execdir $(RM) '{}' \;
	find . -name '*.gb' -execdir $(RM) '{}' \;
	find . -name '*.obj' -execdir $(RM) '{}' \;
	find . -name '*.exe' -execdir $(RM) '{}' \;
	find . -name '*.goto-cc-saved' -execdir $(RM) '{}' \;
	$(RM) tests.log
