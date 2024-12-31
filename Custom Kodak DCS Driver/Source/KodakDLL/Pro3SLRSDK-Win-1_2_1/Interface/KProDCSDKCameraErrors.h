//------- PRO CAMERA errors ------------------------
// The following PSLR error codes come directly from the tethered camera
// These error numbers match the numbers used in the cameras.
#define PSLR_OK                                     ( 0x00000000 )
#define PSLR_BAD_COMMAND                            ( 0x00010000 )
#define PSLR_BAD_OFFSET                             ( 0x00020000 )
#define PSLR_BAD_LENGTH                             ( 0x00030000 )
#define PSLR_HANDLE_OPEN                            ( 0x00040000 )
#define PSLR_HANDLE_NOT_OPEN                        ( 0x00050000 )
#define PSLR_PATH_TOO_LONG                          ( 0x00060000 )
#define PSLR_FILE_DOES_NOT_EXIST                    ( 0x00070000 )
#define PSLR_FILE_ALREADY_EXISTS                    ( 0x00080000 )
#define PSLR_NOT_ON_CARD                            ( 0x00090000 )
#define PSLR_FOLDER_NOT_EMPTY                       ( 0x000A0000 )
#define PSLR_READ_ONLY                              ( 0x000B0000 )
#define PSLR_TOO_MANY_FILES                         ( 0x000C0000 )
// PSLR_OUT_OF_MEMORY gets returned if the application has issued
// a DCCaptureImage command but there is currently not enough 
// Image RAM available to store the image. If the camera is set
// to copy the images to PC Card, this error code means that the
// camera has not yet finished copying from RAM to PC card.
// Either waiting more time or calling DCPollSource until there
// is more memory available will allow another DCCaptureImage.
#define PSLR_OUT_OF_MEMORY                          ( 0x000D0000 )
#define PSLR_CREATE_ERROR                           ( 0x000E0000 )
#define PSLR_RENAME_ERROR                           ( 0x000F0000 )
#define PSLR_CARD_ERROR                             ( 0x00100000 )
#define PSLR_TRANSFER_ERROR                         ( 0x00110000 )

// SBP2 Error codes
//( can only use right-most 16 bits in this range ) 0xXXXXX300 ==> 0xXXXXX3FF
#define SBP2_EUI64_NOT_FOUND                        ( 0x00110301 )
#define SBP2_EUI64_FOUND_DIRTY                      ( 0x00110302 )
#define SBP2_LOGIN_REJECTED                         ( 0x00110303 )
#define SBP2_LUN_NOT_SUPPORTED                      ( 0x00110304 )
#define SBP2_RECONNECT_REJECTED                     ( 0x00110305 )
#define SBP2_LOGOUT_REJECTED                        ( 0x00110306 )

#define SBP2_POST_READ_SIZE_TOO_LARGE               ( 0x00110307 )
#define SBP2_POST_READ_WRONG_DIRECTION              ( 0x00110308 )
#define SBP2_POST_READ_BAD_MAX_PAYLOAD              ( 0x00110309 )

#define SBP2_POST_WRITE_SIZE_TOO_LARGE              ( 0x0011030A )
#define SBP2_POST_WRITE_WRONG_DIRECTION             ( 0x0011030B )
#define SBP2_POST_WRITE_BAD_MAX_PAYLOAD             ( 0x0011030C )

#define SBP2_NO_INITIATOR_LOGGED_IN                 ( 0x0011030D )
#define SBP2_UNSOL_STATUS_NOT_ENABLED               ( 0x0011030E )
#define SBP2_STATUS_LEN_TOO_SMALL                   ( 0x0011030F )
#define SBP2_NULL_XPORT								( 0x00110310 )
#define SBP2_CONFIG_ROM_OFFSET_ERROR				( 0x00110311 )
#define SBP2_RECONNECT_TIMEOUT_ERROR				( 0x00110312 )
#define SBP2_BUS_RESET								( 0x00110313 )
#define SBP2_UNSUPPORTED_REQUEST_TYPE				( 0x00110314 )
#define SBP2_UNSUPPORTED_SPEED						( 0x00110315 )
#define SBP2_UNSUPPORTED_PAGE_SIZE					( 0x00110316 )
#define SBP2_ACCESS_DENIED							( 0x00110317 )
#define SBP2_UNSUPPORTED_LOGICAL_UNIT				( 0x00110318 )
#define SBP2_PAYLOAD_TOO_SMALL						( 0x00110319 )
#define SBP2_UNAVAILABLE_RESOURCES					( 0x0011031a )
#define SBP2_REJECTED_FUNCTION						( 0x0011031b )
#define SBP2_UNRECOGNIZED_LOGIN_ID					( 0x0011031c )
#define SBP2_ABORTED_REQUEST						( 0x0011031d )
#define SBP2_UNSPECIFIED_ERROR						( 0x0011031e )
#define SBP2_TRANSPORT_ERROR						( 0x0011031f )
#define SBP2_ILLEGAL_REQUEST						( 0x00110320 )
#define SBP2_VENDOR_DEPENDENT_ERROR					( 0x00110321 )
#define SBP2_AGENT_STATE_RESET						( 0x00110322 )
#define SBP2_AGENT_STATE_BUSY						( 0x00110323 )
#define SBP2_AGENT_STATE_DEAD						( 0x00110324 )

