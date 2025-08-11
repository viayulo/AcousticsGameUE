// Copyright (c) 2022 Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "AcousticsSourceDataOverrideSourceSettingsFactory.h"
#include "AcousticsSourceDataOverrideSourceSettings.h"
#include "AssetTypeCategories.h"
#include "UObject/Object.h"

#define LOCTEXT_NAMESPACE "ProjectAcoustics"

FText UAssetDefinition_AcousticsSourceDataOverrideSourceSettings::GetAssetDisplayName() const
{
    return LOCTEXT("AssetDefinition_AcousticsSourceDataOverrideSourceSettings", "Project Acoustics Source Data Override Source Settings");
}

TSoftClassPtr<UObject> UAssetDefinition_AcousticsSourceDataOverrideSourceSettings::GetAssetClass() const
{
    return UAcousticsSourceDataOverrideSourceSettings::StaticClass();
}

FLinearColor UAssetDefinition_AcousticsSourceDataOverrideSourceSettings::GetAssetColor() const
{
    return FLinearColor(FColor(100, 100, 100));
}

FText UAssetDefinition_AcousticsSourceDataOverrideSourceSettings::GetAssetDescription(const FAssetData& AssetData) const
{
    return LOCTEXT("AssetDefinition_AcousticsSourceDataOverrideSourceSettingsDesc", "Share per-source settings that can be saved to your Source Data Override Attenuation Settings.");
}

TConstArrayView<FAssetCategoryPath> UAssetDefinition_AcousticsSourceDataOverrideSourceSettings::GetAssetCategories() const
{
    static const auto Categories = { EAssetCategoryPaths::Audio / LOCTEXT("AssetSoundProjectAcousticsSubMenu", "Project Acoustics") };
    return Categories;
}

UAcousticsSourceDataOverrideSourceSettingsFactory::UAcousticsSourceDataOverrideSourceSettingsFactory()
{
    SupportedClass = UAcousticsSourceDataOverrideSourceSettings::StaticClass();

    bCreateNew = true;
    bEditorImport = true;
    bEditAfterNew = true;
}

UObject* UAcousticsSourceDataOverrideSourceSettingsFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context,
    FFeedbackContext* Warn)
{
    return NewObject<UAcousticsSourceDataOverrideSourceSettings>(InParent, Name, Flags);
}

uint32 UAcousticsSourceDataOverrideSourceSettingsFactory::GetMenuCategories() const
{
    return EAssetTypeCategories::Sounds;
}

#undef LOCTEXT_NAMESPACE
