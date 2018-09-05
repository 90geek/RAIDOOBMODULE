#****************************************************************************
#**                                                                        **
#**            (C)Copyright 1993-2016 Supermicro Computer, Inc.            **
#**                                                                        **
#****************************************************************************
#****************************************************************************
#  File History
#
#  Rev. 1.00
#       Bug fixed:   Initialize revision
#       Reason:      Clone from Sample folder.
#       Auditor:     Isaac Hsu
#       Date:        Nov/18/2016
#
#****************************************************************************

Prepare : $(BUILD_DIR)/HideSetupItemInc.h $(BUILD_DIR)/HideSetupItemElinks.h

#----------------------------------------------------------------------------
#           Create HideSetupItemInc header file
#----------------------------------------------------------------------------
OEM_HIDE_SETUPITEM_INCLUDE_FILES1 = $(subst \,/,$(subst +,$(space),$(OEM_HIDE_SETUPITEM_INCLUDE_FILES)))

$(BUILD_DIR)/HideSetupItemInc.h : $(OEM_HIDE_SETUPITEM_INCLUDE_FILES1)
	$(CAT) $(OEM_HIDE_SETUPITEM_INCLUDE_FILES1) > $(BUILD_DIR)/HideSetupItemInc.h

#----------------------------------------------------------------------------
#           Create HideSetupItemElinks header file
#----------------------------------------------------------------------------
$(BUILD_DIR)/HideSetupItemElinks.h :  $(BUILD_DIR)/token.mak
	$(ECHO) \
"// Don't delete this line$(EOL)\
#define OEM_HIDE_SETUPITEM_LIST $(OEM_HIDE_SETUPITEM_LIST)$(EOL)\
// Don't delete this line$(EOL)"\
> $(BUILD_DIR)/HideSetupItemElinks.h


