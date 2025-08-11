// Copyright (c) 2022 Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "AcousticsNativeEditorModule.h"
#include "ISettingsModule.h"
#include "AcousticsSourceDataOverrideSettings.h"

#define LOCTEXT_NAMESPACE "FAcousticsNativeEditorModule"

void FAcousticsNativeEditorModule::StartupModule()
{
    // Register our custom plugin's settings.
    ISettingsModule* SettingsModule = FModuleManager::Get().GetModulePtr<ISettingsModule>("Settings");
    if (SettingsModule)
    {
        SettingsModule->RegisterSettings("Project", "Plugins", "Project Acoustics SDO", NSLOCTEXT("ProjectAcousticsNative", "Project Acoustics SDO", "Project Acoustics SDO"),
            NSLOCTEXT("ProjectAcoustics", "Configure Project Acoustics Source Data Override plugin settings", "Configure Project Acoustics Source Data Override plugin settings"), GetMutableDefault<UAcousticsSourceDataOverrideSettings>());
    }
}

void FAcousticsNativeEditorModule::ShutdownModule()
{
    // Unregister our custom plugin's settings.
    ISettingsModule* SettingsModule = FModuleManager::Get().GetModulePtr<ISettingsModule>("Settings");
    if (SettingsModule)
    {
        SettingsModule->UnregisterSettings("Project", "Plugins", "Project Acoustics SDO");
    }
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAcousticsNativeEditorModule, ProjectAcousticsNativeEditor)