import handTrackingModule as HTM
import cv2
import socket

width, height = 1280, 720


def main():
    cap = cv2.VideoCapture(0)
    tracker = HTM.handTracker()

    #python-unity communication
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    serverAddressPort = ("127.0.0.1", 5052)

    while True:
        success,image = cap.read()
        image = tracker.handsFinder(image)
        lmList = tracker.positionFinder(image)
        data = []
        if len(lmList) != 0:
            print(lmList)
            for lm in lmList:
                data.extend([lm[0],height - lm[1], lm[2]])
            print(data)
            sock.sendto(str.encode(str(data)), serverAddressPort)

        cv2.imshow("Video",image)
        cv2.waitKey(1)

if __name__ == "__main__":
    main()
