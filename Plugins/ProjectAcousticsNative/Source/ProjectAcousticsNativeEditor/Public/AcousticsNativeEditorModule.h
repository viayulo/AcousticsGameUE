// Copyright (c) 2022 Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "Modules/ModuleManager.h"

class FAcousticsNativeEditorModule : public IModuleInterface
{
public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
