# Qt Slider and Spin Box

This project recreates the signals-and-slots example from the assignment video with the required changes:

- The widget setup and connections are implemented inside the `MainWindow` class.
- Explicit types such as `QSlider *`, `QSpinBox *`, `QWidget *`, and `QVBoxLayout *` are used instead of `auto`.
- The connection works in both directions: changing the slider updates the spin box, and changing the spin box updates the slider.

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run tests

```bash
ctest --test-dir build --output-on-failure
```
