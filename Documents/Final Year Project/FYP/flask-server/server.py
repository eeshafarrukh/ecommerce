from flask import Flask, Response
import cv2
from gaze_tracking import GazeTracking

app = Flask(__name__)
gaze = GazeTracking()

# Function to generate video frames and add gaze tracking information
def generate_frames():
    video_capture = cv2.VideoCapture(0)
    while True:
        success, frame = video_capture.read()
        frame = cv2.flip(frame, 1)
        if not success:
            break

        # Send the frame to GazeTracking for analysis
        gaze.refresh(frame)

        frame = gaze.annotated_frame()
        text = ""
        text_color = (147, 58, 31)

        if gaze.is_blinking():
            text = "Blinking"
        elif gaze.is_right():
            text = "Maintain Eye Contact (Looking Left)"
            text_color = (0, 0, 255)  # Red
        elif gaze.is_left():
            text = "Maintain Eye Contact (Looking Right)"
            text_color = (0, 0, 255)  # Red
        elif gaze.is_center():
            text = "Looking center"

        cv2.putText(frame, text, (90, 60), cv2.FONT_HERSHEY_DUPLEX, 1.6, text_color, 2)

        left_pupil = gaze.pupil_left_coords()
        right_pupil = gaze.pupil_right_coords()
        cv2.putText(frame, "Left pupil: " + str(left_pupil), (90, 130), cv2.FONT_HERSHEY_DUPLEX, 0.9, (147, 58, 31), 1)
        cv2.putText(frame, "Right pupil: " + str(right_pupil), (90, 165), cv2.FONT_HERSHEY_DUPLEX, 0.9, (147, 58, 31), 1)

        # Encode the frame as JPEG
        ret, buffer = cv2.imencode('.jpg', frame)
        if not ret:
            continue

        # Yield the frame in the response
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + buffer.tobytes() + b'\r\n')

@app.route('/video')
def video():
    print("Request received")
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == "__main__":
    app.run(debug=True)
