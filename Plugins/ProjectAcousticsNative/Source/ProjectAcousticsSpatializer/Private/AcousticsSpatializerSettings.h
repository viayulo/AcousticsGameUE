// Copyright (c) 2022 Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "UObject/Object.h"

#include "AcousticsSpatializerSettings.generated.h"

#define UE_API PROJECTACOUSTICSSPATIALIZER_API

UENUM(BlueprintType)
enum class EFlexEngineType : uint8
{
    HIGH_QUALITY    UMETA(DisplayName = "High Quality"),
    LOW_QUALITY     UMETA(DisplayName = "Good Quality"),
    STEREO_PANNING  UMETA(DisplayName = "Stereo Panning")
};

UCLASS(MinimalAPI, config = Engine, defaultconfig)
class UAcousticsSpatializerSettings : public UObject
{
    GENERATED_BODY()

public:
    UE_API UAcousticsSpatializerSettings();

    // setting for modifying the spatializer quality level
    UPROPERTY(GlobalConfig, EditAnywhere, Category = "General", meta = (DisplayName = "Engine Type"))
    EFlexEngineType FlexEngineType;
};

#undef UE_API
