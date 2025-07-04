#include "lvgl.h"
#include "LEDMatrix.h"

// définition des couleurs (mot clé en anglais)
#define BLACK 0x0000                          // noir
#define BLUE 0x001F                           // Bleu
#define RED 0xF800                            // Rouge
#define GREEN 0x07E0                          // Vert
#define CYAN 0x07FF                           // Cyan
#define MAGENTA 0xF81F                        // Magenta
#define YELLOW 0xFFE0                         // Jaune
#define WHITE 0xFFFF                          // Blanc
#define LV_COLOR_RED LV_COLOR_MAKE(255, 0, 0) // Définir la couleur rouge
int color = 0;
// Déclaration du canvas en tant que variable globale
lv_obj_t *canvas;

LEDMatrix ecran(D8, D2, D7, D3, D5, D12, D10, D11, D9, D0, D1, D4, D6);

uint8_t bufferEcran[64 * 32 * 2] = {0};

/*static void event_handler(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);

  if (code == LV_EVENT_CLICKED)
  {
    LV_LOG_USER("Clicked");
    color +=1;
  }
  else if (code == LV_EVENT_VALUE_CHANGED)
  {
    LV_LOG_USER("Toggled");
  }
}*/

void bouton1_event_cb(lv_event_t *e)
{

  color = 1; // rouge
}

void bouton2_event_cb(lv_event_t *e)
{

  color = 2; // vert
}
void bouton3_event_cb(lv_event_t *e)
{

  color = 3; // Jaune 
}
void bouton4_event_cb(lv_event_t *e)
{

  color = 0; // Noir
}
void bouton5_event_cb(lv_event_t *e)
{

  color = 4; // Bleu
}
void bouton6_event_cb(lv_event_t *e)
{

  color = 5; // Bleu
}
void bouton7_event_cb(lv_event_t *e)
{

  color = 6; // Bleu
}

void bouton8_event_cb(lv_event_t *e)
{

  color = 7; // Bleu
}

void bouton9_event_cb(lv_event_t *e)
{

  ecran.clear();
}

void testLvgl()
{
  // Initialisations générales
  lv_obj_t *label;

  lv_obj_t *btn1 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn1, 50, 50);
  lv_obj_align(btn1, LV_ALIGN_TOP_LEFT, 0, 0);
  lv_obj_remove_flag(btn1, LV_OBJ_FLAG_PRESS_LOCK);
  lv_obj_add_event_cb(btn1, bouton1_event_cb, LV_EVENT_CLICKED, NULL);

  label = lv_label_create(btn1);
  lv_label_set_text(label, "Rouge");
  lv_obj_center(label);

  lv_obj_t *btn2 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn2, 50, 50);
  lv_obj_align(btn2, LV_ALIGN_TOP_LEFT, 51, 0);
  lv_obj_remove_flag(btn2, LV_OBJ_FLAG_PRESS_LOCK);

  label = lv_label_create(btn2);
  lv_label_set_text(label, "Vert");
  lv_obj_center(label);

  lv_obj_add_event_cb(btn2, bouton2_event_cb, LV_EVENT_CLICKED, NULL);

  lv_obj_t *btn3 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn3, 50, 50);
  lv_obj_align(btn3, LV_ALIGN_TOP_LEFT, 102, 0);
  lv_obj_remove_flag(btn3, LV_OBJ_FLAG_PRESS_LOCK);

  label = lv_label_create(btn3);
  lv_label_set_text(label, "Jaune");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn3, bouton3_event_cb, LV_EVENT_CLICKED, NULL);


  lv_obj_t *btn4 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn4, 50, 50);
  lv_obj_align(btn4, LV_ALIGN_TOP_LEFT, 153, 0);
  lv_obj_remove_flag(btn4, LV_OBJ_FLAG_PRESS_LOCK);

  label = lv_label_create(btn4);
  lv_label_set_text(label, "Gomme");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn4, bouton4_event_cb, LV_EVENT_CLICKED, NULL);

   lv_obj_t *btn5 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn5, 50, 50);
  lv_obj_align(btn5, LV_ALIGN_TOP_LEFT, 204, 0);
  lv_obj_remove_flag(btn5, LV_OBJ_FLAG_PRESS_LOCK);

  label = lv_label_create(btn5);
  lv_label_set_text(label, "Bleu");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn5, bouton5_event_cb, LV_EVENT_CLICKED, NULL);


     lv_obj_t *btn6 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn6, 50, 50);
  lv_obj_align(btn6, LV_ALIGN_TOP_LEFT, 255, 0);
  lv_obj_remove_flag(btn6, LV_OBJ_FLAG_PRESS_LOCK);

  label = lv_label_create(btn6);
  lv_label_set_text(label, "Violet");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn6, bouton6_event_cb, LV_EVENT_CLICKED, NULL);


   lv_obj_t *btn7 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn7, 50, 50);
  lv_obj_align(btn7, LV_ALIGN_TOP_LEFT, 306, 0);
  lv_obj_remove_flag(btn7, LV_OBJ_FLAG_PRESS_LOCK);

  label = lv_label_create(btn7);
  lv_label_set_text(label, "Cyan");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn7, bouton7_event_cb, LV_EVENT_CLICKED, NULL);



   lv_obj_t *btn8 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn8, 50, 50);
  lv_obj_align(btn8, LV_ALIGN_TOP_LEFT, 357, 0);
  lv_obj_remove_flag(btn8, LV_OBJ_FLAG_PRESS_LOCK);

  label = lv_label_create(btn8);
  lv_label_set_text(label, "Blanc");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn8, bouton8_event_cb, LV_EVENT_CLICKED, NULL);


  lv_obj_t *btn9 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn9, 50, 50);
  lv_obj_align(btn9, LV_ALIGN_TOP_LEFT, 409, 0);
  lv_obj_remove_flag(btn9, LV_OBJ_FLAG_PRESS_LOCK);

  label = lv_label_create(btn9);
  lv_label_set_text(label, "Clear");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn9, bouton9_event_cb, LV_EVENT_CLICKED, NULL);
 
 
}

