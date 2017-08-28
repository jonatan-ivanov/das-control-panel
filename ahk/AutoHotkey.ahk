#z::
soundget, isMute, MICROPHONE, MUTE
if isMute = Off
    toMute = 1
else
    toMute=0
SoundSet, toMute, MICROPHONE, MUTE
return

Alt & F6::
	If GetKeyState("Ctrl")
		SoundSet, 1, Microphone, mute
Return

Alt & F7::
	If GetKeyState("Ctrl")
		Send {Volume_Mute}
Return

Alt & F8::
	If GetKeyState("Ctrl")
		Send {Media_Prev}
Return

Alt & F9::
	If GetKeyState("Ctrl")
		Send {Media_Play_Pause}
Return

Alt & F10::
	If GetKeyState("Ctrl")
		Send {Media_Next}
Return

Alt & F11::
	If GetKeyState("Ctrl")
		Send {Volume_Down 2}
Return

Alt & F12::
	If GetKeyState("Ctrl")
		Send {Volume_Up 2}
Return
