// Copyright (c) 2022 Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "Factories/Factory.h"
#include "AssetDefinitionDefault.h"
#include "AcousticsReverbSettingsFactory.generated.h"

UCLASS()
class UAssetDefinition_AcousticsReverbSettings : public UAssetDefinitionDefault
{
    GENERATED_BODY()

public:
    //~UAssetDefinition interface
    FText GetAssetDisplayName() const override final;
    TSoftClassPtr<UObject> GetAssetClass() const override final;
    FLinearColor GetAssetColor() const override final;
    FText GetAssetDescription(const FAssetData& AssetData) const override final;
    TConstArrayView<FAssetCategoryPath> GetAssetCategories() const override final;
    //~End of UAssetDefinition interface
};

UCLASS(MinimalAPI, hidecategories = Object)
class UAcousticsReverbSettingsFactory : public UFactory
{
    GENERATED_BODY()

public:
    UAcousticsReverbSettingsFactory();

    virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
    virtual uint32 GetMenuCategories() const override;
};