// FIREWIRE Error codes
// ( can only use right-most 16 bits in this range ) 0xXXXXX400 ==> 0xXXXXX4FF
#define FIREWIRE_READ_NOT_ALLOWED                   ( 0x00110401 )
#define FIREWIRE_READ_TIMEOUT                       ( 0x00110402 )
#define FIREWIRE_READ_EV_RECEIVE_W_ERR              ( 0x00110403 )
#define FIREWIRE_READ_T_IDENT_ERR                   ( 0x00110404 )

#define FIREWIRE_WRITE_NOT_ALLOWED                  ( 0x00110411 )
#define FIREWIRE_WRITE_TIMEOUT                      ( 0x00110412 )
#define FIREWIRE_WRITE_EV_RECEIVE_W_ERR             ( 0x00110413 )
#define FIREWIRE_WRITE_T_IDENT_ERR                  ( 0x00110414 )


#define PSLR_CARD_FULL                              ( 0x00120000 )
#define PSLR_BAD_FILE                               ( 0x00130000 )
#define PSLR_UPDATE_FAILED                          ( 0x00140000 )
#define PSLR_FILE_NOT_OPEN                          ( 0x00150000 )
#define PSLR_BAD_HANDLE                             ( 0x00160000 )
#define PSLR_NOT_A_FOLDER                           ( 0x00170000 )
#define PSLR_ACCESS_VIOLATION                       ( 0x00180000 )
#define PSLR_BAD_DATA                               ( 0x00190000 )
#define PSLR_BAD_NAME                               ( 0x001A0000 )
#define PSLR_BATTERY_LOW                            ( 0x001B0000 )
#define PSLR_SYSTEM_ERROR                           ( 0x001C0000 )
#define PSLR_CAMERA_HOT                             ( 0x001D0000 )
#define PSLR_IMAGE_ERROR                            ( 0x001E0000 )
#define PSLR_FILE_IN_USE                            ( 0x001F0000 )

#define PSLR_BAD_FORMAT								( 0x00200000 )
#define PSLR_BAD_VERSION                			( 0x00210000 )
#define PSLR_NO_CARD                    			( 0x00220000 )
#define PSLR_NO_MORE_TASKS              			( 0x00230010 )
#define PSLR_TASK_DOES_NOT_EXIST        			( 0x00230011 )
#define PSLR_EVENT_TIMEOUT              			( 0x00230020 )
#define PSLR_NO_EVENTS                  			( 0x00230021 )
#define PSLR_NO_MORE_SEMAPHORES         			( 0x00230030 )
#define PSLR_SEMAPHORE_DOES_NOT_EXIST   			( 0x00230031 )   
#define PSLR_SEMAPHORE_TIMEOUT          			( 0x00230032 )  
#define PSLR_SEMAPHORE_FULL             			( 0x00230033 )
#define PSLR_SEMAPHORE_EMPTY            			( 0x00230034 )
#define PSLR_NO_MORE_QUEUES             			( 0x00230040 )
#define PSLR_QUEUE_DOES_NOT_EXIST       			( 0x00230041 )
#define PSLR_QUEUE_TIMEOUT              			( 0x00230042 )
#define PSLR_QUEUE_FULL                 			( 0x00230043 )
#define PSLR_QUEUE_EMPTY                			( 0x00230044 )
#define PSLR_DUPLICATE_PROPERTY         			( 0x00240000 )
#define PSLR_END_OF_FILE                			( 0x00250000 )
#define PSLR_ASYNC_COMMAND_BUSY         			( 0x00260000 )
#define PSLR_DISABLED                   			( 0x00270000 )
#define PSLR_NO_RECOVER_DATA            			( 0x00280000 )

#define PSLR_NO_DATA                    0x00290000
#define PSLR_DSP_START_ERROR            0x002A0000
#define PSLR_DSP_BUSY                   0x002B0000
#define PSLR_DSP_ERROR                  0x002C0000
#define PSLR_CAPTURE_DISABLED           0x002D0000

#define PSLR_OTHER_ERROR                      		( 0xFFFF0000 )


