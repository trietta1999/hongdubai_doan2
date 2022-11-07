#pragma once

#include "ESP8266Firebase.h"

namespace firebase
{
Firebase firebase(PROJECT_ID);

void get()
{
  tivi = firebase.getInt(BEDROOM_TIVI);
  maylanh = firebase.getInt(BEDROOM_MAYLANH);
  den = firebase.getInt(BEDROOM_DEN);
}

void set(const String& path, const auto& value)
{
  firebase.setInt(path, value);
}

void setData(const String& path, const String& value)
{
  firebase.setString(path, value);
}
}
