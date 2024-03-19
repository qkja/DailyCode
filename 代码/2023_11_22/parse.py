import argparse

# parser = argparse.ArgumentParser(description='Process some integers.')
# parser.add_argument('integers', metavar='N', type=int, nargs='+',
#                     help='an integer for the accumulator')
# parser.add_argument('--sum', dest='accumulate', action='store_const',
#                     const=sum, default=max,
#                     help='sum the integers (default: find the max)')
#
# args = parser.parse_args(['--sum', '7', '-1', '42'])
# print(args.accumulate(args.integers))
# parser.add_argument('--weights', nargs='+', type=str, default=ROOT / 'yolov5s.pt', help='model path or triton URL')
# ROOT = "rrrr"
# default=ROOT / 'yolov5s.pt'
# print(default)
# def print_args(args: Optional[dict] = None, show_file=True, show_func=False):
#     # Print function arguments (optional args dict)
#     x = inspect.currentframe().f_back  # previous frame
#     file, _, func, _, _ = inspect.getframeinfo(x)
#     if args is None:  # get args automatically
#         args, _, _, frm = inspect.getargvalues(x)
#         args = {k: v for k, v in frm.items() if k in args}
#     try:
#         file = Path(file).resolve().relative_to(ROOT).with_suffix('')
#     except ValueError:
#         file = Path(file).stem
#     s = (f'{file}: ' if show_file else '') + (f'{func}: ' if show_func else '')
#     LOGGER.info(colorstr(s) + ', '.join(f'{k}={v}' for k, v in args.items()))

# def parse_opt():
#     parser = argparse.ArgumentParser()
#     parser = argparse.ArgumentParser()
#     # parser.add_argument('--weights', nargs='+', type=str, default= 'yolov5s.pt', help='model path or triton URL')
#     # parser.add_argument('--source', type=str, default='data/images', help='file/dir/URL/glob/screen/0(webcam)')
#     # parser.add_argument('--data', type=str, default='data/coco128.yaml', help='(optional) dataset.yaml path')
#     parser.add_argument('--imgsz', '--img', '--img-size', nargs='+', type=int, default=[640], help='inference size h,w')
#     parser.add_argument('--conf-thres', type=float, default=0.25, help='confidence threshold')
#     # parser.add_argument('--iou-thres', type=float, default=0.45, help='NMS IoU threshold')
#     # parser.add_argument('--max-det', type=int, default=1000, help='maximum detections per image')
#     # parser.add_argument('--device', default='', help='cuda device, i.e. 0 or 0,1,2,3 or cpu')
#     # parser.add_argument('--view-img', action='store_true', help='show results')
#     # parser.add_argument('--save-txt', action='store_true', help='save results to *.txt')
#     # parser.add_argument('--save-csv', action='store_true', help='save results in CSV format')
#     # parser.add_argument('--save-conf', action='store_true', help='save confidences in --save-txt labels')
#     # parser.add_argument('--save-crop', action='store_true', help='save cropped prediction boxes')
#     # parser.add_argument('--nosave', action='store_true', help='do not save images/videos')
#     # parser.add_argument('--classes', nargs='+', type=int, help='filter by class: --classes 0, or --classes 0 2 3')
#     # parser.add_argument('--agnostic-nms', action='store_true', help='class-agnostic NMS')
#     # parser.add_argument('--augment', action='store_true', help='augmented inference')
#     # parser.add_argument('--visualize', action='store_true', help='visualize features')
#     # parser.add_argument('--update', action='store_true', help='update all models')
#     # parser.add_argument('--project', default= 'runs/detect', help='save results to project/name')
#     # parser.add_argument('--name', default='exp', help='save results to project/name')
#     # parser.add_argument('--exist-ok', action='store_true', help='existing project/name ok, do not increment')
#     # parser.add_argument('--line-thickness', default=3, type=int, help='bounding box thickness (pixels)')
#     parser.add_argument('--hide-labels', default=False, action='store_true', help='hide labels')
#     # parser.add_argument('--hide-conf', default=False, action='store_true', help='hide confidences')
#     # parser.add_argument('--half', action='store_true', help='use FP16 half-precision inference')
#     # parser.add_argument('--dnn', action='store_true', help='use OpenCV DNN for ONNX inference')
#     # parser.add_argument('--vid-stride', type=int, default=1, help='video frame-rate stride')
#
#     opt = parser.parse_args()
#     print(vars(opt))
#     # print(type(opt))
#
# parse_opt()

from pathlib import Path
# a = "at"
# FILE = Path(__file__)
# FILE = Path(__file__).resolve()
# FILE = Path(__file__).resolve()
# ROOT = FILE.parents[0]  # YOLOv5 root directory
# print(FILE)
# print(__file__)
# print(ROOT)
# print(type(ROOT))

# print(ROOT/"ddddd.yxt")

# ROOT = FILE.parents[0]  # YOLOv5 root directory
import subprocess
from pathlib import Path

# def check_requirements(requirements_file="requirements.txt"):
#     # Get the full path to the requirements file
#     requirements_path = Path(__file__).parent / requirements_file
#
#     # Use pip to check if the requirements are installed
#     try:
#         subprocess.run(["pip", "check", "-r", str(requirements_path)], check=True)
#         print("All requirements are satisfied.")
#     except subprocess.CalledProcessError:
#         print("Some requirements are missing or not compatible.")
#
# # Example usage:
# check_requirements()
# nosave = False
# save_img = not nosave and not True
# print(save_img)
# a = [1,2,3]
# print(a[1:])
# a = 1 if False  else 2
# print(a)
a = (1, 0)
# for i in range(1, 3):
#     with a[0]:
#         print('a')
#     with a[1]:
#         print('b')

print(a[0])