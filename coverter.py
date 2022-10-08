from pytube import YouTube

link = input("Link ou Url : ")
yt = YouTube(link)

print(yt.title + "\n\nBaixando...")

yd = yt.streams.get_highest_resolution()
yd.download(filename=yt.title + '.mp3',)

print("Sucesso!")
