import streamlit as st
import time, random
from firebase import firebase

firebase = firebase.FirebaseApplication("https://do-an-2-ute-default-rtdb.firebaseio.com/", None)
data = firebase.get('BED_ROOM/data', None).split('-')
path = ["BED_ROOM/nhiet_do", "BED_ROOM/do_am", "BED_ROOM/khi_ga", "BED_ROOM/cb_as", "BED_ROOM/ti_vi", "BED_ROOM/may_lanh", "BED_ROOM/den"]

for i in range(len(path)):
	firebase.put("/", path[i], int(data[i + 1]))

time.sleep(2)
st.experimental_rerun()
