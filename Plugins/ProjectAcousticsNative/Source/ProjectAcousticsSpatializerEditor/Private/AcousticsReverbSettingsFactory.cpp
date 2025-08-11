// Copyright (c) 2022 Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "AcousticsReverbSettingsFactory.h"
#include "AcousticsSpatializerSettings.h"
#include "AssetTypeCategories.h"
#include "UObject/Object.h"

#define LOCTEXT_NAMESPACE "ProjectAcoustics"

FText UAssetDefinition_AcousticsReverbSettings::GetAssetDisplayName() const
{
    return LOCTEXT("AssetDefinition_AcousticsReverbPluginPreset", "Project Acoustics Reverb Settings");
}

TSoftClassPtr<UObject> UAssetDefinition_AcousticsReverbSettings::GetAssetClass() const
{
    return UAcousticsSpatializerSettings::StaticClass();
}

FLinearColor UAssetDefinition_AcousticsReverbSettings::GetAssetColor() const
{
    return FLinearColor(FColor(100, 100, 100));
}

FText UAssetDefinition_AcousticsReverbSettings::GetAssetDescription(const FAssetData& AssetData) const
{
    return LOCTEXT("AssetDefinition_AcousticsReverbPluginPresetDesc", "Acoustics Spatializer Settings.");
}

TConstArrayView<FAssetCategoryPath> UAssetDefinition_AcousticsReverbSettings::GetAssetCategories() const
{
    static const auto Categories = { EAssetCategoryPaths::Audio / LOCTEXT("AssetSoundProjectAcousticsSubMenu", "Project Acoustics") };
    return Categories;
}

UAcousticsReverbSettingsFactory::UAcousticsReverbSettingsFactory()
{
    SupportedClass = UAcousticsSpatializerSettings::StaticClass();

    bCreateNew = true;
    bEditorImport = false;
    bEditAfterNew = true;
}

UObject* UAcousticsReverbSettingsFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
    return NewObject<UAcousticsSpatializerSettings>(InParent, InName, Flags);
}

uint32 UAcousticsReverbSettingsFactory::GetMenuCategories() const
{
    return EAssetTypeCategories::Sounds;
}

#undef LOCTEXT_NAMESPACE
