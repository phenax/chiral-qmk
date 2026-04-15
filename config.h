
#define MASTER_LEFT
// #define SPLIT_HAND_PIN GP2

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

#ifndef DefaultLayerColorHSV
#define DefaultLayerColorHSV 0xaa, 0xff, 20
#endif

#define DEFINE_LAYER_LIGHTS(...)                                               \
  const uint8_t layer_colors[][3] = __VA_ARGS__;                               \
  void keyboard_post_init_user(void) { layer_state_set_user(layer_state); }    \
  layer_state_t layer_state_set_user(layer_state_t state) {                    \
    uint8_t layer = get_highest_layer(state);                                  \
    if (layer >= (sizeof(layer_colors) / sizeof(layer_colors[0]))) {           \
      rgblight_sethsv(DefaultLayerColorHSV);                                   \
    } else {                                                                   \
      const uint8_t *color = layer_colors[layer];                              \
      rgblight_sethsv(color[0], color[1], color[2]);                           \
    }                                                                          \
    return state;                                                              \
  }
