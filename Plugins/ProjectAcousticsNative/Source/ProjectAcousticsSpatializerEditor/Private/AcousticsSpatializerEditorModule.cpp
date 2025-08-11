// Copyright (c) 2022 Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "AcousticsSpatializerEditorModule.h"
#include "ISettingsModule.h"
#include "AcousticsSpatializerSettings.h"

#define LOCTEXT_NAMESPACE "FAcousticsSpatializerEditorModule"

void FAcousticsSpatializerEditorModule::StartupModule()
{
    // Register our custom plugin's settings.
    ISettingsModule* SettingsModule = FModuleManager::Get().GetModulePtr<ISettingsModule>("Settings");
    if (SettingsModule)
    {
        SettingsModule->RegisterSettings("Project", "Plugins", "Project Acoustics Spatializer", NSLOCTEXT("ProjectAcousticsSpatializer", "Project Acoustics Spatializer", "Project Acoustics Spatializer"),
            NSLOCTEXT("ProjectAcousticsSpatializer", "Configure Project Acoustics Spatializer plugin settings", "Configure Project Acoustics Spatializer plugin settings"), GetMutableDefault<UAcousticsSpatializerSettings>());
    }
}

void FAcousticsSpatializerEditorModule::ShutdownModule()
{
    // Unregister our custom plugin's settings.
    ISettingsModule* SettingsModule = FModuleManager::Get().GetModulePtr<ISettingsModule>("Settings");
    if (SettingsModule)
    {
        SettingsModule->UnregisterSettings("Project", "Plugins", "Project Acoustics Spatializer");
    }
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAcousticsSpatializerEditorModule, ProjectAcousticsSpatializerEditor)