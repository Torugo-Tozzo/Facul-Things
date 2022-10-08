#Partes comentadas = imagem pra colocar no arquivo.mp3


from pytube import YouTube
#import wget
#import eyed3
#from eyed3.id3.frames import ImageFrame

link = input("Link ou Url : ")
yt = YouTube(link)

print(yt.title + "\n\nBaixando...")

yd = yt.streams.get_audio_only()
yd.download(filename=yt.title + ".mp3")

#image_filename = wget.download(yt.thumbnail_url)
#file = yt.title + ".mp3"
#f = eyed3.load(file)
#f.initTag()
#f.tag.images.set(3, open("sddefault.jpg", 'rb').read(), 'image/jpeg')
#f.tag.save()

print("completo! "+ yt.title + ".mp3" +" baixado com sucesso!")
