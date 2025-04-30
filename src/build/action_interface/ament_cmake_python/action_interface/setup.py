from setuptools import find_packages
from setuptools import setup

setup(
    name='action_interface',
    version='0.0.0',
    packages=find_packages(
        include=('action_interface', 'action_interface.*')),
)
