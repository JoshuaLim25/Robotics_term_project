import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'robot_camera'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
		(os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma    ]*'))),
		# (os.path.join('share', package_name, 'urdf'), glob('urdf/*')),
		# (os.path.join('share', package_name, 'action'), glob('action/*')),
		(os.path.join('share', package_name, 'params'), glob('params/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='rock6',
    maintainer_email='chillythermometer@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
			'static_tag_broadcaster = robot_camera.static_tag_broadcaster:main',
			'pose_lookup_transform = robot_camera.pose_lookup_transform:main',
			'find_tag_action_server = robot_camera.find_tag_action_server:main',
        ],
    },
)
