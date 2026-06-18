# Indie Plugin Template

Template for spinning up new audio plugins in the Indie suite (by Dr Fix Audio).

Built on the [Pamplejuce](https://github.com/sudara/pamplejuce) JUCE plugin template (C++23,
CMake, Catch2), with [indie_shared_dsp](https://github.com/FXDecroix/indie-shared-dsp) wired in
as a submodule.

## Creating a new plugin from this template

1. Use this repo as a template (or clone it) to start a new plugin repo.
2. Run `./rename.sh ProjectName "Product Name" com.company.product MnfC Plgc` to set the plugin
   identity in `CMakeLists.txt`.
3. Replace the placeholder DSP in `source/PluginProcessor.h`/`.cpp` with your plugin's logic.
4. Update this README and `CLAUDE.md` to describe the new plugin.

## Building

See [CLAUDE.md](CLAUDE.md) for build commands and project structure.

```bash
git submodule update --init --recursive
cmake -B Builds -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build Builds --config Debug
ctest --test-dir Builds --verbose --output-on-failure
```
