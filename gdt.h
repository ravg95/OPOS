#ifndef __GDT_H
#define __GDT_H

#include <stdint.h>

class GlobalDescriptorTable {
public:
	class SegmentDescriptor {
	private:
		uint16_t limit_lo;
		uint16_t base_lo;
		uint8_t base_hi;
		uint8_t type;
		uint8_t flags_limit_hi;
		uint8_t base_vhi;
	public:
		SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type);
		uint32_t getBase();
		uint32_t getLimit();
		
	} __attribute__((packed)); //this is here to tell the compiler not to mix the order of fields

	SegmentDescriptor nullSegmentSelector;
	SegmentDescriptor unusedSegmentSelector;
	SegmentDescriptor codeSegmentSelector;
	SegmentDescriptor dataSegmentSelector;
	
	GlobalDescriptorTable();
	~GlobalDescriptorTable();
	
	uint16_t getCodeSegmentSelector();
	uint16_t getDataSegmentSelector();

};

#endif
