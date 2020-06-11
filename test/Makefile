OUTPUT_FILE = output.txt

all:
	$(info For Windows use: $(MAKE) windows)
	$(info For Linux use: $(MAKE) linux)
	$(error Missing argument: windows or linux)

LINUX_CRC32_SUM = ../src/crc32sum
linux:
	$(MAKE) linux -C ../src
	$(LINUX_CRC32_SUM) if=data1.txt > $(OUTPUT_FILE)
	$(LINUX_CRC32_SUM) if=data2.txt >> $(OUTPUT_FILE)
	$(LINUX_CRC32_SUM) if=data3.txt >> $(OUTPUT_FILE)
	$(LINUX_CRC32_SUM) if=data4.txt >> $(OUTPUT_FILE)

WINDOWS_CRC32_SUM = ../src/crc32sum.exe
windows:
	$(MAKE) windows -C ../src
	$(WINDOWS_CRC32_SUM) if=data1.txt > $(OUTPUT_FILE)
	$(WINDOWS_CRC32_SUM) if=data2.txt >> $(OUTPUT_FILE)
	$(WINDOWS_CRC32_SUM) if=data3.txt >> $(OUTPUT_FILE)
	$(WINDOWS_CRC32_SUM) if=data4.txt >> $(OUTPUT_FILE)
