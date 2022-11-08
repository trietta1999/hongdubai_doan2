import streamlit as st
import time, random
from firebase import firebase

path = ["BED_ROOM/nhiet_do", "BED_ROOM/do_am", "BED_ROOM/khi_ga", "BED_ROOM/cb_as", "BED_ROOM/ti_vi", "BED_ROOM/may_lanh", "BED_ROOM/den"]
"https://do-an-2-ute-default-rtdb.firebaseio.com/"
firebase = firebase.FirebaseApplication("https://smart-steward-default-rtdb.firebaseio.com/", None)
data = firebase.get("BED_ROOM/data", None)
old_data = firebase.get("BED_ROOM/old_data", None)

if (data != old_data):
	firebase.put("/", "BED_ROOM/old_data", data)
	data = data.split('-')
	for i in range(len(path)): pass
# 		firebase.put("/", path[i], data[i + 1])
st.experimental_rerun()
