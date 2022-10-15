import cmd
from pytube import YouTube
import os
import wget
import eyed3

link = input("Link ou Url : ")
yt = YouTube(link)
base_dir = input("Diretorio de download:")

print(yt.title + "\n\nBaixando...")

yd = yt.streams.get_audio_only()
yd.download(filename ='generico.mp4')
image_filename = wget.download(yt.thumbnail_url)

#base_dir = "C:/Users/Karat/Documents/PastaProgramas/.vscode/"

mp4_file = base_dir + 'generico.mp4'
mp3_file = base_dir + 'generico.mp3'

cmd = 'ffmpeg -i '+ mp4_file + ' -vn ' + mp3_file
os.system(cmd)

file = 'generico.mp3'

f = eyed3.load(file)
f.initTag()
f.tag.images.set(3, open("sddefault.jpg", 'rb').read(), 'image/jpeg')
f.tag.save()

oldname = base_dir + "generico.mp3"
newname = base_dir + yt.title+".mp3"
os.rename(oldname, newname)
os.remove(base_dir + "sddefault.jpg")
os.remove(base_dir + "generico.mp4")

print("completo! "+ mp3_file +" baixado com sucesso!")
