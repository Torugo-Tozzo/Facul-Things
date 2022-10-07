from inspect import _void
from pytube import YouTube

link = "https://youtu.be/g1Hb8FDs-hA"
yt = YouTube(link)
print(yt.title)

#videos = yt.streams.all()
videos = yt.streams.filter(only_audio=True)
vid = (enumerate(videos))
for i in vid:
    print(i)

strm = int(input("enter : "))
videos[strm].download()
print('Done!')
