# Project Acoustics Sample for Unreal Engine

> [!IMPORTANT]
>
> This project requires `Git LFS` for it to work properly, `ZIP` downloads **might not work**.

Sample project for evaluating Project Acoustics plugins in Unreal Engine 5.

For additional information, please refer to [ProjectAcoustics](https://github.com/viayulo/ProjectAcoustics).

## Installation

- Download plugin from [GitHub Releases](https://github.com/viayulo/AcousticsGameUE/releases).
- Extract and move the plugin folder under your project's `Plugins` folder (install to project), or engine's `Engine/Plugins/Marketplace` folder (install to engine).

## Known Issues

### The **Spatial Reverb** does not work in non-editor builds.

- Affects Versions: 5.6 and above
- How to fix (with **source build** engine):

In `Engine/Source/Runtime/AudioMixer/Private/AudioMixerSource.cpp`, remove the `#if WITH_EDITOR` (and corresponding `#endif // WITH_EDITOR`) preprocessor directives in following lines:

```cpp
#if WITH_EDITOR
	// The following can spam to the command queue. But is mostly here so that the editor live edits are immedately heard
	// For anything less than editor this is perf waste, so predicate this only to be run in editor.
	MixerSourceVoice->SetSourceBufferListener(WaveInstance->SourceBufferListener, WaveInstance->bShouldSourceBufferListenerZeroBuffer);
#endif // WITH_EDITOR
```
---

### When using **Spatial Reverb**, the Initialize method is called twice in non-editor builds, causing double virtual speakers to spawn.

- Affects Versions: 5.6 and before
- How to fix (with **source build** engine):

In `Engine/Source/Runtime/Engine/Private/AudioDevice.cpp`, within the `FAudioDevice::SetListener()` function, replace `Listeners` with `ListenerProxies`:

```cpp
// World change event triggered on change in world of existing listener.
if (InViewportIndex < ListenerProxies.Num())
{
    if (ListenerProxies[InViewportIndex].WorldID != WorldID)
    {
```
---
