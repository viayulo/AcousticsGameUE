# Project Acoustics Sample for Unreal Engine

> [!IMPORTANT]
>
> This project requires `Git LFS` to function properly. Downloading as a ZIP archive may result in missing or broken assets.
>
> If downloading fails due to GitHub's monthly LFS limits, please download the sample project from **Releases** or wait until next month.

Sample project for evaluating Project Acoustics plugins in Unreal Engine 5.

For additional **documentation** and **bake tools**, please refer to [ProjectAcoustics](https://github.com/viayulo/ProjectAcoustics).

## Plugin Installation

1. Download **plugin** from [GitHub Releases](https://github.com/viayulo/AcousticsGameUE/releases).
2. Extract the archive and place the plugin folder into one of the following locations:
    - Project level: `<YourProject>/Plugins/`
    - Engine level: `<EngineRoot>/Engine/Plugins/Marketplace/`

> [!NOTE]
>
> The latest release is not guaranteed to be compatible with older engine versions.
> 
> If you are using an earlier engine version, you may need to modify the source code to resolve compatibility issues, or consider using a previous release that matches your engine version.

## Known Issues & Fixes

<details>

<summary>The <code>Spatial Reverb</code> does not work in non-editor builds.</summary>

>**Affected Engine Versions:** 5.6 or later
>
>**Resolution (Requires Engine Source Build):**
>
>In `Engine/Source/Runtime/AudioMixer/Private/AudioMixerSource.cpp`, remove the `#if WITH_EDITOR` (and corresponding `#endif // WITH_EDITOR`) lines shown below:
>
>```cpp
>#if WITH_EDITOR // <--- REMOVE
>	// The following can spam to the command queue. But is mostly here so that the editor live edits are immedately heard
>	// For anything less than editor this is perf waste, so predicate this only to be run in editor.
>	MixerSourceVoice->SetSourceBufferListener(WaveInstance->SourceBufferListener, WaveInstance->bShouldSourceBufferListenerZeroBuffer);
>#endif // WITH_EDITOR // <--- REMOVE
>```

</details>

<details>

<summary>When using <code>Spatial Reverb</code>, the Initialize method is called twice in non-editor builds, causing double virtual speakers to spawn.</summary>

>**Affected Engine Versions:** 5.7 and earlier (Fixed in 5.8)
>
>**Resolution (Requires Engine Source Build):**
>
>In `Engine/Source/Runtime/Engine/Private/AudioDevice.cpp`, within the `FAudioDevice::SetListener()` function, replace `Listeners` with `ListenerProxies`:
>
>```cpp
>// World change event triggered on change in world of existing listener.
>if (InViewportIndex < ListenerProxies.Num())
>{
>    if (ListenerProxies[InViewportIndex].WorldID != WorldID)
>    {
>```

</details>
