
#include "ftsCrossCompile.h"
#include "ftsSoftware.h"



#define COMP_DATA_READ_RETRY			2


//Bytes dimension of Compensation Data Format

#define COMP_DATA_HEADER				8
#define COMP_DATA_GLOBAL				8


#define HEADER_SIGNATURE				0xA5


//Possible Compensation Data Type
#define GENERAL_TUNING					0x0100
#define MS_TOUCH_ACTIVE					0x0200
#define MS_TOUCH_LOW_POWER				0x0400
#define MS_TOUCH_ULTRA_LOW_POWER		0x0800
#define MS_KEY							0x1000
#define SS_TOUCH						0x2000
#define SS_KEY							0x4000
#define SS_HOVER						0x8000
#define SS_PROXIMITY					0x0001


#define TIMEOUT_REQU_COMP_DATA			1000			//ms


typedef struct {
	int force_node, sense_node;
} DataHeader;


typedef struct {
	DataHeader header;
	u8 tuning_ver;
	u8 cx1;
	u8 *node_data;
	int node_data_size;
} MutualSenseData;


typedef struct {
	DataHeader header;
	u8 tuning_ver;
	u8 f_ix1, s_ix1;
	u8 f_cx1, s_cx1;
	u8 f_max_n, s_max_n;

	u8 *ix2_fm;
	u8 *ix2_sn;
	u8 *cx2_fm;
	u8 *cx2_sn;

} SelfSenseData;


typedef struct {
	DataHeader header;
	u8 ftsd_lp_timer_cal0;
	u8 ftsd_lp_timer_cal1;
	u8 ftsd_lp_timer_cal2;

	u8 ftsd_lp_timer_cal3;
	u8 ftsa_lp_timer_cal0;
	u8 ftsa_lp_timer_cal1;

} GeneralData;


int requestCompensationData(u16 type);
int readCompensationDataHeader(u16 type, DataHeader *header, u16 *address);
int readMutualSenseGlobalData(u16 *address, MutualSenseData *global);
int readMutualSenseNodeData(u16 address, MutualSenseData *node);
int readMutualSenseCompensationData(u16 type, MutualSenseData *data);
int readSelfSenseGlobalData(u16 *address, SelfSenseData *global);
int readSelfSenseNodeData(u16 address, SelfSenseData *node);
int readSelfSenseCompensationData(u16 type, SelfSenseData *data);
int readGeneralGlobalData(u16 address, GeneralData *global);
int readGeneralCompensationData(u16 type, GeneralData *data);
int parseProductionTestLimits(char * path, char *label, int **data, int *row, int *column);
int readLine(char * data, char ** line, int size, int *n);