#ifdef ARDUINO

#include "lvglDrivers.h"

// à décommenter pour tester la démo
// #include "demos/lv_demos.h"

// uint8_t draw_buf[64*7*32*7*1];

void mySetup()
{
  //  LV_DRAW_BUF_DEFINE_STATIC(draw_buf, 64*4, 32*4, LV_COLOR_FORMAT_RGB565);
  //  LV_DRAW_BUF_INIT_STATIC(draw_buf);

  // à décommenter pour tester la démo
  // lv_demo_widgets();

  // Initialisations générales
  testLvgl();

  ecran.begin(bufferEcran, 64, 32);

  // Créer un canvas
  //  canvas = lv_canvas_create(lv_screen_active());

  //  lv_canvas_set_buffer(canvas, draw_buf, 64*7, 32*7, LV_COLOR_FORMAT_I4);

  //  lv_canvas_set_draw_buf(canvas, &draw_buf);
  //  lv_canvas_fill_bg(canvas, lv_color_black(), LV_OPA_COVER);
  //  lv_obj_center(canvas);

  // lv_layer_t layer;
  // lv_canvas_init_layer(canvas, &layer);

  //   lv_draw_rect_dsc_t dsc;
  //   lv_draw_rect_dsc_init(&dsc);
  //   dsc.bg_color = lv_palette_main(LV_PALETTE_RED);
  //   dsc.border_color = lv_palette_main(LV_PALETTE_BLUE);
  //   dsc.border_width = 3;
  //   dsc.outline_color = lv_palette_main(LV_PALETTE_GREEN);
  //   dsc.outline_width = 2;
  //   dsc.outline_pad = 2;
  //   dsc.outline_opa = LV_OPA_50;
  //   dsc.radius = 5;
  //   dsc.border_width = 3;

  //   lv_area_t coords = {10, 10, 40, 30};

  //   lv_draw_rect(&layer, &dsc, &coords);

  //   lv_canvas_finish_layer(canvas, &layer);

  /*for (int i = 0; i < 32; i++)
  {
    for (int j = 0; j < 16; j++)
    {
      ecran.drawPoint(i, j, 1);
    }
  }*/
}

void loop()
{
  // lv_task_handler(); // Traiter les tâches LVGL
  // delay(5);          // Petite pause pour éviter une surcharge
  //  Inactif (pour mise en veille du processeur)
}

void myTask(void *pvParameters)
{
  int n = 0;
  int i = 0, j = 0;

  lv_point_t point, oldPoint;

  // Init
  TickType_t xLastWakeTime;
  // Lecture du nombre de ticks quand la tâche débute
  xLastWakeTime = xTaskGetTickCount();
  while (1)
  {
    lv_indev_get_point(lv_indev_get_act(), &point); // Récupérer la position du point touché
    if(point.y > 51){
    if ((point.x != oldPoint.x) || (point.y != oldPoint.y))
    {
      point.y-=51;
      ecran.drawPointDirect(point.x / 7.5, point.y / 6.9, color);
      oldPoint = point;
    }}
    //  Afficher les coordonnées dans le moniteur série
    //  if (point.x >= 0 && point.y >= 0)
    //{
    /* Serial.print("Touch position: x = ");
     Serial.print(point.x);
     Serial.print(", y = ");
     Serial.println(point.y);
     // }

     // Dessiner un pixel à la position touchée
     lv_canvas_set_px(canvas, point.x, point.y, LV_COLOR_RED, 255); // Dessiner un pixel rouge*/

    // Loop
    ecran.scan();

    n++;
    if (n >= 50)
    {
      n = 0;
      // ecran.clear();
      // ecran.drawPoint(i, j, 1);
      // i++;
      // if (i >= 64)
      // {
      //   i = 0;
      //   j++;
      //   if (j >= 32)
      //     j = 0;
      // }
      // ecran.drawPoint(i, j, 1);
      // ecran.swap();
    }
    // Endort la tâche pendant le temps restant par rapport au réveil,
    // ici 200ms, donc la tâche s'effectue toutes les 200ms
    vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1)); // toutes les 1 ms
  }
}

#else

#include "lvgl.h"
#include "app_hal.h"
#include <cstdio>

int main(void)
{
  printf("LVGL Simulator\n");
  fflush(stdout);

  lv_init();
  hal_setup();

  testLvgl();

  hal_loop();
  return 0;
}

#endif
