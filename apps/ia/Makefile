apps += Ia::App
app_headers += apps/ia/app.h

apps_src += $(addprefix apps/ia/,\
  app.cpp \
  families.cpp \
  family_list_controller.cpp \
  options_controller.cpp \
  input_controller.cpp \
)

app_images += apps/ia/ia_icon.png

i18n_files += $(call i18n_without_universal_for,ia/base)

$(eval $(call depends_on_image,apps/ia/app.cpp,apps/ia/ia_icon.png))
